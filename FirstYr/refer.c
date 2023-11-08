#include<stdio.h>
main()
{
 int s=0,p=0,i,a[20],n;
 printf("enter the size of array");
 scanf("%d",&n);
 printf("enter the number");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 {
  if(a[i]%2==0)
  s=s+a[i];
  else
  p=p+a[i];
 }
 printf("the sum of even elements is %d",s);
 printf("\nthe sum of odd elements is %d",p);
}

