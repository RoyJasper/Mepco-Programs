#include<stdio.h>
main()
{
 int p,q,m,n,i,j,a[20][20],b[20][20],c[20][20],k;
 printf("enter the row sizo of a");
 scanf("%d",&m);
 printf("enter the column sizo of a");
 scanf("%d",&n);
 printf("enter the values of a");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  scanf("%d",&a[i][j]);
 }
 printf("enter the row size of b");
 scanf("%d",&p);
 printf("enter the column size of b");
 scanf("%d",&q);
 printf("enter the values of b");
 for(i=0;i<p;i++)
 {
  for(j=0;j<q;j++)
  scanf("%d",&b[i][j]);
 }
 if(n!=p)
 printf("matrix multiplication is not possible");
 else
 {
  for(i=0;i<m;i++)
  {
   for(j=0;j<q;j++)
   {
    c[i][j]=0;
    for(k=0;k<n;k++)
     c[i][j]=c[i][j]+a[i][k]*b[k][j]; 
   }
  } 
  printf("resultant matrix\n");
  for(i=0;i<m;i++)
  {
  for(j=0;j<q;j++)
   printf("%d ",c[i][j]);
   printf("\n");
  }
 }
}   
   

