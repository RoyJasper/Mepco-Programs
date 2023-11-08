#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
  int d,m,vowels=0,i;
	char *p,s[20];
  d=shmget(IPC_PRIVATE,50*sizeof(char),IPC_CREAT|0766);
  p=(char *)shmat(d,NULL,0);
  if(d!=-1)
  {
    m=fork();
  if(m<0)
    printf("CREATION ERROR");
  else if(m==0)
  {
    int *n,b;
    printf("\nEnter The String  ");
		scanf("%s",s);
		for(i=0;s[i]!='\0';i++)
    {
			p[i]=s[i];
		}
  }
  else if(m>0)
  {
		int g;
		scanf("%d",&g);
		for(i=0;p[i]!='\0';i++)
		{
    	if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u')
     		vowels++;
		}
		printf("\nNo of vov are  %d",vowels);
  }
  }
}

