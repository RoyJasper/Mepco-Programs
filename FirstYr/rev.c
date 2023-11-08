#include<stdio.h>
main()
{
 int a[20],n,i;
 printf("enter the size of array");
 scanf("%d",&n);
 printf("enter the number");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("the reversed array is");
 for(i=n-1;i>=0;i--)
 printf("\n%d",a[i]);
}
