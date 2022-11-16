//  (wunzip) is a file decompression tool.

#include <stdio.h>
#include <stdlib.h>

//compressed file function
static int compress(char *compressFile) {
  int oldFile = compressFile[3];
  for (int i=2; i >= 0; i--) {
    oldFile = (oldFile << 8) | compressFile[i];
  }

  return oldFile;
}

//decompressing the file
char *decompressFile(char compressFile[]) {
  char text = compressFile[4];
  int textCount = compress(compressFile);

  char *uncompressedText;
  if ((uncompressedText = calloc(1, textCount + 1)) == NULL) {
    fprintf(stderr, " ");
    exit(1);
  };
  for (int i=0; i < textCount; i++)
    uncompressedText[i] = text;

  return uncompressedText;
}

int main(int argc, char *argv[]) {

     // Argument runs if no file is specified
  if (argc <= 1) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  FILE *fPointer;
  char compressFile[5];

  for (int i=1; i < argc; i++) {
    char *file_name = argv[i];
    if ((fPointer = fopen(file_name, "r")) == NULL) {
      printf("wzip: cannot open : \n");
      exit(1);
    }
   
   //reading the compressed file
    while (fread(&compressFile, 5, 1, fPointer)) {  
      char *uncompressedText = decompressFile(compressFile);
      printf("%s", uncompressedText); //print out the uncompressed output to standard output 
      free(uncompressedText);
    }

    fclose(fPointer);
  }
}