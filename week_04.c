#include "week_04.h"
#include "stdio.h"
#include "string.h"
#include <sys/types.h> // open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // read
#include <stdlib.h> // realloc
#include <dirent.h> // DIR



void dummy_file(char * srcFileName, char * beginText, char * endText, int jump){
  int fd;

 
  if ( (fd=creat(srcFileName,0666))<0)
  {
    perror("error creating the file");
    exit(1);
  }
 
  /* write buf1 in the file */
  if ( write(fd,beginText,strlen(beginText))< 0) {
    perror("write error");
    exit(1);		
  }
  
  /* Jump beyond the end */
  if( lseek(fd,jump,SEEK_END) < 0) {
     perror("seek error");
     exit(1);
  }

  /* write buf2 in the file */

  if ( write(fd,endText,strlen(endText)) <0) {    
    perror("write error");
    exit(1);
  }
  
 
  if (close(fd)<0){    
    perror("close error");
    exit(1);
  }
 
  return 0;
}



int printDirContent(char * dir) {
    DIR * pDir;
    struct dirent * pDirent;
    int file, sz;
    char fileName[260];

    pDir = opendir(dir);
    if (pDir == NULL) {
        printf("Cannot open directory '%s'\n", dir);
        return -1;
    }

    
    while ((pDirent = readdir(pDir)) != NULL) {
            if ( (strcmp(pDirent->d_name, ".")!=0 )&& (strcmp(pDirent->d_name, "..")!=0 )){
      strcpy (fileName, dir);
      strcat (fileName, "/");
      strcat (fileName, pDirent->d_name);
      printf ("%s:\n", fileName);
    }

      
    }

    closedir(pDir);
    return 0;
}

int saveDirContent(char * dir, char * fileName) {
    DIR * pDir;
    struct dirent * pDirent;
    int file, sz;
    char str[260];

    pDir = opendir(dir);
    if (pDir == NULL) {
        printf("Cannot open directory '%s'\n", dir);
        return -1;
    }

    file = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0) {
        printf("Cannot create file '\n");
        return (-1); /* cannot create file */
    }
    
    //printf ("%s\n", fileName);
    while ((pDirent = readdir(pDir)) != NULL) {
        sprintf(str, "%s\n", pDirent -> d_name);
        //printf ("%s\n", str);
        sz = write(file, str, strlen(str));
        if (sz < 0) {
            perror("Error writing file");
            close(file);
            closedir(pDir);
            return (-1);
        }
    }

    close(file);
    closedir(pDir);
    return 0;
}



long getFileSize(char * fileName) {
    struct stat fileStat;
    if (stat(fileName, & fileStat) < 0)
        return -1;

    //printf("%s size %ld B",fileName, fileStat.st_size);
    return fileStat.st_size;

}

