#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//程序以两个进程的形式在运行， 父进程和子进程都在运行这个程序所以总体的输出会会是交替的。

int main()
{
	pid_t pid;
	char* message;
	int n;
	perror("fork program statring \n");
	pid = fork();

	switch(pid)
	{
		case -1:
		perror("fork failed ");
		exit(1);
		case 0:
		message = "This is the child";
		n =  5; 
		break;
		default:
		message = "This is the  parent";
		n = 3;
		break;
	}
	for(; n > 0; --n)
	{
		puts(message);
		sleep(1);
	}
	exit(0);
}