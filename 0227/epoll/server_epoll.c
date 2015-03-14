#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#define MY_ASSERT(flag, msg) do{\
        (flag) || (printf("%s \n", msg), exit(1), 0);\
}while(0)
int main(int argc, char* argv[])
{
    int fd_listen,fd_client;
    int epoll_fd;
    MY_ASSERT((fd_listen = socket(AF_INET, SOCK_STREAM, 0)) != -1, "listen socket init");
    struct sockaddr_in seraddr;
    memset(&seraddr, 0, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);
    MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "bind");
    MY_ASSERT(listen(fd_listen, 10) == 0,"listen");

    MY_ASSERT( (epoll_fd = epoll_create(1024)) != -1, "epoll create");

    struct epoll_event my_event, my_evets[1024];
    char buf[1024];
    int ready_events, index;
    memset(&my_event, 0, sizeof(my_event));
    my_event.events = EPOLLIN;
    my_event.data.fd = fd_listen;

    MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_listen, &my_event) == 0, "epoll ctl");

    while(1)
    {
        memset(my_evets, 0, sizeof(my_evets));
        ready_events = epoll_wait(epoll_fd, my_evets, 1024, -1);
        for(index = 0; index < ready_events; index ++)
        {
            if(my_evets[index].events & EPOLLIN && my_evets[index].data.fd == fd_listen)
            {
                fd_client = accept(my_evets[index].data.fd, NULL, NULL);
                printf("a client connect ! \n");

                memset(&my_event, 0, sizeof(my_event));
                my_event.events = EPOLLIN;
                my_event.data.fd = fd_client;

                MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_client, &my_event) == 0, "epoll ctl connect ");
            }else if(my_evets[index].events & EPOLLIN)
            {
                memset(buf, 0, 1024);
                if(recv(my_evets[index].data.fd, buf, 1024, 0) == 0)
                {
                    printf("a client exit ! \n ");
                    MY_ASSERT(epoll_ctl(epoll_fd, EPOLL_CTL_DEL, my_evets[index].data.fd, NULL) == 0, "epoll del");
                }else
                {
                    printf("from client : %s \n", buf);
                }
            }
        }
    }



}
