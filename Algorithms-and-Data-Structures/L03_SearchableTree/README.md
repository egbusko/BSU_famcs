## Problem 0.3. Is a binary tree searchable?
Input file name: bst.in\
Output file name: bst.out\
Time limit: 1s\
Memory limit: 64 MB

Given a directed graph G containing n vertices and m arcs, each arc (u, v) is assigned a capacity cuv.
It is required to find in this network the maximum flow from the source (vertex 1) to the sink (vertex n).

**Input**\
The first line contains two numbers n and m — the number of vertices and arcs in the graph, respectively. It is guaranteed that 1 ≤ n, m ≤ 200.
Each of the next m lines contains three numbers ui, vi, wi — two vertices connected by an arc and the capacity of this arc. It is guaranteed that ui ≠ vi, 1 ≤ ui, vi ≤ n, 1 ≤ wi ≤ 1000000 for each arc.

**Output**\
Print a single number — the maximum possible flow in the given graph.

![image](https://user-images.githubusercontent.com/60915234/193082521-e3f6fc00-ecac-43e8-af31-81b79743bae7.png)

**Note**\
The tree from the example can be drawn as follows:
![image](https://user-images.githubusercontent.com/60915234/193082646-fdfa271b-24d9-48c5-94e7-46e670247381.png)
