#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int fds[2]; //0_r 1_w
    pipe(fds);
    if(fork() == 0)
    {
        int fd_recv;
        char buf[1024] = "";
        close(fds[1]);
        read(fds[0], &fd_recv, 4);
        if(-1 == read(fd_recv,buf, 1024))
        {
            printf("child read error! \n");
        }else
        {
            printf("read form file: %s \n",buf);
        }
        exit(1);

    }
    close(fds[0]);
    int fd = open(argv[1], O_RDONLY);
    write(fds[1], &fd, 4);

    printf("paretn:file_fd: %d \n", fd);

    wait(NULL);
    return 0;
}
