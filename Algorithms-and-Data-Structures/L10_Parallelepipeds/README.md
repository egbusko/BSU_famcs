## Problem 10. Parallelepipeds
Input file name: input.txt\
Output file name: output.txt\
Time Limit: 1s\
Memory limit: no

In n-dimensional space, m parallelepipeds are given by their sizes (ai, 1, ai, 2, …, ai, n), where i = 1, …, m. The box can be located in any area due to the viewing angle, if its coordinates are the coordinate axis. It is necessary to build a structure based on the structure of a sequence of parallelepipeds nested inside each other.

We assume that a box with dimensions (ai, 1, ai, 2, …, ai, n) is placed in a box with dimensions (aj, 1, aj, 2, …, aj, n), if ai, k ≤ aj, k for all k = 1, …, n.

**Input**\
The first line contains numbers n and m (2 ≤ n ≤ 100, 1 ≤ m ≤ 1000). The next m lines have large parallelepiped sizes (n natural numbers in each line, separated by spaces, all numbers do not exceed 1,000,000,000).

**Output**\
Print the maximum number of nested friends in the boxes.


![image](https://user-images.githubusercontent.com/60915234/193080916-33f4c3b6-8946-485c-b886-570c9b1cdea9.png)
