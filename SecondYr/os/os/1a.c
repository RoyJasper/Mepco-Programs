#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main(int argc,char * argv[])
{
int i,fp;
char ch;
fp=open(argv[1],O_RDONLY);
if(fp==-1)
printf("\nSUCH FILE IS NOT EXISTS");
else
{
while((read(fp,&ch,1))>0)
{
printf("%c",ch);
}}
close(fp);
return 0;
}
