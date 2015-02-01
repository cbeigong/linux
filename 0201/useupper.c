#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char* filename;
	if(argc != 2)
	{
		fprintf(stderr, "could not redirect stdin from file %s \n ", filename);
		exit(1);
	}
    filename = argv[1];
	if(!freopen(filename, "r", stdin))
	{
		//将filename 和 stdin 联系起来， 让filename的内容那个 变为stdin的输入、
		fprintf(stderr,"could not redirect stdin from file %s \n ", filename);
		exit(2);
	}
	//第一个位置是path
	/*extern char **environ;

       int execl(const char *path, const char *arg, ...);
       int execlp(const char *file, const char *arg, ...);
       int execle(const char *path, const char *arg,
                  ..., char * const envp[]);
       int execv(const char *path, char *const argv[]);
       int execvp(const char *file, char *const argv[]);
       int execvpe(const char *file, char *const argv[],
                   char *const envp[]);*/

	execl("./upper","upper", NULL);
	perror("couldn't exec upper");
	exit(3);

}
