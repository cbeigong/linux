/*************************************************************************
	> File Name: menu.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 17时29分06秒
 ************************************************************************/

//下面的程序有点问题
#include<stdio.h>
#include <stdlib.h>

char* menu[] = {"a - add new record","d - delete record","q- quit", NULL};
int getchoice(char* greet ,char *choice[]);
int main()
{
	int choice = 0;
	do
	{
		choice = getchoice("please select an action", menu);
		printf("you have chosen %c \n", choice);
	}while(choice == '\n');//while(choice != 'q');
	exit(0);
}

int getchoice(char* greet , char* choices[])
{
	int chosen = 0;
	int selected;
	char** option;
	do
	{
		printf("choices: %s\n", greet);
		option = choices;
		while(*option)
		{
			printf("%s \n", *option);
			option++;
		}
		selected = getchar();
		//通常我们会用swith 
		while(*option)
		{
			if(selected == *option[0])
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen)
		{
			printf("Incorrect choice ,select again . \n");
		}
	}while(!chosen);
	return selected;
}
