#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//僵尸进程 ， 子进程先死，但是子进程与父进程的关联还在， 如果此时父进程意外停止的话， 
//子进程将把他自己托给init 进程，， 僵尸进行将一直保留在进程表中个，知道被init 进程发现
//并且清理
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
		n =  3; 
		break;
		default:
		message = "This is the  parent";
		n = 5;
		break;
	}
	for(; n > 0; --n)
	{
		puts(message);
		sleep(1);
	}
	exit(0);
}