#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main(int argc,char * argv[])
{
int fp1,fp2;
char ch;
fp1=open(argv[1],O_WRONLY);
fp2=open(argv[2],O_RDONLY);
if(fp1==-1||fp2==-1)
printf("\nSUCH FILE IS NOT EXISTS");
else
{
while(read(fp2,&ch,1)>0)
{
write(fp1,&ch,1);
}
printf("COPY PROCESS IS DONE SUCCESSFUL");
}
close(fp1);
close(fp2);
return 0;
}




