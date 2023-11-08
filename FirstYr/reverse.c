
#include<stdio.h>
main()
{
int a[5],i,n;
printf("enter the size of array");
scanf("%d",&n);
printf("enter the nos");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("the reversed array is");
for(i=n-1;i>=0;i--)
printf("%d\n",a[i]);
}

