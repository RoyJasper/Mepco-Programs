#include<stdio.h>
main()
{
 int s,a[20],n,i,flag=0,c=0;
 printf("enter the size of array");
 scanf("%d",&n);
 printf("enter the number");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter the specified number");
 scanf("%d",&s);
 for(i=0;i<n;i++)
 {
  if(a[i]==s)
  {
   printf("\nthe element is present",s);
   printf("\nthe position is %d",i+1);
   flag=1;
   c=c+1;
  }
 }
 printf("\nthe occurence is %d",c);
 if(flag=0)
 printf("the element is not present");
} 

