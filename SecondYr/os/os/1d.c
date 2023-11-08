#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char * argv[])
{
int fp1,fp2,fp3;
char ch;
switch(argc)
{
printf("%s",argv[1]);
case 2:
fp1=open(argv[1],O_RDONLY);
if(fp1==-1)
printf("\nUNABLE TO OPEN THE FILE");
else
{
while(read(fp1,&ch,1)>0)
{
printf("%c",ch);
}}
break;
case 3:
fp1=open(argv[1],O_WRONLY);
fp2=open(argv[3],O_RDONLY);
if(fp1==-1||fp2==-1)
printf("\nSuch File is not openable");
else
{
while(read(fp2,&ch,1)>0)
{
write(fp1,&ch,1);
}
printf("COPY IS DONE SUCESSFULLY");
}
break;
case 4:
fp1=open(argv[1],O_RDWR,00100);
fp2=open(argv[3],O_RDONLY);
if(fp1==-1||fp2==-1)
printf("\nSuch File is not openable");
else
while(read(fp1,&ch,1)>0)
while(read(fp2,&ch,1)>0)
{
write(fp1,&ch,1);
}
printf("APPEND IS DONE SUCCESSFULLY");
break;
}
close(fp1);
close(fp2);
return 0;
}
 
