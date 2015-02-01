#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_fuction(void *arg);
char message[] = "Hello World ";

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	res = pthread_create(&a_thread, NULL, thread_fuction, (void*)message);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Watint thread to finish .. \n");

	res = pthread_join(a_thread, &thread_result);
	//成的的时候返回的是0
	if(res != 0)
	{
		perror("Thread joined failed ");
		exit(EXIT_FAILURE);
	}
	printf("thread joined , it returned %s \n ", (char*)thread_result);
	printf("message is now %s \n", message);
	exit(EXIT_SUCCESS);
}

void* thread_fuction(void *arg)
{
	printf("thread_fuction is running , Argumeng was %s \n", (char*)arg);
	sleep(3);
	strcpy(message, "BYE !");
	pthread_exit("Thank you for you CPU time ");
}
