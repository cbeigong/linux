#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#define PIPE_PATH "/home/cenlumy/pipe"
#define PIPE_NAME "server.fifo"
int main(int argc, char* argv[])
{
	int fd_server;
	char path_name[128] = "";
	char fifo_name[128];
	char msg[1024] = "";
	sprintf(path_name, "%s/%s",PIPE_PATH, PIPE_NAME);

	fd_server = open(path_name, O_WRONLY);
	if(fd_server == -1)
	{
		printf("open fail .\n");
		exit(1);
	}
	// pie_r.fifo pie_w.fifo
	memset(fifo_name, 0, 128);
	sprintf(fifo_name, "%u r.fifo", getpid());
	memset(path_name, 0, sizeof(path_name));
	sprintf(path_name, "%s/%s", PIPE_PATH, fifo_name);
	mkfifo(path_name, 0666);

	memset(fifo_name, 0, 128);
	sprintf(fifo_name, "%u w.fifo", getpid());
	memset(path_name, 0, sizeof(path_name));
	sprintf(path_name, "%s/%s", PIPE_PATH, fifo_name);
	mkfifo(path_name, 0666);

	printf("mkfifo over ! \n", getpid());
	write(fd_server, msg, strlen(msg));

}