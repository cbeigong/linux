#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void  ouch(int sig)
{
	printf("OUCH | I got a signal %d \n ", sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	//在调用sa_handler 所指的信号处理函数之前，该信号集将被加入到进程的信号屏蔽字当中
	//可重入的概念： 可以安全的进入和再次执行。
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);
	while(1)
	{
		printf("Hello BEIGONG ! \n");
		sleep(1);
	}
}