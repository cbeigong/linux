/*************************************************************************
	> File Name: syslog.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 17时03分41秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main()
{
	FILE* f;
	f = fopen("not_hear", "r");
	if(!f)
		syslog(LOG_ERR | LOG_USER, "opps = %m \n");
	exit(0);
}
