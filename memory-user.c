#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    printf("Current Process ID = %d\n",getpid());
    //converting mebabytes to byte
    long long memory  = atoi(argv[1]) * 1024 *1024;
    long* ip = malloc(memory);

    //time conversion
    time_t begin;
    time_t end;
    time_t duration = atoi(argv[2]);

    begin = time(0);   // getting time
    end = begin + duration;

    // while loop
    while (begin<end){
        printf("processing"); // shwoing process
        fflush( stdout ); //flushes the output buffer of a stream.
        for  (long long i  = 0; i < memory/sizeof(long) ; i++)
        {
            //count of i is assigned to the time array
           ip[i] = i;
        } 
        begin = time(0);  // reassinging time

    }
    //Print of the processes are done
    printf("%s\n ","done");
    exit(0);

    

}
