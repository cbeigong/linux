#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <unistd.h>

 //      ssize_t read(int fd, void *buf, size_t count);
// On success, zero is returned.  On error, -1 is returned, and  errno  is set appropriately.
// 
 // ssize_t write(int fd, const void *buf, size_t count);
 //On  success,  the  number  of bytes written is returned (zero indicates
 // nothing was written).  On error, -1  is  returned,  and  errno  is  set appropriately.
// 其中pipe 是 从 file_pipe[1] 中读入 而 从file_pipe[0] 中读出。


int main()
{
	int data_processed;
	int file_pipes[2];
	const char somedata[] = "123";
	char buffer[BUFSIZ + 1];
	memset(buffer, '\0', sizeof(buffer));
	pid_t fork_result;
	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();
		if(fork_result == -1)
		{
			fprintf(stderr, "Fork failure \n");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0)
		{
			data_processed = read(file_pipes[0], buffer, BUFSIZ);
			printf("Read %d bytes %s \n", data_processed,buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			//将somedata 写进去 file_pipes[1]
			data_processed = write(file_pipes[1], somedata, strlen(somedata));
			printf("Wrote %d bytes \n", data_processed);
			//从file_pipes[0] 读到buffer 中去。
			exit(EXIT_FAILURE);
		}
		
	}
	exit(EXIT_FAILURE);

	

}