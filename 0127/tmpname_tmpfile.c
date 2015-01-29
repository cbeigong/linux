/*************************************************************************
	> File Name: tmpname_tmpfile.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 14时28分45秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main()
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE* tmpfp;
	
	filename = tmpnam(tmpname);
	printf("Temporary file name is: %s \n", filename);

	tmpfp = tmpfile();
	if(tmpfp)
	{
		printf("Opened a temporary file is OK\n");

	}
	else
	{
		perror("tmpfile\n");
		exit(0);
	}

}
