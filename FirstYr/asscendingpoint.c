#include<stdio.h>
main()
{
int n,*p[10],a[10],i,j,t;
printf("Enter number of numbers");
scanf("%d",&n);
printf("Enter %d numbers",n);
for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 p[i]=&a[i];
 }
for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(*p[i]>*p[j])
    {
     t=*p[i];
     *p[i]=*p[j];
     *p[j]=t;
    }
  }
 }
for(i=0;i<n;i++)
 {
  printf("asscending order is\t%d",*p[i]);
 }
for(i=n-1;i>0;i++)
 {
  printf("decending order is\t%d",*p[i]);
 }
} 

 


