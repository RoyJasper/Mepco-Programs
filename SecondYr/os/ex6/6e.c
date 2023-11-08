#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sem.h>
void wait(int);
void signal(int);
main()
{
int f,m,b,i;
int mutex,empty,full,n,in=-1,out=-1,shmid;
int a[5],*buffer,*p,id,sid,*g;
printf("\nEnter no of elements.. ");
scanf("%d",&p);
n=p;
mutex=shmget(IPC_PRIVATE,1,IPC_CREAT|0776);
semctl(mutex,0,SETVAL,1);
empty=shmget(IPC_PRIVATE,1,IPC_CREAT|0776);
semctl(empty,0,SETVAL,n);
full=shmget(IPC_PRIVATE,1,IPC_CREAT|0776);
semctl(full,0,SETVAL,1);
shmid=shmget(IPC_PRIVATE,n*sizeof(int),IPC_CREAT|0776);
buffer=(int *)shmat(shmid,NULL,0);
shmid=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0776);
p=(int *)shmat(id,NULL,0);
shmid=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0776);
p=(int *)shmat(sid,NULL,0);
m=fork();
if(m==0)
{
wait(empty);
printf("Enter the Values");
wait(mutex);
in=(in+p);
for(in=0;in<p;in++)
{
scanf("%d",&b);
buffer[in]=b;
}
signal(mutex);
signal(full);
}
else if(m>0)
{
getchar();
getchar();
wait(full);
wait(mutex);
out=(out+1);
f=buffer[out];
printf("Deleted Element is  %d ",f);
signal(mutex);
signal(empty);
}
else
exit(0);
}
void wait(int semid)
{
struct sembuf buf;
buf.sem_num=0;
buf.sem_op=-1;
buf.sem_flg=0;
semop(semid,&buf,1);
}
void signal(int semid)
{
struct sembuf buf;
buf.sem_num=0;
buf.sem_op=1;
buf.sem_flg=0;
semop(semid,&buf,1);
}

