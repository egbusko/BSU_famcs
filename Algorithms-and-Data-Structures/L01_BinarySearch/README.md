## Problem 0.1. Binary search
Input file name: standard input\
Output file name: standard output\
Time limit: 2s\
Memory limit: 256 MB\


Implement a binary search on an array of numbers sorted in non-decreasing order.
It is forbidden to use ready-made binary search functions from standard libraries.

**Input**\
The first line contains an integer n — the number of numbers in the array (1 ≤ n ≤ 3 * 10^5). The second line contains n array numbers separated by a space. All numbers are integers and belong to the interval from -2^{31} to 2^{31} - 1 inclusive. The numbers in the array are sorted in non-decreasing order.

The third line contains an integer k — the number of requests (1 ≤ k ≤ 3 * 10^5). The fourth line contains k integers-requests from the interval from -2^{31} up to 2^{31} - 1 inclusive.

**Output**\
For each query number x print on a separate line space-separated numbers b, l and r, where b equals 1 if x is present in the array, or 0 otherwise; l is the index of the first element greater than or equal to x; r is the index of the first element greater than x. Array elements are numbered with indices from 0 to n-1. If there are no suitable elements in the array, we will agree that the returned value will be equal to n.

![image](https://user-images.githubusercontent.com/60915234/193348804-e4cf14ef-cb69-476e-af01-3fad900ff50e.png)
