#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/select.h>
#include <stdlib.h>

int main(int argc , char* argv[])
{
    int fd21, fd31, fd12, fd13;
    int iret;
    char buf[1024];
    fd12 = open("12", O_WRONLY);
    fd13 = open("13", O_WRONLY);
    fd21 = open("21", O_RDONLY);
    fd31 = open("31", O_RDONLY);
    fd_set read_sets;
    struct timeval tm;

    while(1)
    {
        memset(buf, 0, 1024);
        read(0, buf, 1023);
        write(fd12, buf, strlen(buf));

        memset(buf, 0, 1024);
        read(0, buf, 1023);
        write(fd13, buf, strlen(buf));

        tm.tv_sec = 1;
        tm.tv_usec = 0;
        FD_ZERO(&read_sets);
        FD_SET(fd21, &read_sets);
        FD_SET(fd31, &read_sets);

        iret = select(1024, &read_sets, NULL, NULL, &tm);
        if(iret == 0)
        {
            printf("no active ! \n");
        }
        else
        {
            printf("active : %d \n", iret);
            if(FD_ISSET(fd21, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd21, buf, 1023);
                printf("from 2: %s \n", buf);
            }
            if(FD_ISSET(fd31, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd31, buf, 1023);
                printf("from 3: %s \n", buf);
            }

        }
    }
    return 0;

}
