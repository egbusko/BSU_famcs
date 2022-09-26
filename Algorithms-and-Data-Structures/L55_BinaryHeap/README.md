## Problem 0.3. Is Binary heap?
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

Recall that for compact storage of a complete binary tree on n vertices in the computer memory, you can use a one-dimensional array of length n. The vertex keys are the values ​​of the array elements, indexing starts from one, while the element with index i has children with the elements with indices 2i and 2i + 1 (if such elements exist).

A binary heap is a complete binary tree for which the main property of the "heap" data structure is fulfilled: the elements are organized in such a way that the priority of any vertex is not lower than the priority of each of its sons.

We will assume that among the elements, that element has the highest priority, whose key value is less (Min-Heap).

Given an array of n numbers. You need to check if it can represent a binary heap.

It is forbidden to use special check methods from standard libraries (std::is_heap in C++, etc.).

**Input**\
The first line contains the number n of elements in the array (1 ≤ n ≤ 100 000). The second line contains n space-separated integers not exceeding 109 in modulus — the elements of the array.

**Output**\
Print Yes if there exists a binary heap represented by the given array in memory, or No otherwise.

![image](https://user-images.githubusercontent.com/60915234/192251375-2ed0785d-5098-4cb2-9b0a-52b68b0eeb28.png)
