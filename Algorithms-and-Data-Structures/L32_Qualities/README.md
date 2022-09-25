## Problem 32. Equalities and inequalities
Input file name: equal-not-equal.in\
Output file name: equal-not-equal.out\
Time limit: 1 s\
Memory limit: 256 MB

Problems similar to this one arise in the field of code analysis, automatic theorem proving, and artificial intelligence.

For a set of variables x1, x2, …, xn, you are given a list of equality constraints of the form xi = xj and inequality constraints of the form xi ≠ xj. Is it possible to choose such integer values of the variables x1, x2, ..., xn, so that all constraints are fulfilled simultaneously?

**Input**\
The first line contains the number n of variables (1 ≤ n ≤ 100000) and the number m of constraints (1 ≤ m ≤ 100000).
Then m lines contain the constraints themselves in the format "variable", "operator", "variable". Variables are defined as follows: the letter x, then the number - an integer from 1 to n inclusive. An operator is either == (equal to) or != (not equal to).


**Output**\
Print the answer to the problem question — Yes or No.

![image](https://user-images.githubusercontent.com/60915234/192140810-7e2a2363-b55f-4397-8a62-61527f1561d6.png)
