#include<stdio.h>
main()
{
int f[50],b[50],m,n,i,j,flag=0,*p,*q;
printf("enter the size of array A");
scanf("%d",&m);
printf("enter the size of array B");
scanf("%d",&n);
printf("enter the element of array A");
for(i=0;i<m;i++)
scanf("%d",&f[i]);
printf("enter the element of array B");
for(j=0;j<n;j++)
scanf("%d",&b[j]);
p=f;
q=b;
printf("the combination of the two array elements are");
while(*p!='\0')
{
printf("\t%d\t",*p);
p++;
}
for(i=0;i<m;i++)
{
for( j=0;j<n;j++)
{
if(*(b+1)!=*(f+1))
{
flag=1;
}
else
{
flag=0;
break;}
}}
if(flag==1)
{
printf("%d",*(b+1));
printf("\t");
}
}

