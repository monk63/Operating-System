// Authors : Michael Ofori, Elijah Boateng
//Reference : man manual
// Reference : https://linux.die.net/man/3/execv
//Reference : https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 
int main(int argc, char** argv) {
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }

    int c_pid = fork();


    if(c_pid == 0){
        execv("usr/bin/tree/", &argv[1]);
    }
    //This process was used because it optimizes for the parameters 
    //that would be used to extract the tree.
    //execu takes the path of the file to be exceuted with the array of character pointer.
    // The exec() functions only return if an error has occurred. The return value is -1, and errno is set to indicate the error.
}