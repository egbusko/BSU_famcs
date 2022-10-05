## Task 2
 
### Topic: Synchronization of processes
 
Write an implementation of two console processes, Boss and Scout, that perform the following actions.
 
**Boss process**
1. prompts the user for the number of Scout processes to run;
2. starts a user-specified number of Scout processes;
3. Receives a message from each of the Scout processes and prints each of the messages to the console.
 
**Process Scout**
1. character by character enters a string consisting of ‘ – ‘ and ‘ . ‘, and prints it to your console;
2. character-by-character passes the entered string to the Boss process in the process of its input;
3. after the string is passed, it terminates its work.
 
**Implementation requirement**
1. to transfer dot and dash characters between processes, use events;
2. ensure that two Scout processes cannot send a message at the same time.
