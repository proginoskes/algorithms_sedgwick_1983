# algorithms sedgwick 1983
In this project, I will be systematically reading 
and implementing all algorithms from Robert 
Sedgewick's 1983 work "Algorithms." I will use 
C++17, since it balances low-level control with 
'off-the-shelf' data structures. This will also
give me the opportunity to learn a bit about how
Pascal and C++ are different, since Sedgwick's
algorithms are in Pascal for this book. I will 
post to this repository five out of every seven 
days until I've finished the book. 

# sections

Sedgwick's book is divided into sections of chapters.
The sections are:
- Mathetmatical Algorithms
- Sorting Algorithms
- Searchin Algorithms
- String Processing Algorithms
- Geometric Algorithms
- Graph Algorithms
- Advanced Topics

First, I will read and implement the first chapter of 
each section (BFS), then I will read and implement the 
rest of each section in order from front to back (DFS).
This will give me broad knowledge first, and then 
introduce more of the complexities in each field over 
time.

I expect the introductory 'DFS' stage to take about a 
week and a half, and each section after that to take
about a week. This means I will plan on being done in
eight weeks, or in the first week of July 2022.

After this, I'll plan on coming back relatively 
consistently to complete the exercises, though I may
place those in a private reposity to retain integrity
of the text.

# complexity 

Sedgwick outlines complexity notation in terms of *N*,
or  the primary parameter for a given function. That is,
"the number of data items to be processed." As expressed,
most algorithms written for the book have complexities
of:

- 1, or "constant time": implying a set number of steps on any input
- log(N), or "logarithmic time": constant factor division on each step.
- N, or "linear time": implying a number of steps equal to some contant multiple of the number of data items.
- Nlog(N), or "linearithmic?": division into subproblems and then combination of these results into a solution.
- N^2, or "quadratic": processing all pairs of data items
- N^3, or "cubic": processing all triplets of data items
- N^x, or "polynomial": processing all x-groupings of N data items.
- X^n, or "explonential": constant factor multiplication on each step.

