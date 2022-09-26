## Problem 21. Shortest route with additional crossing time
Input file name: input.txt\
Output file name: output.txt\
Time limit: 1 s\
Memory limit: no

The city plan is a set of intersections connected by roads (on the road, traffic is allowed in both directions).

Each road is given by the number of intersections it connects and the travel time along it. There can be at most one road between two different intersections. A road cannot connect an intersection to itself. In addition, the time to pass intersection i is equal to qki, where q is a given constant and ki is the number of roads approaching intersection i.

It is necessary to find the shortest route from intersection s to intersection f.

The final intersection f does not need to be overcome, but the starting vertex s of the route is overcome as an intersection.

**Input**\
The first line contains the numbers N and M — the number of intersections (1 ≤ N ≤ 11,000) and the number of roads on the city plan (0 ≤ M ≤ 100,000), respectively.
In each of the next M lines of the file, first there are numbers of intersections that are connected by the next road, and then the time of movement along it (from 0 to 1000).

The last line contains the intersection numbers s and f (1 ≤ s, f ≤ N), as well as the constant q (1 ≤ q ≤ 100).

**Output**\
If it is possible to drive from intersection s to intersection f, print the message Yes on the first line, and the minimum travel time on the second line. If it is impossible to pass, then print the message No on a single line.

![image](https://user-images.githubusercontent.com/60915234/192242619-3072ddee-22f3-4489-8faa-1180b311e905.png)

