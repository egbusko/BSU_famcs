## Problem 0.7. Canonical view (by adjacency matrix)
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

Given a directed graph that is a rooted tree. The vertices of the graph are numbered with integers from 1 to n. The arcs are directed from the root to the leaves. Output a canonical way to define this tree.

The canonical way to represent a rooted tree on n vertices is an array P of size n, where pi is the father of vertex i, and if vertex i is the root of the tree, then pi is set to zero.

**Input**\
The first line contains an integer n (1 ≤ n ≤ 100). The next n lines contain the adjacency matrix of the graph. If the graph has an arc leading from vertex i to vertex j, then the j-th number in the i-th row of the matrix is ​​1, otherwise 0. The numbers are separated by single spaces. It is guaranteed that the input graph is a rooted tree.

**Output**\
Print n numbers — elements of array P.

![image](https://user-images.githubusercontent.com/60915234/192255654-52110c3f-351f-400a-be71-c14b417f7b09.png)
