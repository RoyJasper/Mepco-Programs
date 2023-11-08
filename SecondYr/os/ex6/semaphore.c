#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{
 int mutex,empty,full,n,d,f,a,in=-1,out=-1,*buff;
 printf("\n Enter size");
 scanf("%d",&n);
 d=shmget(IPC_PRIVATE,n*sizeof(int),IPC_CREAT|0766);
 buff=(int *)shmat(d,NULL,0);
 mutex=shmget(IPC_PRIVATE,1,IPC_CREAT|0766);
 semat(mutex,0,SETVAL,1);
 full=shmget(IPC_PRIVATE,1,IPC_CREAT|0766);
 semctl(full,0,SETVAL,0);
 empty=shmget(IPC_PRIVATE,1,IPC_CREAT|0766);
 semctl(empty,0,SETVAL,n);
 f=fork();
 if(f<0)
  {
   printf("Error"); 
   return 1;
  }
 else if(f==0)
  {
   wait(empty);
   printf("\n Enter value");
   scanf("%d",&a);
   wait(mutex);
   in=(in+1)%n;
   buff[in]=a;
   signal(mutex);
   signal(full);
  }
 else if(f>0)
  {
   wait(full);
   wait(mutex);
   out=(out+1)%n;
   a=buff[out];
   printf("\n Item value is %d",a);
   signal(mutex);
   signal(empty);
  }
}
void wait(int semid)
{
 struct sembuf sb;
 //sb.semnum=0;
 sb.sem_op=-1;
// sb.semflg=0;
 semop(semid,&sb,1);
}
void signal(int semid)
{
 struct sembuf sb;
 sb.sem_num=0;
 sb.sem_op=-1;
// sb.semflg=0;
// sb.semflg=0;
 semop(semid,&sb,1);
}
