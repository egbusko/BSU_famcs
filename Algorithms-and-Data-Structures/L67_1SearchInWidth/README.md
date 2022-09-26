## Problem 0.8. Breadth first search
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

For a directed graph defined by an adjacency matrix, a breadth-first search was performed. When the choice of the next vertex was ambiguous, the vertex with the lower number was always chosen. In the process of breadth-first search, at the moment of visiting a vertex, a label was assigned to it (the numbering of labels starts from one). Determine what label each of the vertices of the graph received (breadth-first search was performed until all vertices received labels).

**Input**\
The first line contains an integer number n of vertices of the digraph (1 ≤ n ≤ 100). The vertices are numbered from 1 to n. Next, the adjacency matrix of the graph is written: n lines with n numbers, each of which is 0 or 1. The numbers are separated by single spaces. It is guaranteed that all elements on the main diagonal are zero.

**Output**\
Print n numbers, the i-th of which is the label given to node i.

![image](https://user-images.githubusercontent.com/60915234/192252334-d3262ade-08ae-4be8-8637-782c970bfd15.png)
