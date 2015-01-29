/*************************************************************************
	> File Name: user.c
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 15时38分48秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	uid_t uid;
	gid_t gid;
	
	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	printf("User is %s \n", getlogin());
	printf("User IDs: uid = %d, gid = %d\n", uid, gid);
	
	pw = getpwuid(uid);
	printf("UID passwd entry: \n name= %s, shell =%s ",pw->pw_name, pw->pw_shell);
	printf("root passwd entry:\n");
	printf("root passwd entry: \n name= %s, shell =%s ",pw->pw_name, pw->pw_shell);
	exit(0);
	


}

