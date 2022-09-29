## Problem 0.2. Road destruction (simple version)
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256M

Berland has n cities connected by m roads. It is guaranteed that initially the graph of cities is connected, i.e. there is a path between any pair of vertices. There are q earthquakes in Berland, during each of which exactly one road is destroyed. After each earthquake, it is necessary to find out whether the resulting graph from cities is connected. After the next earthquake, the road is not rebuilt, that is, it is destroyed forever.


**Input**\
The first line of the input file contains three numbers n, n, q (1  ≤  n, m, q  ≤  100000) - the number of cities, roads and earthquakes in Berland, respectively.\
The next m lines contain two natural numbers each u and v (1  ≤  u, v  ≤  n) are the numbers of the cities connected by the road. It is guaranteed that u ≠ v and there is at most one road between each pair of cities.\
The next q lines contain one integer each xi (1 ≤ xi ≤ m) - the number of the road that will suffer during time of the i-th earthquake. It is guaranteed that two different earthquakes do not destroy the same road.

**Output**\ 
Output a string of length q consisting of zeros and ones. The i-th symbol is equal to 1 if the graph turned out to be connected after the i-th earthquake, otherwise print 0.

![image](https://user-images.githubusercontent.com/60915234/193090149-c832e993-b3ec-435a-8f32-144ade73510a.png)
