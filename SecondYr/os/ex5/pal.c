#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
  int *a,s=0,i,q,r,b,d,k,temp,qw;
 
  
 d=shmget(IPC_PRIVATE,sizeof(int),0766|IPC_CREAT);
 
 a=(int *)shmat(d,NULL,0);
 k=fork(); 
if(k==0)
  {
  printf("\n Enter a no: ");
  scanf("%d",a);
  }
 else if(k>0)
  {
   getchar();
   temp=*a;
   while(*a!=0) 
    {
     q=*a/10;
     r=*a%10;
     s=(s*10)+r;
     *a=q;
    }
    if(s==temp)
     printf("\n Palindrome");
    else
     printf("\n Not palindrome ");
  }
  else
   {
    printf("\nError");
    return 1;
   }
}
