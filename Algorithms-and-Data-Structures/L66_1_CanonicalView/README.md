## Problem 0.5. Canonical view (by list of arcs)
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

Given a directed graph that is a rooted tree. The vertices of the graph are numbered with integers from 1 to n. The arcs are directed from the root to the leaves. Output a canonical way to define this tree.

The canonical way to represent a rooted tree on n vertices is an array P of size n, where pi is the father of vertex i, and if vertex i is the root of the tree, then pi is set to zero.

**Input**\
The first line contains an integer n (1 ≤ n ≤ 100 000). The next n −1 lines contain the arcs of the graph. An arc going from vertex u to vertex v is given by a pair of numbers u and v separated by a space (1 ≤ u, v ≤ n). It is guaranteed that the graph is a rooted tree.

**Output**\
Print n numbers — elements of array P.

![image](https://user-images.githubusercontent.com/60915234/192255401-c6af2a36-a8b1-4d15-9bda-782fddb57497.png)
