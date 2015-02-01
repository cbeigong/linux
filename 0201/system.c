#include <stdlib.h>
#include <stdio.h>
/*
#include <stdlib.h>

 int system(const char *command);

*/
int main()
{
	printf("Running ps with system  \n");
	system("ps ax &");
	printf("Done \n");
	exit(0);
}