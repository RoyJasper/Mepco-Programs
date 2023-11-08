#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
  int d,m;
  char *p;
  d=shmget(IPC_PRIVATE,sizeof(char),IPC_CREAT|0766);
  p=(char *)shmat(d,NULL,0);
  if(d!=-1)
  {
    m=fork();
    if(m<0)
      printf("ERROR");
    else if(m==0)
    {
      int i;
      char *n,b[10];
      printf("enter your string");
      scanf("%s",b);
      for(i=0;b[i]!='\0';i++)
        p[i]=b[i];
    }
    else if(m>0)
    {
      char g;
      int h,i,c=0;
      scanf("%c",&g);
      i=0;
      while(p[i]!='\0')
      {
        i++; c++;
      }
      for(i=c-1;i>=0;i--)
      {
        printf("%c",p[i]);
      }
    }
  }
}

