/*************************************************************************
	> File Name: memory.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 20时57分34秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define ONE_K (1024000)

int main()
{
	char* some_memory;
	double size_to_allocate = ONE_K;
	int megs_obtained = 0;
	int ks_obtained = 0;
	
	while(1)
	{
		for(ks_obtained = 0; ks_obtained < 102400000; ks_obtained++)
		{
			some_memory = (char*)malloc(size_to_allocate);
			if(some_memory == NULL)
			{
				exit(EXIT_FAILURE);
				sprintf(some_memory,"Hello World");
			}
			megs_obtained++;
			printf("Now alllocated %d Megabytes \n", megs_obtained);
		}
		exit(EXIT_SUCCESS);
	}
}
