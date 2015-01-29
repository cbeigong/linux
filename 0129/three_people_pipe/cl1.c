#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
    int fd12, fd13, fd21,fd31;
    char buf[1024];
    int readn;
    fd12 = open("12", O_WRONLY);
    fd13 = open("13", O_WRONLY);
    fd21 = open("21", O_RDONLY);
    fd31 = open("31", O_RDONLY);
    printf("%d %d %d %d OK\n", fd12, fd13,fd21,fd31);
    while(1)
    {
        //zero indicates end of file
        memset(buf, 0, 1024);
        printf("enter: \n");
        readn = read(0, buf, 1023);
        if(readn == 0)
        {
            break;//文件读完了
        }
        write(fd12, buf, strlen(buf));
        write(fd13, buf, strlen(buf));
        printf("watint for 2!\n");
        memset(buf, 0, 1024);
        readn = read(fd21, buf, 1024);
        if(readn == 0)
        {
            printf("2 exit \n ");
        }
        printf("form 2: %s \n ", buf);

        //recv 2
        printf("waiting for 3! \n");
        memset(buf, 0, 1024);
        readn = read(fd31, buf, 1024);
        if(readn == 0)
        {
            printf("3 exit \n ");
        }
        printf("form 3: %s \n ", buf);


    }
    close (fd12);
    close (fd13);
    close (fd21);
    close (fd31);
    return 0;
}
