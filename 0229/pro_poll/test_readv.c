#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_WRONLY | O_TRUNC);
    char buf1[10] = "", buf2[10] = "";
    strcpy(buf1, "12345");
    strcpy(buf2, "abcdef");

    struct iovec bufs[2];
    bufs[0].iov_base = buf1;
    bufs[0].iov_len = strlen(buf1);

    bufs[1].iov_base = buf2;
    bufs[1].iov_len = strlen(buf2);
    writev(fd, bufs, 2);
    printf("buf1: %s\n buf2: %s\n",buf1, buf2);

    return 0;
}
