#include<stdio.h>
#include<stdlib.h>
main()
{
int i,j,m,k,n,*p,*q,*r,t=0,c;
printf("Enter row and column for both matrix\n");
scanf("%d%d",&m,&n);
p=(int *)malloc(n*m*sizeof(int));
q=(int *)malloc(n*m*sizeof(int));
r=(int *)malloc(n*m*sizeof(int));
c=m*n;
printf("enter matrix A");
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
    {
     scanf("%d",((p+(i*n))+j));
     }
 }
printf("enter matrix B");
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
    {
     scanf("%d",((q+(i*n))+j));
     }

}
   for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
     {
       *((r+i)+j)=0;
        for(k=0;k<n;k++)
       {
        *((r+(i*n))+j)=(*((r+(i*n))+j)+(*((p+(i*n))+k))*(*((q+(i*n))+k)));
       }
      }
     }
printf("Resultant matrix is\n");
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
    {
    printf("\t%d",*((r+(i*n))+j));
    }
  printf("\n");
 }
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
   {
    if(i==j)
      {
       if((*(r+(i*n))+j)==1)
        {
         t=t+1;
        }
      }
     else
       {
        if((*(r+(i*n))+j)==0)
         {
          t=t+1;
         }
     
       }
    }
  }
if(c==t)
  printf("They are identity  matrix\n");
else
  printf("They are not identical matrix\n");
}
