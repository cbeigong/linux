#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd12, fd23, fd21, fd32;
    int readn;
    char buf[1024];
    fd12 = open("12", O_RDONLY);
    fd21 = open("21", O_WRONLY);
    fd23 = open("23", O_WRONLY);
    fd32 = open("32", O_RDONLY);
    while(1)
    {
        printf("wait for 1 ! \n");
        memset(buf, 0, 1024);
        readn = read(fd12, buf, 1024);
        if(readn == 0)
        {
            printf("1 exit \n");
        }
        printf("form1: %s \n ", buf);

        //send;
        memset(buf, 0, 1024);
        printf("please enter: \n ");
        readn = read(0, buf , 1024);//remember;
        if(readn == 0)
        {
            break;
        }
        write(fd21, buf, strlen(buf));
        write(fd23, buf, strlen(buf));

        printf("waint for 3: \n");
        memset(buf, 0, 1024);
        readn = read(fd32, buf, 1024);
        if(readn == 0)
        {
            printf("3 exits\n ");
        }
        printf("form 3 : %s \n", buf);
    }
    return 0;

}
