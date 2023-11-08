#include<stdio.h>
main()
{
int a[5],i,n,flag=0,s,c=0;
printf("enter the size of array");
scanf("%d",&n);
printf("enter the number");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the search elament");
scanf("%d",&s);
for(i=0;i<n;i++)
{
if(a[i]==s)
{
printf("the element is present in %d position\n",i+1);
flag=1;
c=c+1;
}
}
printf("\noccurence is%d",c);
if(flag==0)
printf("no such elament is present");
}

