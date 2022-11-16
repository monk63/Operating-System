#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *fPointer;
  char buffer[100000];  // Buffer to hold what you read in the file

  for (int i=1 ; argv[i]; i++) {
    fPointer = fopen(argv[i], "r");  //'r' to read and open the file
    if (!fPointer) {
      printf("File cannot open.. oops\n");
      exit(0);
    }
    // cheking contents in the file
    while (fgets(buffer, sizeof buffer, fPointer) != NULL)
      printf("%s", buffer);
      
    if(ferror(fPointer)) {
       printf("Error: Cannot read content in file.");
      fclose(fPointer);
     exit(1);
    }
  }
  exit(0);
}