#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
 int d,*p,c,n;
 d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
 p=(int*)shmat(d,NULL,0);
 c=fork();
 if(c<0)
 printf("error in creation");
 else if(c==0)
 {
  printf("enter a number");
  scanf("%d",p);
 }
 else if(c>0)
 {
  getchar();
  if(*p%2==0)
  printf("even");
  else
  printf("odd");
 }
}
 

