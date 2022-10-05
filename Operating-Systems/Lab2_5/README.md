## Task 2.5
**Task**. Write a console program Main and two utilities Creator and Reporter that perform the following actions.



The **Creator** utility creates a binary file, whose name it receives through the command line.

1. The number of file records is entered from the console.
2. File entries are entered from the console and have the following structure:
        
        struct order {
            charname[10]; // product name
            int amount; // number of product units
            double price; // cost of a unit of goods
        };

The **Reporter** utility creates a text file that contains a product report, description
which is stored in a binary file created by the Creator program.

1. The utility receives the following data via the command line:  
 1.1. The name of the original binary file.  
 1.2. The name of the report file.  
 1.3. The minimum number of items.  
 1.4. The minimum total cost of the goods.

2. The report includes data on the quantity and total cost of only those goods, the quantity or total cost of which is less than specified on the command line.

3. The report contains the following lines:  
 3.1. Title: Report on the file "source binary file name".  
 3.2. Rows: product name, number of product units, total cost of the product.

4. The total cost of the goods is calculated by the formula: amount*price.

\
The **Main** program does the following:

1. Requests from the console the name of the generated binary file.

2. Launches the Creator utility, which passes the name of the file to be created via the command line.



3. Waits for the completion of the Creator utility.
4. Prints the contents of the created binary file to the console.

5. Requests from the console:\
    a. The name of the report file.\
    b. The minimum number of items.\
    c. The minimum total cost of the goods.

6. Launches the Reporter utility, which is passed through the command line:  
    a. The name of the original binary file.  
    b. The name of the report file.  
    c. The minimum number of items.  
    d. The minimum total cost of the goods.

7. Waits for the completion of the Reporter utility.

8. Prints the report to the console.

9. Finishes its work.

\
**Note**. To wait for the completion of the Creator and Reporter processes, use the function:

        DWORD WaitForSingleObject(  
            HANDLE hHandle, // object handle  
            DWORD dwMilliseconds // wait interval in milliseconds  
        );
        
where the second parameter is set to INFINITE,  
for example, WaitForSingleObject(hCreator, INFINITE);  
hCreator is a handle to the Creator process.
