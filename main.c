#include <stdio.h>

int main(void) {
  char * file1 = "file_hole";
  char * file2 = "file_hole2";
  
  dummy_file(file1,"abc","ABC",100);
  
  dummy_file(file2,"abc","ABC",100000);

  printDirContent(".");
  
  saveDirContent(".","files");

  printf("%s size %d bytes \n",file1,getFileSize(file1));

  printf("%s size %d bytes \n",file2,getFileSize(file2));
  
  return 0;
}