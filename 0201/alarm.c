#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;//模拟一闹钟
}

int main()
{
	pid_t pid;
	printf("alarm application starting \n ");
	pid = fork();
	switch(pid)
	{
		case -1:
		perror("fork failed ");
		exit(1);

		case 0:
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);
	}
	printf("waiting for alarm to go off \n");
	(void)signal(SIGALRM, ding);
	//把程序的执行挂起， 知道有一个信号出现为止。
	pause();
	if(alarm_fired)
	{
		printf("DING \n");
	}
	printf("DONE \n");
	exit(0);
}