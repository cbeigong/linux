#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void outch(int sig)
{
	printf("outch ! I got a singal %d \n ", sig);
	//printf("OUCH ! I got a signal %d \n",sig）;
	//第一个参数是忽略信号， 第二个参数是恢复默认行为
	(void)signal(SIGINT, SIG_DFL);
}

int main()
{
	(void)signal(SIGINT, outch);
	while(1)
	{
		printf("Hello BEIGONG \n ");
		sleep(1);
	}
}