/*************************************************************************
	> File Name: copy_system.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月25日 星期日 21时14分18秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int in, out;
	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while(read(in, &c, 1) == 1)
	{
		write(out, &c, 1);
	}
	exit(0);
}

