#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	int num;
	char str[num];
	char ch[1]="a";
	int filedes[2];

	num=atoi(argv[1]);
	int i=0;
	while(i<num){
		strcat(str, ch);
		i+=1;

	};
	pipe(filedes);
    write(filedes[1], str, strlen(str));
	
	
	int x=0;
	pid = fork();
	if (pid == 0) 
	{
		printf("%s\n", str); 
		x++;
	}
}