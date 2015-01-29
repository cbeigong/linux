/*************************************************************************
	> File Name: main.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月28日 星期三 14时53分34秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
extern void function_two();
extern void function_three();

int main()
	{
		function_two();
		function_three();
		exit(EXIT_SUCCESS);
	}
