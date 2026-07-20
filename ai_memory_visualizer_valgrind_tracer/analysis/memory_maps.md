# Memory Maps: Stack, Heap, Pointer Aliasing, and Object Lifetimes

**Programs analyzed:** `stack_example.c`, `aliasing_example.c`, `crash_example.c`, `heap_example.c`
**Compiler / flags (from the provided `Makefile`):**
`gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g`
**Execution mode:** normal (no Valgrind), per assignment instructions.

### ⚠️ Build result using the provided Makefile — important finding

Running `make all` with the Makefile **as provided** does **not** produce all four
binaries:

```
$ make all
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o stack_example stack_example.c   -> OK
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o heap_example heap_example.c     -> OK
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o aliasing_example aliasing_example.c
aliasing_example.c:45:34: error: pointer 'b' used after 'free' [-Werror=use-after-free]
...
cc1: all warnings being treated as errors
make: *** [Makefile:18: aliasing_example] Error 1
```

**Why:** the Makefile compiles with `-Werror`, and `aliasing_example.c` deliberately reads
and writes through a pointer (`b`) after the memory it points to has been `free()`d — this
is the whole point of that file. GCC detects this specific pattern at compile time
(`-Wuse-after-free`) and, because of `-Werror`, that warning is promoted to a hard error.
`aliasing_example` therefore **fails to build**, and because `make`'s default behavior is
to stop at the first failed prerequisite of `all`, **`crash_example` is never built either**
in the same invocation, even though `crash_example.c` itself is not the problem.

This is a genuine conflict between the Makefile and the assignment's own files, not a
mistake in the analysis — it's worth confirming with whoever supplied the Makefile whether
`aliasing_example.c` is meant to be excluded from `-Werror`, built with a relaxed rule, or
whether the Makefile is expected to be adjusted for that one target. It is **not** something
this analysis can silently paper over, since "the AI-generated explanation was correct" is
part of what the assignment wants checked.

**What was done for the rest of this analysis:** `stack_example` and `heap_example` were
built and run directly via `make` with no changes. `crash_example` was built by invoking
gcc with the exact same flags from the Makefile directly (it compiles cleanly on its own —
the only reason `make` didn't reach it was the earlier failure). `aliasing_example` was
built with the same flags **minus `-Werror`** (`-Wall -Wextra -pedantic -std=gnu89 -g`) so
that its real runtime behavior — which is what Section 2 needs — could still be captured
and analyzed; the compiler still emits the same `-Wuse-after-free` warning, just as a
warning instead of a hard stop.

Method: each program was compiled and run normally, real pointer addresses were captured
from the actual output, and an AI (this assistant) first drafted an explanation of what
was happening. That draft was then checked against the real program output and the C
semantics involved. One place where the first AI draft was wrong is documented explicitly
in Section 2, as required by the assignment, with the correction and reasoning.

---

## 1. `stack_example.c` — Stack Frames and Recursion

### What the program does
`main` calls `walk_stack(0, 3)`, which recurses down to depth 3, then unwinds back to depth
0. At each depth, `walk_stack` calls `dump_frame`, a second, separate stack frame, which
prints its own locals.

### Real addresses from an actual run

```
[enter] depth=0  &local_int=0x7ffc67f85fd4  local_buf=0x7ffc67f85fe0  &marker=0x7ffc67f86024
[enter] depth=1  &local_int=0x7ffc67f85fa4  local_buf=0x7ffc67f85fb0  &marker=0x7ffc67f85ff4
[enter] depth=2  &local_int=0x7ffc67f85f74  local_buf=0x7ffc67f85f80  &marker=0x7ffc67f85fc4
[enter] depth=3  &local_int=0x7ffc67f85f44  local_buf=0x7ffc67f85f50  &marker=0x7ffc67f85f94
[exit]  depth=3  (same addresses as enter, depth=3)
[exit]  depth=2  (same addresses as enter, depth=2)
[exit]  depth=1  (same addresses as enter, depth=1)
[exit]  depth=0  (same addresses as enter, depth=0)
```

### Stack memory map (growth direction: **high → low addresses**, x86-64 Linux)

```
High addresses
┌─────────────────────────────────────────┐
│ main() frame                             │  <- created first, lives for whole program
├─────────────────────────────────────────┤
│ walk_stack(depth=0) frame                │
│   marker = 0            @ 0x...86024     │  lifetime: from call entry to that call's return
├─────────────────────────────────────────┤
│ dump_frame("enter",0) frame  (called,    │  lifetime: only while dump_frame(0) is running;
│   then returns before next line runs)    │  destroyed the instant dump_frame returns
├─────────────────────────────────────────┤
│ walk_stack(depth=1) frame                │
│   marker = 10            @ 0x...85ff4    │
├─────────────────────────────────────────┤
│ dump_frame("enter",1) frame              │  (created + destroyed, same pattern)
├─────────────────────────────────────────┤
│ walk_stack(depth=2) frame                │
│   marker = 20            @ 0x...85fc4    │
├─────────────────────────────────────────┤
│ walk_stack(depth=3) frame  (base case)   │
│   marker = 30            @ 0x...85f94    │
├─────────────────────────────────────────┤
│ dump_frame(depth=3) frame (deepest)      │
└─────────────────────────────────────────┘
Low addresses
```

Each recursive call to `walk_stack` allocates a **new** frame roughly 48 bytes (`0x30`)
below the previous one (`0x7ffc67f85fd4` → `0x7ffc67f85fa4` → `0x7ffc67f85f74` →
`0x7ffc67f85f44` — each step down by exactly `0x30`), confirming these are genuinely
distinct stack frames, not a reused/static location.

### Lifetimes (explicit)
- `local_int`, `local_buf`, `p_local` inside `dump_frame`: each exists **only for the
  duration of that specific call** to `dump_frame`. Because `dump_frame` is called twice
  per depth (once on the way down as `"enter"`, once on the way back up as `"exit"`), these
  are actually **two different stack frames that happen to reuse the same address**, since
  the first `dump_frame("enter", depth)` call has already returned (and its frame is
  "deallocated," i.e. no longer valid) before `dump_frame("exit", depth)` is later called
  at the same depth. The identical addresses in the "enter" and "exit" printouts for the
  same depth are **not** the same live object — they are two different objects that
  happen to land in the same freed-and-reused stack slot.
- `marker` inside `walk_stack`: lives from the moment control enters that specific
  `walk_stack` call until that same call returns. Because of recursion, there are up to 4
  *simultaneously alive* `marker` variables at once (one per active call, at depths 0–3),
  each at a distinct address — this is different from `dump_frame`'s locals, which are
  never alive at the same time as each other.
- `p_local` is a pointer that aliases `&local_int` **within the same frame** — it does not
  outlive `local_int`, and since both die together when `dump_frame` returns, there is no
  dangling-pointer risk here (unlike in `aliasing_example.c`).

### Stack vs. heap
Everything in this program is stack memory — there are no calls to `malloc`/`free`. All
lifetimes are strictly tied to function call/return and are managed automatically.

---

## 2. `aliasing_example.c` — Heap Aliasing and Use-After-Free

### What the program does
`make_numbers(5)` heap-allocates an array of 5 ints and returns a pointer to it. `main`
stores that pointer in `a`, then does `b = a;`, making `b` an **alias** of `a` (both point
to the exact same heap block, not a copy). It then frees the block through `a`, and
continues to read and write through the now-dangling `b`.

> Built with the Makefile's flags minus `-Werror` (see the build-result note at the top of
> this document — `-Werror` turns GCC's `-Wuse-after-free` warning on this exact file into
> a hard compile error, so the Makefile as given cannot produce this binary at all).

### Real addresses/output from an actual run
```
a=0x556f6ffe52b0 b=0x556f6ffe52b0 a[2]=22 b[2]=22
after free(a): b=0x556f6ffe52b0 (dangling)
reading b[2]=-278782338
wrote b[3]=1234
```

### Heap memory map

```
Heap
┌───────────────────────────────────────────────┐
│ int[5] block @ 0x556f6ffe52b0                  │
│   [0]=0  [1]=11  [2]=22  [3]=33  [4]=44        │  <- created by malloc() in make_numbers
│   a ──────────────┐                            │
│   b ──────────────┴──► same block (alias)      │
└───────────────────────────────────────────────┘
        after free(a):
┌───────────────────────────────────────────────┐
│ block returned to allocator's free-list        │  <- no longer "owned" by the program
│   a  still holds 0x556f6ffe52b0 (dangling)      │
│   b  still holds 0x556f6ffe52b0 (dangling)      │
└───────────────────────────────────────────────┘
```

### Pointer aliasing (explicit)
`a` and `b` are **not two separate copies of the data** — they hold the identical address
(`0x556f6ffe52b0`), so they are two names for the same one heap object. Any write through
either name affects what the other name reads. This is true both before and after the
`free()` call — `free()` does not change what address `a` or `b` hold, it only invalidates
the memory those addresses point to.

### Lifetime
The heap block's valid lifetime is from the `malloc()` inside `make_numbers` to the
`free(a)` call in `main` — after that point, the memory is logically dead even though
both `a` and `b` still numerically hold its address (this is exactly what "dangling
pointer" means: a pointer whose target's lifetime has ended, but whose value is unchanged).

### ⚠️ Documented example: where the first AI-generated explanation was wrong

**Initial (incorrect) AI draft**, produced before checking against the real run:
> "After `free(a)`, the memory content is unchanged until something else allocates over
> it, so `reading b[2]` will still print `22`, same as before the free."

This is a common and intuitively reasonable claim (undefined behavior often "looks fine"
right after a free, since the bytes aren't zeroed by `free()` itself), but running the
program showed it is **not what actually happened**:

```
a[2]=22        <- before free
reading b[2]=-278782338   <- after free, same address, same index
```

**Why the draft was wrong:** `free()` on glibc does not just mark memory as reusable and
leave the bytes alone — for small allocations it commonly links the freed chunk into a
**tcache freelist**, and doing so involves *writing pointer-sized metadata (a `next`
pointer for the free list) directly into the first bytes of the freed block*. `b[2]` reads
4 bytes starting at offset 8 into the block, which overlaps with where that internal
free-list bookkeeping data was written. That is why the value changed to
`-278782338` (implementation-defined garbage from allocator internals) instead of staying
at `22`. (The exact garbage number is not stable across runs — it depends on ASLR and
allocator state — but the *fact* that it changes, and *why* it changes, is consistent.)

**Correction applied:** The final analysis states that reading (or writing) freed memory
is **undefined behavior with no reliability guarantee about the byte values you'll see** —
not "probably still the old value," and not "definitely garbage" either. The specific
garbage value observed here is a direct, explainable side effect of glibc's allocator
metadata, not a generic "anything could happen" hand-wave. This is also exactly the class
of bug Valgrind's `--track-origins=yes` / memcheck is built to catch, which is why the
assignment title calls this file `aliasing_example` "(Valgrind should report it)."

### Stack vs heap
`a`, `b`, and `n` in `main`, and `arr`, `i` in `make_numbers`, are all **stack** variables
(they hold addresses, or plain ints, but the variables themselves live on the stack and
die when their function returns). The **int array itself** is the only heap object in this
program.

---

## 3. `crash_example.c` — NULL Pointer Dereference

> Built by invoking `gcc` directly with the exact flags from the Makefile
> (`-Wall -Wextra -Werror -pedantic -std=gnu89 -g`), since `make all` stopped at the
> `aliasing_example` error before reaching this target (see the build-result note at the
> top of this document). Built and compiled cleanly with no warnings or errors on its own.

### What the program does
`n` is hardcoded to `0`. `allocate_numbers(0)` hits the `if (n <= 0) return NULL;` guard
and returns `NULL` without ever calling `malloc`. `main` stores that `NULL` in `nums` and
then executes `nums[0] = 42;` — a write through a null pointer.

### Real behavior from an actual run
```
exit code: 139
stderr: Segmentation fault
```
Notably, **no `printf` output appeared at all**, even though the program calls `printf`
twice before the crash. This happens because `stdout` is fully buffered (not line-
buffered) when it isn't connected to a terminal, and the process was killed by SIGSEGV
before the buffer was ever flushed — so those two lines of output existed briefly in an
in-memory stdio buffer that was never written out. This is a real, observable memory-
related behavior in its own right (a buffer that "existed" but was destroyed unflushed)
and is worth explicitly noting rather than assuming the `printf` calls simply "didn't run."

### Memory map
```
Stack (main)                         Heap
┌───────────────┐                    (nothing allocated — allocate_numbers
│ nums = NULL   │  ─── points to ──► returned before reaching malloc())
│ n    = 0      │
└───────────────┘
        │
        ▼
   nums[0] = 42;   <- write to address 0x0 + 0 => SIGSEGV, process terminated
```

### Lifetime
`nums` and `n` are ordinary stack locals with lifetime = the body of `main`. Their
lifetime is irrelevant to the crash — the crash isn't caused by using memory after it was
freed or after a scope ended, it's caused by dereferencing a pointer that was **never
valid to begin with** (`NULL` is not "expired" memory, it was never a valid address at all).
This is a different bug category from Section 2's use-after-free, even though casual
descriptions sometimes lump all pointer bugs together.

---

## 4. `heap_example.c` — Heap Allocation, Struct Members, and a Deliberate Leak

### What the program does
`person_new` heap-allocates a `Person` struct **and** a separate heap-allocated string for
`p->name` (two separate `malloc` calls per `Person`). `main` creates `alice` and `bob`.
For `bob`, both the name buffer and the struct are freed. For `alice`, only
`person_free_partial(alice)` is called, which frees just the `Person` struct, **not**
`alice->name`.

### Real addresses from an actual run
```
alice=0x556473b072b0 name=0x556473b072d0 age=30
bob  =0x556473b072f0 name=0x556473b07310 age=41
```

### Heap memory map

```
Heap
┌──────────────────────────────┐      ┌──────────────────────────────┐
│ Person struct (alice)        │      │ char[6] "Alice\0"            │
│ @ 0x556473b072b0              │      │ @ 0x556473b072d0              │
│   name ───────────────────────┼─────►                              │
│   age = 30                    │      └──────────────────────────────┘
└──────────────────────────────┘

┌──────────────────────────────┐      ┌──────────────────────────────┐
│ Person struct (bob)           │      │ char[4] "Bob\0"               │
│ @ 0x556473b072f0               │      │ @ 0x556473b07310               │
│   name ───────────────────────┼─────►                              │
│   age = 41                    │      └──────────────────────────────┘
└──────────────────────────────┘
```

Each `Person` is **two separate heap allocations aliased through one struct pointer**:
`alice` (and `bob`) point to the struct block; `alice->name` (and `bob->name`) are
separate blocks reached *through* the struct, not embedded inside it.

### Lifetimes (explicit, and where they diverge)

| Object | Allocated | Freed | Result |
|---|---|---|---|
| `bob`'s `Person` struct | `person_new("Bob", 41)` | `free(bob)` in `main` | clean, no leak |
| `bob->name` string | inside `person_new` | `free(bob->name)` in `main` (before `free(bob)`) | clean, no leak |
| `alice`'s `Person` struct | `person_new("Alice", 30)` | `person_free_partial(alice)` | clean, no leak |
| `alice->name` string | inside `person_new` | **never freed** | **memory leak** |

`person_free_partial` only does `free(p)` — it never touches `p->name`. Since `alice` is
cleaned up exclusively through `person_free_partial`, `alice->name`'s heap block outlives
the program's only pointer to it (`alice->name`, which itself dies the instant
`free(alice)` runs and the struct that stored that pointer is gone). After that point
there is no reachable pointer to that memory anywhere in the program — it is a genuine,
permanent leak for the remaining lifetime of the process, exactly as the source comment
"a deliberate leak" states.

By contrast, `bob` is freed correctly: the name is freed **first**, then the struct — order
matters, because once `free(bob)` runs, `bob->name`'s address is no longer accessible to
read.

### Stack vs. heap
`alice` and `bob` (the pointer variables) live on the stack in `main` and disappear when
`main` returns. The `Person` structs and the name strings they point to are the heap
objects; their lifetime is controlled entirely by explicit `malloc`/`free` calls, not by
scope.
