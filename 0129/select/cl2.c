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
    int fd21 = open(argv[1], O_WRONLY);
    printf("OK \n");
    char buf[128] = "";
    while(1)
    {
        memset(buf, 0, 128);
        read(0, buf, 127);
        write(fd21,buf, strlen(buf));
    }
    return 0;
}
