## Laboratory work 7. Working with files
 
Develop a console application in Java.
 
**Formulation of the problem**  
It is necessary for the task of laboratory work 6 to provide for entering a condition for selecting information using an SQL query.
 
To complete the lab:  
    1. Learn the syntax for building a SQL SELECT query.  
        Consider writing a query without using column names.  
        Query table name: dataBase.  
        Do not take into account the case of writing keywords and field names in the SQL query.  
    2. Parse the incoming SQL query.  
    3. Select information as requested.
 
**Input data**  
Place the requests in the input text file requests.txt line by line (each request on a new line).
 
**Output**  
Name the output files with a number corresponding to the serial number of the request in the input file.  
For example, request1.xml, request1.json, request2.xml, request2.json, etc.
 
**Requests**  
    1. Find a company by short name.  
    2. Select companies by type of activity.  
    3. Select companies by the number of employees in a certain period (from and to).
 
**Notes**  
    1. Your program must ignore the distinction between lowercase and uppercase letters.  
    2. It is necessary to keep application statistics in the logfile.txt file (date and time of application launch, whether it was successfully completed, exceptions, etc.).
