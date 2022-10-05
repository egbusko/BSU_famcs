## Task 3
 
### Topic: Developing a Monitor to Synchronize Concurrent Stack Access
 
**Implementation Requirements**
 
1. Monitor interface:

        class MonitorStack {
            MonitorStack(int size);     // size - stack size
            ~MonitorStack();
            void Push(int& element);    // add element to stack
            int pop();                  // remove element from stack
        };
    
2. The stack is implemented by an array whose elements are of type int. The stack size is set in the constructor.
3. If a thread calls the monitor's Push method, and the stack is full at that moment, then this thread must wait until at least one element is removed from the stack.
4. If a thread calls the monitor's Pop method, and the stack is empty at that moment, then this thread must wait until at least one new element is written to the stack.
 
 
 \
**Additional requirements**  
To test the monitor, write a program for the console process, which consists of a **main** thread and several **consumer** and **producer** threads.
 
 \
The **producer** thread must do the following:
- generate a sequence of integers from 1 to a positive integer, which is passed to it as a parameter;
- put the generated integers on the stack;
 
\
The **consumer** thread must do the following:  
- pop integers from the stack;
 
\
The **main** thread should do the following:  
- create a stack monitor, the size of which is entered by the user from the keyboard;
- enter from the keyboard the number of producer threads and the number of consumer threads that it should run;
- for each of the producer and consumer flows, enter the number of integers that these flows must produce and consume, respectively;
- create the required number of producer and consumer flows;
- terminate its work after the end of work of all producer and consumer threads.
 
**Notes**  
1. when adding a number to the stack, output the following message to the console in the Push method:
        "Produced number: N", where N is the number of the number pushed onto the stack.
2. When popping a number from the stack, output the following message to the console:
        "Used the number N", where N is the number of the number popped from the stack.
