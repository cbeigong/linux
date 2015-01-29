/*************************************************************************
	> File Name: file1.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月26日 星期一 21时19分30秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE* in, *out;
	in = fopen("file.in", "r");
	out = fopen("file.out", "w");
	while((c = fgetc(in)) != EOF)
	{
		fputc(c,out);
		exit(0);
	}


}
