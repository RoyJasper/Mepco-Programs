#include<stdio.h>
main()
{
 int a[20],b[20],*p,*q,i,j,m,n,flag;
 printf("enter the size of first array");
 scanf("%d",&m);
 printf("enter the array elements");
 for(i=0;i<m;i++)
 scanf("%d",&a[i]);
 printf("enter the size of second array");
 scanf("%d",&n);
 printf("enter the array elements");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]);
 p=a;
 q=b;
 for(i=0;i<m;i++)
 { 
  printf("%d ",*(p+i));
 }
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   if(*(q+i)!=*(p+j))
   {
    flag=1;
   }
   else
   {  
    flag=0;
    break;
   }
  }
  if(flag==1)
  printf("%d ",*(q+i));
 }
}
