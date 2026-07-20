# Valgrind Analysis

**Tool:** Valgrind 3.22.0, Memcheck
**Command used on each binary:**
`valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./<binary>`
**Binaries:** the same ones built in Task 1 (`stack_example`, `heap_example`,
`crash_example` built with the Makefile's flags; `aliasing_example` built with the same
flags minus `-Werror`, since the Makefile's `-Werror` prevents it from compiling at all —
see `analysis/memory_maps.md` for the full explanation of that build issue).

Method, per the assignment: run Valgrind, capture the raw output, have an AI draft an
interpretation of each report, then independently verify that draft against the actual
source code and the memory maps from Task 1 before writing anything down here. One
verification failure is documented explicitly in Section 2.

---

## 1. `stack_example` — Clean

```
==804== HEAP SUMMARY:
==804==     in use at exit: 0 bytes in 0 blocks
==804==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==804== All heap blocks were freed -- no leaks are possible
==804== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

**Classification:** No Valgrind errors.

**Why this program is clean:** every object it touches (`local_int`, `local_buf`,
`p_local`, `marker`) is a **stack** variable, and every read/write happens strictly within
the lifetime of the function call that owns it (see Task 1 for the exact frame-by-frame
lifetimes). There is no `malloc`/`free` in this file at all — the "1 allocs, 1 frees"
shown above is `libc`/`stdio` internal bookkeeping (buffer setup for `printf`), not
anything from the program's own code, and Valgrind correctly reports it as fully freed by
program exit.

---

## 2. `aliasing_example` — Invalid Read/Write of Freed Memory (Use-After-Free)

```
==810== Invalid read of size 4
==810==    at 0x1092F5: main (aliasing_example.c:42)
==810==  Address 0x4a7d088 is 8 bytes inside a block of size 20 free'd
==810==    at 0x484988F: free (...)
==810==    by 0x1092D1: main (aliasing_example.c:38)
==810==  Block was alloc'd at
==810==    at 0x4846828: malloc (...)
==810==    by 0x1091E4: make_numbers (aliasing_example.c:12)
==810==    by 0x109272: main (aliasing_example.c:30)

==810== Invalid write of size 4
==810==    at 0x109315: main (aliasing_example.c:44)
==810==  Address 0x4a7d08c is 12 bytes inside a block of size 20 free'd  [same free/alloc sites]

==810== Invalid read of size 4
==810==    at 0x109323: main (aliasing_example.c:45)
==810==  Address 0x4a7d08c is 12 bytes inside a block of size 20 free'd  [same free/alloc sites]

==810== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```

**Classification:** **Use-after-free** — specifically, one invalid *write* and two invalid
*reads*, all on the same already-freed heap block.

**Memory object involved:** the 20-byte (`5 × int`) heap block allocated by
`malloc((size_t)n * sizeof(int))` inside `make_numbers` (`aliasing_example.c:12`), returned
to `main`, and stored simultaneously in `a` and `b` (`b = a;` makes them aliases of the
same block — confirmed in Task 1).

**Lifetime violation, precisely:** the block's valid lifetime ends at `free(a)`
(`aliasing_example.c:38`). Every one of the three errors above happens **after** that line:
- Line 42 (`reading b[2]`) — invalid read, 8 bytes into the block (index 2 × 4 bytes).
- Line 44 (`b[3] = 1234;`) — invalid write, 12 bytes in (index 3 × 4 bytes).
- Line 45 (`printf("wrote b[3]...")`, which reads `b[3]` back) — invalid read, same offset.

`free()` does not erase or invalidate the pointer values held by `a` or `b` — it only ends
the validity of the memory they point to. Because `b` is an **alias**, not a separate
allocation, freeing through `a` ends `b`'s validity too, even though `b` itself was never
passed to `free()`. This is exactly the use-after-free pattern the assignment's own file
comment calls out ("Valgrind should report it").

### ⚠️ Documented example: where the AI's interpretation was wrong

**Initial AI draft**, written before comparing against Task 1's actual native-run data:
> "Valgrind should confirm the same thing the native run showed in Task 1 — that
> `b[2]` reads back as corrupted/garbage data, since that's what happened when we ran the
> program normally without Valgrind."

**What the real output actually shows:** under Valgrind, the program's own printed output
for this run was:
```
a=0x4a7d080 b=0x4a7d080 a[2]=22 b[2]=22
after free(a): b=0x4a7d080 (dangling)
reading b[2]=22
wrote b[3]=1234
```
`b[2]` still reads as `22` — the *original* value — **not** the corrupted garbage value
(`-278782338`) that the native run in Task 1 produced.

**Why the draft was wrong:** it assumed Valgrind would reproduce the native allocator's
behavior. It doesn't. Valgrind's Memcheck **replaces** glibc's normal `malloc`/`free` with
its own instrumented versions (visible directly in the stack traces above —
`vgpreload_memcheck-amd64-linux.so`'s `malloc`/`free`, not glibc's). Memcheck deliberately
does **not** immediately hand a freed block's bytes back to glibc's tcache free-list the
way native `free()` does; instead it quarantines freed blocks (so it can still detect and
report accesses to them) and does not overwrite their contents in the same way native
`free()`'s tcache metadata write does. That's why the *bytes* look "unchanged" under
Valgrind, even though the access is just as invalid as it was natively.

**Correction applied:** the values you see when reading freed memory are **implementation
detail, not a required guarantee** — this run under Valgrind happened to preserve the old
value, the native run in Task 1 happened to corrupt it, and neither behavior is something
correct code may rely on. The one fact that **is** consistent and is what actually matters
here is that Valgrind correctly flags the access itself as invalid regardless of what the
bytes happen to look like. Don't confuse "the number displayed" with "whether the access
was legal" — Valgrind is telling you about the latter, not the former.

---

## 3. `heap_example` — Memory Leak ("Definitely Lost")

```
==813== HEAP SUMMARY:
==813==     in use at exit: 6 bytes in 1 blocks
==813==   total heap usage: 5 allocs, 4 frees, 4,138 bytes allocated
==813== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==813==    at 0x4846828: malloc (...)
==813==    by 0x109211: person_new (heap_example.c:21)
==813==    by 0x1092FA: main (heap_example.c:51)
==813== LEAK SUMMARY:
==813==    definitely lost: 6 bytes in 1 blocks
```

**Classification:** **Memory leak, "definitely lost"** — Valgrind's strongest leak
category, meaning no pointer to this block exists anywhere in the program at exit (not
even an indirect one).

**Memory object involved:** the 6-byte `char` buffer allocated at `heap_example.c:21`
(`p->name = (char *)malloc(len + 1);`) during the call `person_new("Alice", 30)` — 6 bytes
is exactly `"Alice\0"` (5 characters + null terminator), which confirms this is `alice`'s
name string specifically, not `bob`'s.

**Lifetime violation, precisely — "leak due to lost ownership":** `person_free_partial`
(called on `alice`) does `free(p)` only; it never frees `p->name`. The moment
`free(alice)` runs, the `Person` struct holding the only pointer to that name string is
itself gone, so the name buffer's address is no longer stored anywhere the program can
reach — the block still technically exists on the heap, but its **owning reference has
been destroyed while the block itself was never freed**. That is what "definitely lost"
formally means: unreachable *and* unfreed at the same time. This matches exactly what
Task 1's lifetime table predicted from reading the source alone, and the 6-byte size is
independent, code-level confirmation that the leaked block really is `alice->name` and not
some other allocation.

`bob`'s equivalent string is freed explicitly (`free(bob->name)`) before `free(bob)` in
`main`, which is why only one leak record appears, not two.

---

## 4. `crash_example` — Invalid Write (NULL Pointer Dereference) + Still-Reachable Block

```
==816== Invalid write of size 4
==816==    at 0x10928A: main (crash_example.c:32)
==816==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==816== Process terminating with default action of signal 11 (SIGSEGV)
==816==  Access not within mapped region at address 0x0

==816== 4,096 bytes in 1 blocks are still reachable in loss record 1 of 1
==816==    at 0x4846828: malloc (...)
==816==    by 0x48EC1B4: _IO_file_doallocate (filedoalloc.c:101)
...
==816==    by 0x10925E: main (crash_example.c:27)
==816== LEAK SUMMARY:
==816==    definitely lost: 0 bytes in 0 blocks
==816==    still reachable: 4,096 bytes in 1 blocks
```

**Classification:** two separate things are reported here, and they must not be conflated:
1. An **invalid write** (a NULL-pointer dereference), which is the actual bug and the
   reason the program crashes.
2. A **"still reachable"** block, which is **not a bug** in this program.

**Memory object involved in the invalid write:** no heap object at all — `nums` holds
`NULL` (`allocate_numbers(0)` returned `NULL` without ever calling `malloc`, per the
`if (n <= 0) return NULL;` guard). `nums[0] = 42;` at `crash_example.c:32` writes to
address `0x0`, which Valgrind correctly reports as *"not stack'd, malloc'd or
(recently) free'd"* — i.e., not a lifetime-ended object, but an address that was never
valid to begin with. This is a different bug category from Section 2's use-after-free:
there, the memory *had* a lifetime that ended; here, there was never any valid memory at
that address in the first place.

**Memory object involved in the "still reachable" block:** a 4,096-byte buffer allocated
internally by glibc's `stdio` (`_IO_file_doallocate`) the first time `puts`/`printf` writes
to `stdout` (`crash_example.c:27`) — this is the exact same stdio output buffer discussed
in Task 1's write-up, where the program's `printf` output never appeared because the
process was killed by SIGSEGV before the buffer was flushed. Valgrind's "still reachable"
category means the block was never freed by program exit, but a pointer to it (held
internally by glibc) still existed — this is expected, normal C library behavior on an
abnormal (crashed) exit, **not** a leak caused by anything in this program's own code.
Correctly classifying this line is part of the point: a naive read of the Valgrind output
could mistake "still reachable: 4,096 bytes" for "the program leaks memory," when the
actual, code-level bug here is the NULL dereference, and the reachable block is a harmless
side effect of the process dying before glibc's normal `stdio` cleanup ran.
