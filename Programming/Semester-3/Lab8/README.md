## Laboratory work 8. Working with Threads
 

Write a program for the console process, which consists of two threads: Main (main thread) and Sort.


The Main thread must do the following:

 - create an array of integers (the number of elements is entered by the user from the keyboard), 
 the elements of which are programmatically set by random numbers;
 - display the number of elements and elements of the source array to the console;
 - ask the user to sort the array (ascending/descending by value, ascending/descending by number of digits);
 - start the Sort thread;
 - output the elements of the sorted array to the console after the Sort thread has completed its work.

 

The Sort thread must do the following:  

- sort the elements of the input array according to the given order (use Comparator).
