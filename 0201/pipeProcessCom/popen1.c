#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1023
//其中BUFSIZ 是在stdio.h中定义的 文件流能读取或着写的最大的数

int main()
{
	FILE* read_fp;
	char buffer[BUFSIZ + 1];
	int chars_read;
	//因为buffer 不是指针， 所以可以用sizeof（buffer）计算buffer 的大小。
	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("uname -a", "r");
	if(read_fp != NULL)
	{
		// #include <stdio.h>

       //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       //size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if(chars_read > 0)
		{
			printf("Output was : \n %s \n ", buffer);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);

}