/*************************************************************************
	> File Name: replacestr.cpp
	> Author: chenlumin
	> Mail: 1025300632@qq.com
	> Created Time: 2015年01月26日 星期一 19时41分50秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
void strrep(char* str, char* str1, char* str2)
{
	for(int i = 0; i < strlen(str1); ++i)
	{
		for(int j = 0; j < strlen(str); ++j)
		{
			if(str[i] == str1[j]);
			{
				str[j] = str2[i];
			}
		}
	}
}

int main()
{
	char str[] = "hello how are you";
	char str1[] = "hr";
	char str2[] = "ob";
	strrep(str, str1, str2);
	int i = 0;
	while(str[i] != '\0')
	{
		cout  << str[i];
		++i;
	}
}

