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
    char buf[1024];
    int fd12 = open("12", O_RDONLY);
    int fd21 = open("21", O_WRONLY);
    int fd23 = open("23", O_WRONLY);
    int fd32 = open("32", O_RDONLY);
    printf("OK \n");
    fd_set read_sets;
    struct timeval tm;
    while(1)
    {
        tm.tv_sec = 1;
        tm.tv_usec = 0;
        FD_ZERO(&read_sets);
        FD_SET(fd12, &read_sets);
        FD_SET(fd32, &read_sets);

        iret = select(1024, &read_sets, NULL, NULL, &tm);
        if(iret == 0)
        {
            printf("no active ! \n");
        }
        else
        {
            printf("active : %d \n", iret);
            if(FD_ISSET(fd12, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd12, buf, 1023);
                printf("from 1: %s \n ", buf);
            }
            memset(buf, 0, 1024);
            read(0, buf, 1023);
             write(fd21,buf, strlen(buf));

           // memset(buf, 0, 1024);
          //  read(0, buf, 1023);
            write(fd23, buf, strlen(buf));
            if(FD_ISSET(fd32, &read_sets))
            {
                memset(buf, 0, 1024);
                read(fd32, buf, 1023);
                printf("from 3: %s \n", buf);
            }
        }

    }


    //printf("OK \n");
 //   char buf[128] = "";
  /*  while(1)
    {
        memset(buf, 0, 1024);
        read(0, buf, 1023);
        write(fd21,buf, strlen(buf));
    }
    */
    return 0;
}
