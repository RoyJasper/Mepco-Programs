#include<stdio.h>
main()
{
int a[20][20],b[20][20],c[20][20],i,j,m,p,q,k,n;
printf("Enter row and column for matrix A");
scanf("%d%d",&m,&n);
printf("Enter row and column for matrix B");
scanf("%d%d",&p,&q);
if(n!=p)
 printf("matrix multiplication is not possible");
else
{
printf("enter matrix A");
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
    {
     scanf("%d",&a[i][j]);
     }
 }
printf("enter matrix B");
for(i=0;i<p;i++)
 {
  for(j=0;j<q;j++)
    {
     scanf("%d",&b[i][j]);
     }
    
}
   for(i=0;i<m;i++)
    {
      for(j=0;j<q;j++)
     {
       c[i][j]=0;
        for(k=0;k<n;k++)
       {
         c[i][j]=c[i][j]+a[i][k]*b[k][j];
       }
      }
     }         
printf("Resultant matrix is\n");
for(i=0;i<m;i++)
 {
  for(j=0;j<q;j++)
    {
    printf("\t%d",c[i][j]);
    }
  printf("\n");
 } 
}
}
