#ifndef __SER_H__
#define __SER_H__
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
typedef struct tag
{
	int m_id;
	int m_send;
	int m_recv;
	struct tag* m_next;
}CLIENT, *pCLIENT;
void distpatch(pCLIENT plist,char* message);
#endif