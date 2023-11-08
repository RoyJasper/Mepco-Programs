#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
    int fd1,fd2;
    char ch;
    switch(argc)
    {
    case 2:
        fd1=open(argv[1],O_RDONLY);
        if(fd1==-1)
            printf("\n Error in opening ");
        else
        {
            while(read(fd1,&ch,1)>0)
            {
                printf("%c",ch);
            }
        }
        close(fd1);
        return 0;
    case 3:
        if(argv[2]=='>')
        {
            fd1=open(argv[1],O_RDONLY);
            fd2=open(argv[3],O_RDWR);
            if(fd1==-1||fd2==-1)
                printf("\n Error in opening ");
            else
            {
                while(read(fd1,&ch,1)>0)
                {
                    write(fd2,&ch,1);
                }
                close(fd1);
                close(fd2);
            }
        }
        else if(strcmp(argv[2],">>")==0)
        {
            fd1=open(argv[1],O_RDONLY);
            fd2=open(argv[3],O_APPEND);
            if(fd1==-1||fd2==-1)
                printf("\n Error in opening ");
            else
            {
                while(read(fd1,&ch,1)>0)
                {
                    write(fd2,&ch,1);
                }
                close(fd1);
                close(fd2);
            }
        }
        else
            printf("\n Enter correct symbol");
    default:
        printf("\nError.....");
    }
    return 0;
}
