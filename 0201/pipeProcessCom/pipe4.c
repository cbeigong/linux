#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//标准输入的文件描述符总是零。

int main(int argc, char* argv[])
{
	int data_processed;
	char buffer[BUFSIZ + 1];
	int file_descriptor;
	memset(buffer, '\0', sizeof(buffer));
	//将又argv[1] 传递过来的文件描述符号度为字符 file_descriptor
	sscanf(argv[1], "%d", &file_descriptor);
	data_processed = read(file_descriptor, buffer, BUFSIZ);
	printf("%d - read %d bytes : %s \n ", getpid(), data_processed, buffer);
	exit(EXIT_SUCCESS);
}