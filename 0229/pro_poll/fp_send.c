#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/socket.h>
void send_fd(int sockfd, int fd);
void recv_fd(int sockfd, int* fd);
int main(int argc, char* argv[])
{
    int fds[2];
    if(-1 == socketpair(AF_LOCAL, SOCK_STREAM, 0, fds))
    {
        perror("socketpair");
        exit(1);
    }
    printf("0: %d, 1: %d \n", fds[0], fds[1]);
    if(fork() == 0)
    {
       int fd, fd1;
       recv_fd(fds[1], &fd);
       char buf[1024] = "";
       printf("begin.. ]n");
       read(fd, buf, 1024);
       printf("end... \n");
       printf("from file: %s\n", buf);

       exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    printf("parent: fd: %d \n ", fd);
    send_fd(fds[0], fd);
    wait(NULL);
    return 0;
}
void send_fd(int sockfd, int fd)
{
    struct msghdr my_msg;
    struct iovec bufs[2];
    struct cmsghdr* pcmsg;
    int cmsglen = CMSG_LEN(sizeof(int));
    int val = 1024;
    char buf[] =  "hello world !";
    memset(&my_msg, 0, sizeof(my_msg));
    my_msg.msg_name = NULL;
    my_msg.msg_namelen = 0;
    bufs[0].iov_base = &val;
    bufs[0].iov_len = sizeof(val);
    bufs[1].iov_base = buf;
    bufs[1].iov_len = strlen(buf);

    my_msg.msg_iov = bufs;
    my_msg.msg_iovlen = 2;
    my_msg.msg_flags = 0;

    pcmsg = (struct cmsghdr*)calloc(1, sizeof(struct cmsghdr));
    pcmsg->cmsg_len = cmsglen;
    pcmsg->cmsg_level = SOL_SOCKET;
    pcmsg->cmsg_type =SCM_RIGHTS;
    *(int*)CMSG_DATA(pcmsg) = fd;

    my_msg.msg_control = pcmsg;
    my_msg.msg_controllen = cmsglen;

    sendmsg(sockfd, &my_msg, 0);
}

void recv_fd(int sockfd, int* fd)
{
    struct msghdr my_msg;
    struct iovec bufs[2];
    struct cmsghdr* pcmsg;
    int cmsglen = CMSG_LEN(sizeof(int));
    int val = 0;
    char buf[32] = "";
    memset(&my_msg, 0, sizeof(my_msg));
    my_msg.msg_name = NULL;
    my_msg.msg_namelen = 0;
    bufs[0].iov_base = &val;
    bufs[0].iov_len = sizeof(val);
    bufs[1].iov_base = buf;
    bufs[1].iov_len = 31;

    my_msg.msg_iov = bufs;
    my_msg.msg_iovlen = 2;
    my_msg.msg_flags = 0;

    pcmsg = (struct cmsghdr*)calloc(1, sizeof(struct cmsghdr));

    my_msg.msg_control = pcmsg;
    my_msg.msg_controllen = cmsglen;

    recvmsg(sockfd, &my_msg, 0);

    recvmsg(sockfd, &my_msg, 0);
    printf("val: %d, buf: %s \n", val, buf);

    *fd = *(int*)CMSG_DATA(pcmsg);
}
