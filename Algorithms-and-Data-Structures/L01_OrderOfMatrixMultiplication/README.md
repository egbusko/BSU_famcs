## Problem 0.1. Order of matrix multiplication
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

A sequence of s matrices A1, A2, …, As is given. It is required to determine in what order they should be multiplied so that the number of atomic multiplication operations is minimal. The matrices are assumed to be compatible with respect to matrix multiplication (i.e., the number of columns of the matrix Ai − 1 coincides with the number of rows of the matrix Ai).

We will assume that the matrix product is an operation that takes two matrices of size k × m and m ×n as input and returns a matrix of size k × n, having spent kmn atomic multiplication operations. (The base type allows you to store any element of the final and any possible intermediate matrix, so multiplying two elements requires one atomic operation.)

Since matrix multiplication is associative, the resulting matrix does not depend on the order in which the multiplication operations are performed. In other words, there is no difference in what order the brackets are placed between the factors, the result will be the same.

**Input**\
The first line contains the number s of matrices (2 ≤ s ≤ 100). Next s lines contain the sizes of matrices: line i + 1 contains, separated by a space, the number ni of rows and the number mi of columns of the matrix Ai (1 ≤ ni, mi ≤ 100). It is guaranteed that mi coincides with ni + 1 for all indices i from 1 to s − 1.


**Output**\
Print the minimum number of atomic multiplications needed to multiply s matrices.

![image](https://user-images.githubusercontent.com/60915234/193350471-7d0c28c1-fe89-4e5b-b0da-0ef6a76c1209.png)


**Note**\
In the first example, you can multiply in two ways:
(A1(A2A3)): 3×5×10+210 operations required;
((A1A2)A3): 2 × 3 × 5 + 2 × 5 × 10 = 30 + 100 = 130 operations are required.
The second way is more efficient.
