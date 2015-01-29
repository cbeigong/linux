/*************************************************************************
	> File Name: my_read.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月28日 星期三 15时57分22秒
 ************************************************************************/
#include <sys/types.h>
#include<stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc ,char* argv[])
{
	DIR* fp_dir;
	struct dirent* pent;
	chdir("..");
	fp_dir = opendir(argv[1]);
	if(fp_dir == NULL)
	{
		perror("open");
		exit(1);
	}
	else
	{
		printf("OK\n");
	}
	while((pent = opendir(argv[1]) )!= NULL)
	{
		printf("ino: %u \noff_t:%u\nname: %s\n", pent->d_ino,pent->d_off, pent->d_name);

	}
	closedir(fp_dir);
	return 0;
}
