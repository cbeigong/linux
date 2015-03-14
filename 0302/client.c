#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define MY_ASSERT(flag, msg)  do {\
					(flag) || (printf("%s\n",msg ) , exit(1) , 0  ) ;\
				}while(0)
int main(int argc, char* argv[])// ip port
{
	int  fd_client ;
	MY_ASSERT( (fd_client = socket(AF_INET, SOCK_STREAM, 0)) != -1, "client socket init" );
	struct sockaddr_in seraddr ;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons( atoi(argv[2]) );
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	MY_ASSERT(connect(fd_client, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "connect");
	char buf[1024] ;
	while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
	{
        if(strncmp(buf,"help",4) == 0)
        {
            printf("The FTP offer six choice: \n");
            printf("\n1:  help \n");
            printf("\n2:  ls \n");
            printf("\n3:  cd \n");
            printf("\n4:  pwd \n");
            printf("\n5:  gets \n");
            printf("\n6:  puts \n");
            printf("\n7:  send \n");
        }
        else if(strncmp(buf, "ls", 2) == 0)
        {
            send(fd_client, buf,strlen(buf), 0);
            memset(buf, 0, sizeof(buf));
            recv(fd_client, buf, sizeof(buf), 0);
            printf("%s\n", buf);

        }
        else if(strncmp(buf, "pwd",  3) == 0)
        {

        }
        else if(strncmp(buf,"cd",2) == 0)
        {

        }
        else if(strncmp(buf, "puts", 4) == 0)
        {

        }
        else if(strncmp(buf, "gets", 4) == 0)
        {

        }
        else if(strncmp(buf, "send", 4) == 0)
        {
		    printf(  "sendn: %d\n",send(fd_client, buf, strlen(buf), 0) );
        }
        else
        {
            printf("error input command , enter again \n");
        }
	}

	return 0 ;
}
