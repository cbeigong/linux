//#include "my_server.h"
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
#endif
void dispatch(pCLIENT plist,char* message);
int main(int argc, char* argv[])
{
	int fd_listen;
	char path_name[128];
	char fifo_name[128];
	char msg[1024];
	char client_stat[5] = "";
	int client_pid;
	sprintf(path_name,"%s/%s",PIPE_PATH, PIPE_NAME);
	mkfifo(path_name, 0666);
	printf("mkfifo over !\n");

	//int mkfifo(const char *pathname, mode_t mode);
	fd_listen = open(path_name, O_RDONLY);
	if(fd_listen == -1)
	{
		printf("open server_fifo fail ! \n");
		exit(1);
	}
	//int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
	pCLIENT plist = NULL, pcur, pnew, ppre;
	fd_set rd_sets, bak_sets;//每次改变副本
	FD_ZERO(&rd_sets);
	FD_ZERO(&bak_sets);
	FD_SET(fd_listen, &rd_sets);
	while(1)
	{
		bak_sets = rd_sets;
		select(1024, &bak_sets,NULL,NULL, NULL);

		if(FD_ISSET(fd_listen, &bak_sets))
		{
			memset(msg, 0, 1024);

			if( read(fd_listen, msg, 1024) == 0)
			{
				printf("no client! \n");
				continue;
			}
			//<F12>
			memset(client_stat, 0, sizeof(client_stat));
   			scanf(msg, "%d%d", &client_pid, client_stat);
			if(strncmp("on", client_stat,2))
			{// pid_r.fifo(c_r - s_w) pid_w.fifo(c_w - s_r)
				printf("client : %d on \n ", client_pid);
				memset(fifo_name, 0 , 128);
				sprintf(fifo_name, "%d r.fifo", client_pid);
				memset(path_name, 0, 128);
				sprintf(path_name,"%s/%s",PIPE_PATH, fifo_name);

				pnew = (pCLIENT)calloc(1,sizeof(CLIENT));
				pnew->m_id = client_pid;
				pnew->m_send = open(path_name, O_WRONLY);

				memset(fifo_name, 0 , 128);
				sprintf(fifo_name, "%d w.fifo", client_pid);
				memset(path_name, 0, 128);
				sprintf(path_name,"%s/%s",PIPE_PATH, fifo_name);

				pnew->m_recv = open(path_name, O_WRONLY);
				printf("open client fifl : %d , %d \n", pnew->m_send, pnew->m_recv);
				FD_SET(pnew->m_recv, &rd_sets);

				pnew->m_next = plist;
				plist = pnew;


			}
			else
			{
				ppre = NULL;
				pcur = plist;
				while(pcur && pcur->m_id != client_pid)
				{
					ppre = pcur;
					pcur = pcur->m_next;
				}
				if(pcur == NULL)
				{
					printf("not exist ! \n");
					continue;
				}
				else
				{
					if(ppre == NULL)
					{
						plist = pcur->m_next;
					}
					else
					{
						ppre->m_next = pcur->m_next;
					}
					close(pcur->m_send);
					close(pcur->m_recv);
					//FD_CLR(fd, fdsetp)

					
				}
			}
		}
		pcur = plist;
		while(pcur)
		{
			if(FD_ISSET(pcur->m_recv, &bak_sets))//translate
			{
				memset(msg, 0, 1024);
				read(pcur->m_recv,msg, 1024);
				dispatch(plist, msg);
			}
			pcur = pcur->m_next;
		}

	}


	return 0;
}