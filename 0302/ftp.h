#ifndef  __FTP__
#define __FTP__
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
int gets(int sck, char* pDownloaDFileName);
int puts(int sck, char* pUploadFilName);
#define SER_IP "192.168.1.55"
#define SER_PORT 1234
int send_Buf(int sfd, char* buf, int len);
int recv_buf(int sfd, char* buf, int len);
void child_main(int fd_clientaA);
void child_handle(int signum);

#endif

