/*************************************************************************
	> File Name: lock1.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 21时21分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int file_desc;
	int save_errno;

	file_desc = open("/tmp/LCK.test", O_RDWR |  O_CREAT | O_EXCL, 0444);
	if(file_desc == -1)
	{
		save_errno = errno;
		printf("Open failed with error %d \n", save_errno);
	}
	else
	{
		printf("OPEN SUCCEDED \n");
	}
	exit(EXIT_SUCCESS);
}
