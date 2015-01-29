#include <stdio.h>
int main(int argc, char* argv[])
{
    FILE* fp = popen("cat ./test.txt", "r");
    char buf[1024];
     while(fgets(buf, sizeof(buf), fp))
     {
         puts(buf);
     }
    pclose(fp);
    return 0;
}
