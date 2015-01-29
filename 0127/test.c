/*************************************************************************
	> File Name: test.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 09时35分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000000
int main(int argc, char* argv[])
{
	FILE** fp_arr = (FILE**)calloc(MAX, sizeof(FILE*));
	char buf[1024] = "";
	int index;
	for(int index = 0; index < MAX; ++index)
	{
		memset(buf, 0, 1024);
		sprintf(buf, "%d.txt", index);
		fp_arr[index] = fopen(buf, "w");
		if((fp_arr[index]) == NULL)
		{
			printf("index: %d ", index);
		}
	}

	return 0;
}
