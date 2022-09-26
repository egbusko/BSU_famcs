## Problem 0.9. Depth first search
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
emory limit: 256 MB

For a directed graph defined by an adjacency matrix, a depth-first search was performed. When the choice of the next vertex was ambiguous, the vertex with the lower number was always chosen. In the process of depth-first search, at the moment of visiting a vertex, a label was assigned to it (the numbering of labels starts from one). Determine what label each of the vertices of the graph received.

**Input**\
The first line contains an integer number n of vertices of the digraph (1 ≤ n ≤ 100). The vertices are numbered from 1 to n. Next, the adjacency matrix of the graph is written: n lines with n numbers, each of which is 0 or 1. The numbers are separated by single spaces. It is guaranteed that all elements on the main diagonal are zero.

**Output**\
Print n numbers, the i-th of which is the label given to node i.

![image](https://user-images.githubusercontent.com/60915234/192252982-869e749f-dbc6-4005-8944-b689fc1ce318.png)
