#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
    char buf[1024];
    int fd13, fd23, fd31, fd32;
    int readn;
    fd13 = open("13", O_RDONLY);
    fd23 = open("23", O_RDONLY);
    fd31 = open("31", O_WRONLY);
    fd32 = open("32", O_WRONLY);
    printf("%d %d %d %d \n" , fd13, fd23, fd31, fd32);
    while(1)
    {
        printf("wait 1: \n");
        memset(buf,0, 1024);
        readn = read(fd13, buf, 1024);
        if(readn == 0)
        {
            printf("1 exit \n");
        }
        printf("1 form: %s \n", buf);

        printf("wait 2:\n");
        memset(buf, 0, 1024);
        readn = read(fd23, buf, 1024);
        if(readn == 0)
        {
            printf("2 exits");
        }
        printf("form 2: %s \n", buf);
        //send
        memset(buf, 0, 1024);
        printf("please enter :\n");
        readn = read(0, buf, 1024);
        if(readn == 0)
        {
            break;
        }
        write(fd31, buf, strlen(buf));
        write(fd32, buf, strlen(buf));

    }
    return 0;
}
