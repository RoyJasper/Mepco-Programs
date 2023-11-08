#include<stdio.h>
main()
{
int a[10],*p,i,n,sum=0;
printf("Enter no of times");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
  *p=a[i];
  sum=sum+*p;
 }
printf("The sum is %d",sum);
}














