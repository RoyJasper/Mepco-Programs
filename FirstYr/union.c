#include<stdio.h>
void uni(int[],int[],int,int);
void inter(int[],int[],int,int);
void diff(int[],int[],int,int);
main()
{
 int a[50],b[50],m,n,i;
 printf("enter the array size of 1st set");
 scanf("%d",&m);
 printf("enter the array elements");
 for(i=0;i<m;i++)
 scanf("%d",&a[i]);
 printf("enter hte array size of 2nd set");
 scanf("%d",&n);
 printf("enter the array elements");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]);
 uni(a,b,m,n);
 inter(a,b,m,n);
 diff(a,b,m,n);
}
 void uni(int a[50],int b[50],int m,int n)
 {
  int i,j,flag;
  printf("union is ");
  for(i=0;i<m;i++)
  printf("%d ",a[i]);
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    if(b[i]!=a[j])
    flag=1;
    else
   {
    flag=0;
    break;
   }
  }
  if(flag==1)
  printf("%d ",b[i]);
  }
 }

 void inter(int a[50],int b[50],int m,int n)
 {
   int i,j;
  printf("\nintersection is ");
  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
   {
    if(a[i]==b[j])
    printf("%d ",a[i]);
   }
  }
 }
 void diff(int a[50],int b[50],int m,int n)
 {
  int i,j;
  printf("\ndifference is ");
  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
   {
    if(a[i]==b[j])
    a[i]=0;
   } 
  }
  for(i=0;i<m;i++)
  if(a[i]!=0)
  printf("%d ",a[i]);
 } 
 
 

