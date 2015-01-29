/*************************************************************************
	> File Name: stat.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 15时26分00秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void mode_to_str(mode_t md, char* buf);
int main(int argc, char* argv[])
{
	struct stat my_stat;
	memset(&my_stat, 0,sizeof(my_stat));

	if(-1 == stat(argv[1], &my_stat))
	{
		perror("star");
		exit(1);
	}
	printf("mode: %u \n st_uid: %u \n_link:  \n",my_stat.st_mode,my_stat.st_uid);
}
void mode_to_str(mode_t md, char* buf)
{
	if(S_ISREG(md))
	{
		buf[0] = '-';
	}
	else if(S_ISDIR(md))
	{
		buf[0] = 'd';
	}
	else if(S_ISCHR(md))
	{
		buf[0] = 'c';
	}
	else if(S_ISBLK(md))
	{
		buf[0] = 'b';
	}
	else if(S_ISFIFO(md))
	{
		buf[0] = 'p';
	}
	else if(S_ISLINK(md))
	{
		buf[0] = 'l';
	}
	else
	{
		buf[0] = 's';
	}
	if(st_mode & S_IRUSR)
	{
		buf[1] = 'r';
	}else
	{
		buf[2] = '-';
	}
	if(st_mode & S_IWUSR)
	{
		buf[2] = 'w';
	}else
	{
		buf[3] = '-';
	}
	if(st_mode & S_IRGRP)
	{
		buf[4] = 'r';
	}else
	{
		buf[4] = '-';
	}
	if(st_mode & S_IWGRP)
	{
		buf[5] = 'w';
	}else
	{
		buf[5] = '-';
	}
	if(st_mode & S_IXGRP)
	{
		buf[6] = 'x';
	}else
	{
		buf[6] = '-';
	}
	if(st_mode & S_IROTH)
	{
		buf[7] = 'r';
	}else
	{
		buf[7] = '-';
	}
	if(st_mode & S_IWOTH)
	{
		buf[8] = 'w';
	}else
	{
		buf[8] = '-';
	}
	if(st_mode & S_IXOTH)
	{
		buf[9] = 'x';
	}else
	{
		buf[9] = '-';
	}
	if(st_mode & S_IRUSR)
	{
		buf[1] = 'r';
	}else
	{
		buf[1] = '-';
	}
}
