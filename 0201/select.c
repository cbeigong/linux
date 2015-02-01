#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char buffer[128];
	int result , nread;
	fd_set inputs, testfds;
	struct timeval timeout;
	//下面的两个函数分别是 1： 把inputs 这个文件描述符的集合社会设置为空的集合
	//把文件描述的集合都设置为零。
	FD_ZERO(&inputs);
	FD_SET(0,&inputs);

	while(1)
	{
		testfds = inputs;
		timeout.tv_sec = 2;
		timeout.tv_usec = 500000;
		//其中fd_set 是由打开的文件描述符构成的集合。
		// int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
		// On success, select() and pselect() return the number of  file  descrip‐tors  contained  in  the  three  returned descriptor sets 
		//select 是用来测试文件描述符号又中是有文件处于可读， 可写， 或者是错误的状态。
		result = select(FD_SETSIZE, &testfds, (fd_set*)NULL, (fd_set*)NULL, &timeout);
		switch(result)
		{
			case 0:
			printf("timeout \n");
			break;
			case -1:
			perror("select");
			exit(1);

			default:
			if(FD_ISSET(0, &testfds))
			{
				ioctl(0, FIONREAD, &nread);
				if(nread == 0)
				{
					printf("keyboard done \n");
					exit(0);
				}
				nread = read(0, buffer, nread);
				buffer[nread] = 0;
				printf("read %d froom keyboard : %s", nread, buffer);
			
			}
		break;
	}

	}

	//return 0;

}
