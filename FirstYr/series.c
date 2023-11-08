#include<stdio.h>
main()
{
 int i,n,s=0;
 printf("Enter last term\n");
 scanf("%d",&n);
 printf("the sum of\n");
 for(i=1;i<=n;i++)
 {
  s=s+i;
  if(i<n)
   {
   printf("%d+",i);
   }
  else if (i==n)
  {
   printf("%d",i);
  }
 }
 printf("=%d",s);
 }

