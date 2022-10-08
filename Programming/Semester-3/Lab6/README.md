## Laboratory work 6. Working with various data storage formats (CSV, XML, JSON)
 
Develop a console application in Java.
 
**Formulation of the problem**  
You need to read the data, process it, and write the output in the specified format.
 
**Input data**  
The input file input contains data in CSV format.  
Each entry in the file is on a new line.  
The separator between the fields of one record is the semicolon character (';').  
If there is no value for some field of the record, then split is still present.  
Mandatory fields are only those fields on which queries are built for data selection.
 

**Input data format**  
There is a list of companies.  
Each list element contains the following fields:

    Name (name)
    Short title (shortTitle)
    Update date (dateUpdate)
    address
    Foundation date (dateFoundation)
    Number of employees (countEmployees)
    Auditor
    phone
    Email (email)
    Branch
    Type of activity (activity)
    Internet page address (internetAddress/link)

 
**Output**  
    1. Read data from the input file.  
    2. Select data on request.  
    3. Write the received data to two files (in XML format and JSON).
 
**Requests**  
    1. Find a company by short name.  
    2. Select companies by industry.  
    3. Select companies by type of activity.  
    4. Select companies by founding date within a certain range (from and to).  
    5. Select companies by the number of employees in a certain period (from and to).
 
**Notes**  
    1. Your program must ignore the distinction between lowercase and uppercase letters.  
    2. It is necessary to keep application statistics in the logfile.txt file. Data must be accumulated. Data format: date and time when the application was launched; request text; the number of records found that match the query condition.
