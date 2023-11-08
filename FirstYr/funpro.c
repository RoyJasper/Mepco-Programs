#include<stdio.h>
int pro(int);
main()
{
int n,s;
printf("enter a number");
scanf("%d",&n);
s=pro(n);
printf("product of digits is %d",s);
}
int pro(int n)
{
int q,r;
static int s=1;
  if(n!=0)
  {
   q=n/10;
   r=n%10;
   s=s*r;
   n=q;
   pro(n);
   }
return s;
}
