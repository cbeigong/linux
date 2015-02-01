#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc , char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    char buf[1024];
    while(memset(buf, 0, 1024), fgets(buf,1024, fp));
    {
        puts(buf);
    }
    fclose(fp);
}
