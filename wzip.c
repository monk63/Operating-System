//  (wzip) is a file compression tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Argument runs if no file is specified
  if (argc <= 1) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

  FILE *fPointer;
  char item[2]="";char previous_item[2] = "";
  int count = 0;

    //open files
  for (int i=1; i < argc; i++) {
    char *textFile = argv[i];
    while ((fPointer = fopen(textFile, "r")) == NULL) {
      printf("wzip: cannot open fPointer");
      exit(1);
    }

    
    while (fread(&item, 1, 1, fPointer)) {
        // This function takes two strings as arguments and compares these two strings if there are a match
      if (strcmp(item, previous_item) == 0) {   
        count++;
      } else {
        //format of the compressed file
        if (previous_item[0] != '\0') {
          fwrite(&count, 4, 1, stdout);
          fwrite(previous_item, 1, 1, stdout);
        }
        count = 1;
        strcpy(previous_item, item); 
      }
    }
    fclose(fPointer);
  }
  
  fwrite(&count, 4, 1, stdout);
  fwrite(previous_item, 1, 1, stdout);
}