#include <stdio.h>
#include <unistd.h>

int main()
{
    fork() || fork();//parent return 1  second fork not exec, child return 0;
    //so child exec the second fork()  so "hello" printf three times;
    printf("/n hello");
}
