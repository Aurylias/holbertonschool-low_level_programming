<h1 style="align: center;">Green Efficiency Analysis</h1>

## Measurement Methodology

We use the `clock_t` type for our variables `start` and `end`, which is a type that's capable of representing the processor time used by a process in ticks. On the other hand, we use the function `clock()` which measure the CPU time in ticks, ticks which begin being counted at the start of the program. Ticks are a more relevant metric for our measurement than wall-clock we can get with `time()`.

`start` takes the number of ticks elapsed since the start of the program just before the implementation we want to measure and `end` takes the number of ticks elapsed right after the implementation finishes running.
Then we subtract `end` by `start` to get the runtime of the implementation in ticks, and then we divide this result by `CLOCKS_PER_SEC` to convert the ticks into seconds, giving us the runtime of the implementation in seconds.

We used this method three times in a row for all implementation we tested, on the same computer and then calculate the average runtime. After that, we compared the avarage value to see which one was faster and the reason why.

## Observed Performance Differences

I will use my analysis in my *comparison_algorithms-metrics.md* to illustrate the difference between the two implementations, with one not optimized and the other optimized.
- The first implementation uses three variables and two for loops, the second nested in the first, making it more complex than the second implementation and has an average runtime of **0.800743 seconds**.
- The second implementation uses two variables and only one for loop and has an average runtime of **0.000097** seconds.

We can clearly see the second implementation is way much faster (around **8255 times** faster) than the first one.

## Relation Between Runtime and Energy Consumption

On a hardware level, energy is mostly consumed when transistors switch on/off so, in general, longer runtime means longer CPU activity. And longer CPU activity requires more energy, with some of this energy being wasted in the form of heat. Heat which needs to be dealt with consuming even more energy.

## Limitations of the Experiment

Here we only measure the runtime difference for different implementations, which is a good indicator, but we don't measure the real power drawn in watts. Depending on the hardware that is used, some will consume less and some more for the same given task, changing the results.

## Practical Engineering Takeaway

A few years ago, we tried to optimize as much as possible the hardware, and in some case the code when working with limited hardware. But with the arrival of high-end hardware, the optimization of the code was some time overlooked, causing simple apps to use a lot more power than they should. Nowadays, we want to optimize the implementation and code in general and we also want to remove all useless parts of the code (unused librarys, functions, variables and so on...) if we want to reduce the energy cost for a given task. Also, it makes the code easier to read and easier to maintain. All of this combined help us reduce the carbon footprint of our applications, which is good for everyone. All resources on Earth are finite and energy is no exception, so we need to be weary about it and save it whenever we can.
