## Problem 0.4. Binomial heap
Input file name: input.txt\
Output file name: output.txt\
Time limit: 1 s\
Memory limit: 64 MB

A binomial tree of height k is denoted by Bk and is defined as follows.

The binomial tree B0 consists of one single vertex.
The binomial tree Bk is formed by joining a binomial tree of height k − 1 to the root of another binomial tree of height k − 1 (during the addition, the root of one of the trees is assumed to be one of the sons of the root of the other tree).
Thus, the binomial tree Bk has a root vertex whose sons are the roots of the binomial trees B0, B1, B2, …, Bk − 1.

![image](https://user-images.githubusercontent.com/60915234/192249319-35df4a2c-6ba2-4233-9d6b-5c2b85dda14b.png)

The binomial heap consists of a set of binomial trees of different heights in pairs. In other words, for any k ≥ 0, the binomial tree Bk either does not appear in the heap or occurs exactly once.

The total number n of vertices in the binomial heap is given. Determine which binomial trees this heap can consist of.

**Input**\
The input is one number n of vertices in the heap (1 ≤ n ≤ 1018).

**Output**\
For each binomial tree Bk in the heap, print on a separate line one integer — the height k. Trees should be displayed in ascending order of height. All trees must have different orders, and the sum of the orders must be n.
If there are several solutions, print any one. If there are no solutions and it is impossible to construct a binomial heap with the given number of vertices, print −1.

![image](https://user-images.githubusercontent.com/60915234/192249548-fe3bc1ef-2a86-4b1d-b46e-fb60907614d2.png)

