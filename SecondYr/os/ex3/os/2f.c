#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int l,a[2],p,fp1,ln=1,wr=0,vw=0,ca=0;
char ch;
p=pipe(a);
l=fork();
if(l==-1)
{
printf("ERROR IN PROCESSOR CREATION");
exit(0);
}
else if(l==0)
{
fp1=open("read.txt",O_RDONLY);
if(fp1==-1)
{
printf("FILE OPENING IS TEDIOUS");
exit(0);
}
else
{
while(read(fp1,&ch,1)>0)
{
if(ch==' ')
{
wr=wr+1;
}
if(ch=='\n')
{
ln=ln+1;
}
if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
{
vw++;
}
ca++;
}
close(a[0]);
write(a[1],&wr,sizeof(wr));
write(a[1],&ln,sizeof(ln));
write(a[1],&vw,sizeof(vw));
write(a[1],&ca,sizeof(ca));
}
}
else
{
close(a[1]);
read(a[0],&wr,sizeof(wr));
printf("\nTHE NUMBER OF WORDS ARE %d",wr);
read(a[0],&ln,sizeof(ln));
printf("\nTHE NUMBER OF LINES ARE %d",ln);
read(a[0],&vw,sizeof(vw));
printf("\nTHE NUMBER OF VOWELS ARE %d",vw);
read(a[0],&ca,sizeof(ca));
printf("\nTHE NUMBER OF CHARACTERS ARE %d",ca);
return 0;
}
}

