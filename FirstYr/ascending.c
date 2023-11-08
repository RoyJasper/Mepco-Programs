#include<stdio.h>

main()
{
int i,a[10],n,c,j;
printf("enter the no  of times");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
 printf("enter number");
 scanf("%d",&a[i]);
 }
  for(i=0;i<n;i++)
  { 
   for(j=i+1;j<n;j++)
   { 
    if(a[i]>a[j])
     { 
      c=a[i];
      a[i]=a[j];
      a[j]=c;
     }    
   }
  }
printf("the sorted array is ");
for(i=0;i<n;i++)
printf("\n %d",a[i]);
printf("decending order is");
for(i=n-1;i>=0;i--)
printf("\n %d",a[i]);

}









