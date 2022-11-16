#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,  char *argv[])
{
	if (argc !=2)
	{
		exit(0);
	}
	pid_t c_pid = fork();
	if (c_pid == 0)
	{
		
		char *FilePath = "/usr/bin/tree";
  		char *args[] = {FilePath, argv[1], NULL};
		  execv(filepath,args);

	} else {

		wait(NULL);
	}
}
