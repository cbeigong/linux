#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <grp.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#include<fcntl.h>
#include<errno.h>
#define MY_ASSERT(flag, msg)  do {\
	(flag) || (printf("%s\n",msg ) , exit(1) , 0  ) ;\
}while(0)
void setnonblock(int sfd)
{
	int old_flag ;
	old_flag = fcntl(sfd, F_GETFL);

	old_flag = old_flag | O_NONBLOCK ;//
	//old_flag &= ~O_NONBLOCK
	fcntl(sfd, F_SETFL, old_flag);
}
int main(int argc, char* argv[])// ip port
{
	int fd_listen, fd_client ;
	int epoll_fd ;
	MY_ASSERT( (fd_listen = socket(AF_INET, SOCK_STREAM, 0)) != -1, "listen socket init" );
	struct sockaddr_in seraddr ;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons( atoi(argv[2]) );
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "bind");
	MY_ASSERT(listen(fd_listen, 10) == 0, "listen");

	MY_ASSERT( (epoll_fd = epoll_create(1024) ) != -1, "epoll create" );

	struct epoll_event my_event , my_events[1024];
	char buf[1024] ;
	int ready_events , index ;
	memset(&my_event, 0, sizeof(my_event));
	my_event.events = EPOLLIN ;
	my_event.data.fd = fd_listen ;

	MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_listen, &my_event) == 0, "epoll ctl" );

	while(1)
	{
		memset(my_events, 0, sizeof(my_events));
		ready_events = epoll_wait(epoll_fd, my_events, 1024, -1);
		for(index = 0; index < ready_events; index ++)
		{
            pid_t pid;
			if( my_events[index].events & EPOLLIN && my_events[index].data.fd == fd_listen )
			{
				fd_client = accept(my_events[index].data.fd, NULL, NULL);
				printf("a client connect !\n");

				setnonblock(fd_client);
				memset(&my_event, 0, sizeof(my_event));
				my_event.events = EPOLLIN | EPOLLET;
				my_event.data.fd = fd_client ;

				MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_client, &my_event) == 0, "epoll ctl client" );

			}else if(my_events[index].events & EPOLLIN)
			{
				int recv_ret ;
				int recv_sum = 0 ;
				memset(buf, 0, 1024);
				while(1)
				{
					recv_ret = recv(my_events[index].data.fd, buf + recv_sum, 1024 - recv_sum, 0)  ;
					if( recv_ret == 0)
					{
						printf("a client exit !\n");
						MY_ASSERT( epoll_ctl(epoll_fd, EPOLL_CTL_DEL, my_events[index].data.fd, NULL) == 0, "epoll del");
						break ;
					}else if(recv_ret > 0)
					{
						recv_sum += recv_ret ;
					}else if(recv_ret == -1 && errno == EAGAIN)
					{
                        DIR* fp_dir;
                        struct dirent* pent;

                        fp_dir = opendir("./");
                        if(fp_dir == NULL)
                        {
                            perror("open");
                            exit(1);
                        }
                        printf("OK\n");
                        while((pent = readdir(fp_dir)) != NULL)
                        {
                            int ret;
                            struct stat my_stat;
                            memset(&my_stat, 0, sizeof(my_stat));
                            if(-1 == stat(pent->d_name, &my_stat))
                            {
                                perror("stat");
                                exit(1);
                            }
                            sprintf(buf,"%s %5d",pent->d_name, my_stat.st_size);
                            printf("%s\n", buf);
                           // ret = send(fd_client,buf, strlen(buf), 0);
					        ret = send(my_events[index].data.fd, buf, strlen(buf), 0)  ;
                            printf("ret :%d    ", ret);
                        }
                            printf("%s \n ", buf);

                      //  send(fd_client ,buf, strlen(buf), 0);

                    //    closedir(fp_dir);

						//printf("recv from client: %s\n", buf);
						break ;
					}

				}
			}
		}
	}





	return 0 ;
}
