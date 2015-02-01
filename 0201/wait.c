#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
//程序以两个进程的形式在运行， 父进程和子进程都在运行这个程序所以总体的输出会会是交替的。

//下面的程序是通过wait系统调用的的返回值来判断子进程是否终止
//linux p400 又几个宏定义

int main()
{
	pid_t pid;
	char* message;
	int n;
	int exit_code;
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
		exit_code = 37;
		break;
		default:
		exit_code = 0;
		message = "This is the  parent";
		n = 3;
		break;
	}
	for(; n > 0; --n)
	{
		puts(message);
		sleep(1);
	}
	if(pid != 0)
	{
		//如果stat_val 不是空指针， 状态信息将会被写入他所指向的位置
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);
		printf("Chile has finished PID: %d \n", child_pid);
		if(WIFEXITED(stat_val))
		{
			printf("Chile has exit with PID: %d \n", WEXITSTATUS(stat_val));
		}
		else
		{
			printf("Child termanited abnormally \n");
		}
	}
	exit(exit_code);
}