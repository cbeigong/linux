/*************************************************************************
	> File Name: sizeterm.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 20时31分38秒
 ************************************************************************/

#include<stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
	int nrows , ncolumns;
	setupterm(NULL, fileno(stdout), (int *)0);
	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	printf("This terminal has %d columns and %d rows \n", ncolumns , nrows);
	exit(0);
}
