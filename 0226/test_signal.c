#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void sig_handle(int num)
{
    printf("recv signal : %d\n", num);
    sleep(5);
}
int main(int argc, char* argv[])
{
    signal(2, sig_handle);
    while(1);
}
