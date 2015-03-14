#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/select.h>
#define MY_ASSERT(flag, msg) do {\
    (flag) || (printf("%s\n", msg), exit(1), 0); \
}while(0)
void setnonblock(int sfd);
void setblock(int sfd);
int recvtimeout(int sfd, void* buf, int len , int secs);
int main(int argc, char* argv[])
{
    int fd_listen, fd_client;
    char buf[1024];
    MY_ASSERT( (fd_listen = socket(AF_INET, SOCK_STREAM, 0)) != -1, "listen socket init");
    struct sockaddr_in seraddr;
    int recv_ret;
    memset(&seraddr, 0, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons( atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);
    MY_ASSERT(bind(fd_listen, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "bind");
    MY_ASSERT(listen(fd_listen, 10) == 0, "listen");
    fd_client = accept(fd_listen, NULL, NULL);
    while(1)
    {
        memset(buf, 0, 1024);
        printf("recv ^^^^^^! \n");
        recv_ret = recvtimeout(fd_client, buf, 1024, 5);
        if(recv_ret == -1 && errno == EAGAIN)
        {
            continue;
        }else if(recv_ret > 0)
        {
            puts(buf);
        }else if(recv_ret == 0)
        {
            printf("client close ! \n");
            break;
        }

    }
    return 0;

}
void setnonblock(int sfd)
{
    int old_flag;
    old_flag = fcntl(sfd, F_GETFL);
    old_flag = old_flag | O_NONBLOCK;
    //old_flag &= ~O_NONBLOCK;
    fcntl(sfd, F_SETFL, old_flag);
}
void setblock(int sfd)
{
    int old_flag;
    old_flag = fcntl(sfd, F_GETFL);

    old_flag &= ~O_NONBLOCK;
    fcntl(sfd,F_SETFL, old_flag);
}

int recvtimeout(int sfd, void* buf, int len, int secs)
{
    fd_set rdsets;
    int ret;
    struct timespec tm;
    FD_ZERO(&rdsets);
    FD_SET(sfd, &rdsets);

    tm.tv_sec = secs;
    tm.tv_nsec = 0;

    ret = pselect(sfd + 1, &rdsets, NULL, NULL, &tm, NULL);
    if(ret == 0)
    {
        printf("time out ! \n ");
        errno = EAGAIN;
        return -1;
    }else if(ret == -1)
    {
        printf("error ! n");
    }else
    {
        return recv(sfd, buf, len, 0);

    }
}
