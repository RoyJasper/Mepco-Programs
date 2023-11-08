#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define BUFFER_SIZE 10
main()
{
int *count,*buffer,d,e,m,in=0,out=0,nxtpro,nxtcon;
d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
e=shmget(IPC_PRIVATE,sizeof(int)*BUFFER_SIZE,IPC_CREAT|0766);
count=(int *)shmat(d,NULL,0);
buffer=(int *)shmat(e,NULL,0);
m=fork();
if(m==0)
{
while(1)
{
while(count==0);
nxtcon=buffer[out];
printf("\n%d",nxtcon);
count=count-1;
out=(out+1)%BUFFER_SIZE;
}
}
if(m>0)
{
while(1)
{
while(count==BUFFER_SIZE);
printf("\nEnter the number");
scanf("%d",&nxtpro);
buffer[in]=nxtpro;
count=count+1;
in=(in+1)%BUFFER_SIZE;
}
}
}
