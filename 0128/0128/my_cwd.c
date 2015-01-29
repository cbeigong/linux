/*************************************************************************
	> File Name: my_cwd.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月28日 星期三 15时43分49秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//chdir 没测试成功
int main(int argc, char* argv[])
{
	char* pdir = getcwd(NULL, 0);
	printf("cwd1: %s \n", pdir);
	chdir("..");
	char* edir = getcwd(NULL, 0);
	printf("cwd2: %s \n", edir);
	while(1);
	return 0;
}
