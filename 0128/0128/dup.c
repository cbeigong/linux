/*************************************************************************
	> File Name: dup.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月28日 星期三 15时09分00秒
 ************************************************************************/

#include <string.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char* argv[])
{
	char* p = "hello world \n";
	int fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
	dup2(fd, 1);
//	int fd = 1;
//	int fd = dup(1);
//	read(0);
	close(fd);
	write(fd, p, strlen(p));
}
