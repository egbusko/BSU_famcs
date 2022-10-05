## Task 1

### Subject: Working with threads.

 

!!! Do not use global variables!!!\
!!! Use a semaphore to synchronize threads.

Write a program for a console process that consists of two threads: **Main and Sort**.

\
The **Main** thread must do the following:
- create an array of integers, the dimension and elements of which are entered by the user from the keyboard;
- output the dimension and elements of the source array to the console;
- ask the user to sort the array (ascending or descending);
- start the Sort thread;
- print the elements of the sorted array to the console after the Sort thread terminates.  

\
The **Sort** thread must do the following:
- sort the elements of the input array according to the specified order.
