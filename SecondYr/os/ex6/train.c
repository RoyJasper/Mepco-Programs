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
int m,b;
int mutex,shmid;
int a[5],*buffer;
mutex=shmget(IPC_PRIVATE,1,IPC_CREAT|0776);
semctl(mutex,0,SETVAL,1);
shmid=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0776);
buffer=(int *)shmat(shmid,NULL,0);
m=fork();
if(m==0)
{
wait(mutex);
printf("\nTrain is on the Platform");
signal(mutex);
}
else if(m>0)
{
wait(mutex);
printf("\nPlatform is Free");
signal(mutex);
}}
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

