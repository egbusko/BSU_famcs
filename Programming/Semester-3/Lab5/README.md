## Laboratory work 5: Finding Text in an HTML Page
 
Develop a console application in Java.
 
**Formulation of the problem**


**Input data:**

The input file *input1.html* contains text written in HTML.  
There are tags in the test. There can be multiple tags on one line. Tags are in angle brackets, each opening tag is matched with a closing tag. For example, a pair of \<b>\</b> tags.  
There is text between the tags, and the tags do not break the text. For example, when searching for the word hello, the combination h\<b>\<i>el\</i>l\</b>o should be found.  
It is guaranteed that the HTML page is valid, i.e. all characters "<" and ">" are used only in tags, all tags are written correctly.  
The input file *input2.in* contains a list of text fragments to be found in the first file, separated by separators (semicolon). There may be multiple lines.

 
**Note:** Your program must ignore the distinction between lowercase and uppercase letters for both tags and search context.
 
**Output:**
 1. In the output file *output1.out* output a list of all tags in ascending order of the number of tag characters.  
 2. In the output file *output2.out* output the line numbers (numbered from 0) of the first file in which the searched context was found for the first time or -1 if it was not found.
 3. In the output file *output3.out* - a list of fragments of the second file that were NOT found in the first file.
