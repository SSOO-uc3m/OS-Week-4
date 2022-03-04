#ifndef WEEK_04_H    
#define WEEK_04_H   


/*Problem 1:
Write a C program that creates a file, writes something, jumps 100 bytes further from the end of the file, and writes something. 
.*/
void dummy_file(char * srcFileName, char * beginText, char * endText, int jump);


/*Problem 2:
Write a C program that receives a directory name and displays the names of files and directories it contains.
*/

int printDirContent(char * dir);

/*Problem 3:
 Save the content of a folder in a filename
*/

int saveDirContent(char * dir, char * fileName);

/*Problem 4:
 printe the size of a file
*/


long getFileSize(char * fileName); 

#endif /* WEEK_04_H */