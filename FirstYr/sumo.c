#include<stdio.h>
main()
{
 int a[20],*p[20],i,n,sum=0;
 printf("enter the number");
 scanf("%d",&n);
 printf("enter the array elements");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
  p[i]=&a[i];
 }
 for(i=0;i<n;i++)
 {
  sum=sum+*p[i];
 }
 printf("the sum is %d",sum);
}
