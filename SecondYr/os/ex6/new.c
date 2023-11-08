#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
  int d,element[10],n,count=0,m,i,in=0,out=0;
  int *p,*q,*r,*s;
  d=shmget(IPC_PRIVATE,10*sizeof(int),IPC_CREAT|0766);
  p=(int *)shmat(d,NULL,0);
  d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
  q=(int *)shmat(d,NULL,0);
  for(i=0;i<10;i++)
  p[i]=element[i];
  if(d!=-1)
  {
    m=fork();
  if(m<0)
    printf("CREATION ERROR");
  else if(m==0)
  {
    int count=0,in=0,n;
    *q=count;
    while(1)
    {
      printf("%d",*q);
      while(*q==10);
      printf("\nENTER THE ELEMENT");
      scanf("%d",&n);
      p[in]=n;
      count=count+1;
      in=(in+1)%10;
      *q=count;

    }

  }
  else if(m>0)
  {
    int out=0,n;
    while(1)
    {
      getchar();
      printf("\t%d",*q);
      while(*q==0);
      n=*q;
      printf("\nTHE ELEMENT IS TAKEN %d",p[out]);
      n=n-1;
      out=(out+1)%10;
      *q=n;
      }
		}
	}
}
