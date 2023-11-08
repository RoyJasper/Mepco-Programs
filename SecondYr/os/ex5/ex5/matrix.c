#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
  int d,m,vowels=0,i;
  int *p,s[20];
  d=shmget(IPC_PRIVATE,16*sizeof(char),IPC_CREAT|0766);
  p=(int *)shmat(d,NULL,0);
  if(d!=-1)
  {
		printf("\n Enter 4X4 Matrix \n");
		for(i=0;i<16;i++)
    {
			scanf("%d",&s[i]);
      p[i]=s[i];
    }
		m=fork();
  	if(m<0)
    	printf("CREATION ERROR");
  	else if(m==0)
  	{
    	int *n,b,g=0;
    	for(i=0;i<8;i++)
    	{
      	g=g+p[i];
    	}
			printf("\nThe first 4 row total is  %d",g);
  	}
  	else if(m>0)
  	{
    	int h=0,j;
    	for(j=8;j<16;j++)
    	{
      	h=h+p[j];
    	}
    	printf("\nThe second 4 row total is  %d",h);
  	}
  }
}


