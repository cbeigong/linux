#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ + 1];
	sprintf(buffer, "Once upon a time you are a pig <<<<<<<");
	write_fp = popen("od -c", "w");
	if(write_fp != NULL)
	{
		//size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
		//通过buffer 向 write_fp发送消息
		fwrite(buffer, sizeof(char), strlen(buffer)/*sizeof(buffer)*/, write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	
}