#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
 int d,*a,k,n,r,q,b,s=0;
 d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
 a=(int*)shmat(d,NULL,0);
 k=fork();
 if(k==0)
 {
  printf("enter a number");
  scanf("%d",a);
 }
 else if(k>0)
 {
  getchar();
  b=*a;
  while(*a!=0)
  {
   q=*a/10;
   r=*a%10;
   s=(s*10)+r;
   *a=q;
  } 
 if(s==b)
 printf("It is palindrome");
 else
 printf("It is not palindrome");
 }
}
