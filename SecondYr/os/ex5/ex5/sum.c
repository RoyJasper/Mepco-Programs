#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
  int d,m,vowels=0,i,n,l;
  int *p,s[20],*q,*r;
	printf("ENTER THE SIZE OF ARRAY");
	scanf("%d",&n);
  d=shmget(IPC_PRIVATE,n*sizeof(int),IPC_CREAT|0766);
  p=(int *)shmat(d,NULL,0);
	d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
  q=(int *)shmat(d,NULL,0);
	r=(int *)shmat(d,NULL,0);
	if(d!=-1)
  {
    printf("ENTER THE ELEMENTS");
    for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
      p[i]=s[i];
    }
		*q=n;
		*r=n;
    m=fork();
		l=fork();
    if((m<0)||(l<0))
      printf("CREATION ERROR");
    else if((m==0)&&(l==0))
    {
      int n,b,g=0;
      for(i=(*q/2);i<*q;i++)
      {
        g=g+p[i];
      }
      printf("THE FIRST TOTAL IS %d",g);
    }
    else if((m==0)&&(l>0))
    {
      int h=0,j;
      for(j=0;j<*q/2;j++)
      {
        h=h+p[j];
      }
      printf("\nTHE SECOND TOTAL IS %d",h);
    }
		else if((m>0)&&(l>0))
		{
			int u=0,k;
			for(k=0;k<*q;k++)
      {
        u=u+p[k];
      }
			u=u/(*r);
      printf("\nTHE AVERAGE IS %d",u);
	 	}
	}
}


