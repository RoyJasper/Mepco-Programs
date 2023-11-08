#include<stdlib.h>>
#include<stdio.h>
main()
{
int n,k[20],*a[20],i,j,c,low,up,mid,s;
printf("enter the size");
scanf("%d",&n);
*a=(int *)malloc(n*sizeof(int));
printf("enter the value of array");
for(i=0;i<n;i++)
{
 scanf("%d",&k[i]);
 a[i]=&k[i];
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(*a[i]>*a[j])
{
c=*a[i];
*a[i]=*a[j];
*a[j]=c;
}
}
}
printf("enter key value");
scanf("%d",&s);
low=0;
up=n-1;
while(low<=up)
{
mid=(low+up)/2;
if(*a[mid]==s)
{
 printf("%d element is present at place %d",s,mid+1);
 break;
}
else if(s<*a[mid])
up=mid-1;
else
low=mid+1;
}
}

