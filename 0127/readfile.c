/*************************************************************************
	> File Name: readfile.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 10时24分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int fd_in = open(argv[1], O_RDONLY);
	if(fd_in == -1)
	{
		perror("fail");
		exit(1);
	}
	printf("Ok");
	char buf[1024] = "";
	read(fd_in, buf, 1023);
	printf("num: %d  buf:%s",strlen(buf), buf);
	close(fd_in);
	
	return 0;
}


