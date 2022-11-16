// This tool looks through a file, line by line,
// trying to find a user-specified search term in the line
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *filePointer = NULL;
    char *line = NULL;
    size_t lineSize = 32;

    char *item = argv[1]; //argument 1 for search item in file
    char *file = argv[2];  //argument 2 to find search item in the line

    // checking the arguments passed on the terminal
    if (argc <= 1)
    {
        //wgrep is passed no command-line arguments
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
   // if argument is 2 usee would enter the search item
   //from standard input
    if (file)
        filePointer = fopen(file, "r");
    else
        filePointer = stdin; //taking standard input

    //wgrep encounters a file that it cannot open
    if (!filePointer)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    
    //
    while (getline(&line, &lineSize, filePointer) != -1)
        if (strstr(line, item))  //retrun trueif the search item is in the line
            printf("%s", line); //prints the line containing the search item

    fclose(filePointer);
    exit(0);
}