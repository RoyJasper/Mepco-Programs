#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
    int fd1,fd2;
    char ch;
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_RDWR);
    if(fd1==-1||fd2==-1)
        printf("\n Error");
    else if(argc==3)
    {
        while(read(fd1,&ch,1)>0)
        {
            write(fd2,&ch,1);
        }
    }
    else
        printf("\n Error");
    unlink(argv[1]);
    close(fd1);
    close(fd2);
    return 0;
}

