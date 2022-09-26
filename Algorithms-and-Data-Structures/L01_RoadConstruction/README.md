## Problem 0.1. Road construction
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

Berland consists of n cities. Initially, all cities are isolated, that is, there are no roads between cities. Roads between pairs of cities will be added in turn. After each added road, it is necessary to find out how many connectivity components from the cities turned out.

**Input**\
The first line of the input file contains two integers n and q (1 ≤  n, q ≤ 500000) — the number of cities and queries, respectively. \
Each of the next q lines contains two integers u, v — between which pair of cities the road will be built. In this problem, at most one road is built between any pair of cities, and u ≠ v is true for any query.

**Output**\
For each query of the second type, you need to display one number — the number of connected components in the graph from cities.

![image](https://user-images.githubusercontent.com/60915234/192258000-45673981-fceb-48fb-b360-8de4731f2f1e.png)
