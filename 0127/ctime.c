/*************************************************************************
	> File Name: ctime.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 14时08分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	time_t timeval;
	(void)time(&timeval);
	printf("The date is :%s", ctime(&timeval));
	exit(0);
}
