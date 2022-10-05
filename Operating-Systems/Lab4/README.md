## Task 4
### Subject: Anonymous Data Sharing

**Formulation of the problem**  
Write a program to control the access of parallel processes to a file via an anonymous channel.
1. Develop a server process that performs the following actions:  
        1.1. Creates a binary file whose entries have the following structure:
    
                struct Student
                {
                    int num; // record number
                    charname[20]; // student's last name
                    double grade; // average score
                };
                
                The file name and student data are entered from the console.
    
        1.2. Prints the generated file to the console.  
        1.3. Starts Client processes that access a file over an anonymous channel. The number of client processes is entered from the console.  
        1.4. Serves requests from client processes as follows:
        - if a client process requests modification of a file entry, then access to this file entry is blocked for other client processes until the modification of the record by the client is completed;
        - if the client process requests to read the entry, then access to this entry for other client processes:
        - not blocked if they also request read access to the data;
        - is blocked if they request access to write data.
    
        1.5. After all client processes are finished, outputs the modified file to the console.  
        1.6. On command from the console, it terminates its work.

2. Develop a Client process that executes the following cycle:  
        2.1. Requests from the console the action to be performed:
            - modification of the file record;
            - reading record;
            - exit from the cycle.
    
        2.2. Access to the records of the file is carried out by the key, which is the record number.  
        2.3. When a record is modified, the client process performs the following actions:
            2.3.1. Requests a record key.
            2.3.2. Sends a request to the server.
            2.3.3. Prints the record received from the server to the console.
            2.3.4. Requests new field values.
            2.3.5. On command from the console, sends the modified record to the server.
            2.3.6. Terminates write access on command from the console.
    
        2.4. When reading a record, the client process does the following:
            2.4.1. Requests a record key.
            2.4.2. Sends a request to the server.
            2.4.3. Prints the record received from the server to the console.
            2.4.4. Terminates write access on command from the console.
 
**P.S.**  
    1. Implement this task with classes.  
    2. Read student data from a text file in CSV format.  
    3. Organize direct access to file records by key using a hash function.
