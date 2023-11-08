#include<stdio.h>
#include<stdlib.h>
main()
{
 int **a,**b,c[10][10],n,i,j,h,e,m;
 printf("\nEnter the size of matrix");
 scanf("%d",&n);
 a=(int **)malloc(n*sizeof(int*));
 printf("Enter 1st matrix\n");
 for(i=0;i<n;i++)
  {
   a[i]=(int *)malloc(n*sizeof(int));
   for(j=0;j<n;j++)
   {
    scanf("%d",&a[i][j]);
  }
 }
 b=(int **)malloc(n*sizeof(int*));
 printf("\nEnter 2nd Matrix\n");
 for(i=0;i<n;i++)
  {
   b[i]=(int *)malloc(n*sizeof(int));
   for(j=0;j<n;j++)
    {
     scanf(" %d",&b[i][j]);
    }
  }
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   {
    c[i][j]=0;
    for(h=0;h<n;h++)
     {
      c[i][j]=c[i][j]+a[i][h]*b[h][j];
     }
   }
 }
printf("\n");
for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d\t",c[i][j]); 
   if(c[i][j]==0||c[i][i]==1)
   e=e+1;
  }
   printf("\n");
 }
 m=n*n;
 if(e==m)
 {
 printf("A Is inverse of B");
 }
else
printf("A Is not inverse of B");
}
