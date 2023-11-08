#include<stdio.h>
#include<stdlib.h>
main()
{
 int *a,*b,*c,i,j,k,n,d,e=0;
 printf("enter the order");
 scanf("%d",&n);
 a=(int *) malloc(n*n*sizeof(int));
 b=(int *) malloc(n*n*sizeof(int));
 c=(int *) malloc(n*n*sizeof(int));
 printf("enter first matrix");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",((a+(i*n))+j));
  }
 }
 printf("enter the second matrix");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",((b+(i*n))+j));
  }
 } 
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   *((c+(i*n))+j)=0;
   for(k=0;k<n;k++)
   {
    *((c+(i*n))+j)=(*((c+(i*n))+j)+(*((a+(i*n))+k)) * (*((b+(k*n))+j)));
   }
  }
 }
  for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if((*((c+(i*n))+j))==0||((*((c+(i*n))+j)))==1)
   e=e+1;
  }
 }
 d=n*n;
 if(d==e)
 printf("it is a identity matrix");
 else
 printf("it is not an identity matrix");
}


   


  





