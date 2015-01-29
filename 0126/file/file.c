/*************************************************************************
	> File Name: file.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月26日 星期一 20时49分26秒
 ************************************************************************/
#define SIZE_NAME 10;
#define maxSize 20;
#include<stdio.h>
typedef struct Spaxel
{
	char name[SIZE_NAME];
	int row;
	int colom;
	struct Spaxel* next;
}STU,*pSTU;


void read_put()
{
	char buf[maxSize];
	FILE* file_read;
	file_read = fopen("01.csv", "r");
	if(file_read == NULL)
	{
		printf("open file fail");
	}
	
}

int main(int argc, char* argv[])
{
	return 0;
}
