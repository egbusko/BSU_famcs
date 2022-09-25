## Problem 34. Таксист
Input file name: input.txt\
Output file name: output.txt\
Time limit: 1 s\
Memory limit: 1024 MB


There are N cities located by M roads (numbering of roads and cities starts with population). Road traffic is limited to one location, and roads are only covered in cities. The length of each road is known.

It is necessary to find all the roads that a taxi driver can potentially take in such a way that the length of his route differs by no more than K from the length of the shortest route from the 1st city to the Nth.


**Input**\
The first line of the file contains the numbers N, M and K (2 ≤ N ≤ 200000, 1 ≤ M ≤ 200000, 0 ≤ K ≤ 10000). Each of the next M lines describes the road: the start city, the end city and its length (an integer no more than 10 000).


**Output**\
The first line contains the number L of roads that the taxi driver can potentially use.
Each of the next L lines is one number: the number of the potential road. Road numbers are assigned according to the sequence in which they were entered, and the roads themselves follow in ascending order of their numbers.

![image](https://user-images.githubusercontent.com/60915234/192140444-7d810154-ea64-4a56-b654-40595414c9d3.png)

The figure highlights the roads that a taxi driver can potentially drive on.

![image](https://user-images.githubusercontent.com/60915234/192140466-900aff05-d355-4e0c-b9f5-10721c38b474.png)
