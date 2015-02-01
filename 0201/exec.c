#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Runjing ps with exelp \n");
	execlp("ps", "ps", "ax", NULL);
	printf("Done");
	exit(0);
}