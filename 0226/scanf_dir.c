#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
void scanf_dir(char* dir, int num);
int main(int argc, char* argv[])
{

    scanf_dir(argv[1], 1);
    return 0;
}

void scanf_dir(char* dir, int num)
{
    char name[128] = "";
    DIR* pdir = opendir(dir);
    if(pdir == NULL)
    {
        perror("OPENDIR");
        exit(1);
    }
    struct dirent* pent;
    struct stat mystat;
    while((pent = readdir(pdir)) != NULL)
    {
       if( strcmp(".", pent->d_name) == 0 || \
            //. and .. won't be open, just scan the preset dir;
               //readdir return the dirent structure;
               strcmp("..",pent->d_name) == 0)
       {
           continue;
       }
       memset(name,0, 128);
       sprintf(name, "%s/%s", dir,pent->d_name);
       memset(&mystat,0, sizeof(mystat));

       if(lstat(name, &mystat) == -1)//give the value to mystat;
       {
            perror("lstat");
            exit(1);
       }
       if(S_ISDIR(mystat.st_mode))
       {
           scanf_dir(name, num + 5);//if name is dir dfs.
       }
       else
       {
           printf("%*s%s\n", num, " ", pent->d_name);
       }
    }
    closedir(pdir);

}
