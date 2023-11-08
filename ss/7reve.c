#include<stdio.h>
#include<stdlib.h>
main()
{
int n,i,*a;
printf("enter the number of elements:\n");
scanf("%d",&n);
a=(int *)malloc(n*sizeof(int));
printf("enter the elememts one by one");
for (i=0;i<n;i++)
scanf("%d",&a[i]);
for (i=n-1;i>=0;i--)
printf("%d\t",a[i]);
}

