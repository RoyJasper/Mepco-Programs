#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
 int fp;
 char ch;
 fp=open(argv[1],O_RDONLY);
 if(fp==-1)
   printf("\n Error");
 else
  {
 //  read(fp,&ch,1);
 //  while(ch!=EOF)
  while(read(fp,&ch,1)>0)
   {
    printf("%c",ch);
    read(fp,&ch,1);
   }
  }
 close(fp);
}
