#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    //converting mebabytes to byte
    //  Using atoi which converts string into integers
    
    long long  process = atoi(argv[1]) * 1024 *1024;
    long* buffer = malloc(process);

    //time conversion
    time_t start;
    time_t finish;
    time_t time_span = atoi(argv[2]);


     // the finish variable allows to calculate the finish time 
     // based on the start time.
    start = time(0);  
    finish = start + time_span;

     
    while (start<finish){
        // the size of the process is converted into int since the 
        for  (long long i  = 0; i < process/sizeof(long) ; i++)
        {
           buffer[i] = i;
        } 
        start = time(0);  // reassinging time

    }
    printf("%s\n","done");
    exit(0);

    

}