## Problem 0.2. Remove from tree
Input file name: input.txt\
Output filename: output.txt\
Time limit: 1s\
Memory limit: 256 MB

Given a set of keys, build a binary search tree. Delete the key from it (by right deletion) if it exists in the tree. Perform a forward left traversal of the resulting tree.

**Input**\
The first line contains an integer — the key to be removed from the tree.
The second line is empty.

The following lines contain a sequence of numbers - the keys of the vertices in the order they were added to the tree. The keys are specified in the format one per line. The tree contains at least two vertices.

Recall that in a search tree, all keys are by definition unique, so if you try to add a key to the tree that is already there, it is ignored.

**Output**\
Output the sequence of vertex keys obtained by direct left traversal of the tree.

![image](https://user-images.githubusercontent.com/60915234/193088594-6340f2ab-a8bc-45e7-b09f-eb942dfd2120.png)
