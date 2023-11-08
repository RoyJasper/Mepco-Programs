#include<stdio.h>
main()
{
int i,a[20],n,s=0,c=0;
printf("enter size of array");
scanf("%d",&n);
printf("enter elements of array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
if(a[i]%2==0)
s=s+a[i];
else
c=c+a[i];
}
printf("sum of even nos is %d\n",s);
printf("sum of odd nos is %d",c);
}





