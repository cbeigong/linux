#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
int main(int argc, char* argv[])
{
    int iret;
    char buf[1024] = "";
    int fd13 = open("13", O_RDONLY);
    int fd23 = open("23", O_RDONLY);
    int fd31 = open("31", O_WRONLY);
    int fd32 = open("32", O_WRONLY);
    printf("OK \n");
    fd_set read_sets;
    struct timeval tm;
//    char buf[128] = "";
    while(1)
    {
        tm.tv_sec = 1;
        tm.tv_usec = 0;
        FD_ZERO(&read_sets);
        FD_SET(fd13, &read_sets);
        FD_SET(fd23, &read_sets);

        iret = select(1024, &read_sets, NULL, NULL, &tm);
        if(iret == 0)
        {
            printf("no active ! \n");
        }
        {
            printf("active: %d \n", iret);
            if(FD_ISSET(fd13, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd13, buf, 1023);
                printf("from 1: %s \n ", buf);
            }
            if(FD_ISSET(fd23, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd23, buf, 1024);
                printf("from 2: %s \n ", buf);
            }
        }

        memset(buf, 0, 128);
        read(0, buf, 127);
        write(fd31,buf, strlen(buf));

       // memset(buf,0, 128);
       // read(0, buf, 127);
        write(fd32, buf, strlen(buf));


    }
     return 0;
}
