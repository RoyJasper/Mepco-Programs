#include<stdio.h>
int product(int);
main()
{
 int n,a;
 printf("enter the number");
 scanf("%d",&n);
 a=product(n);
 printf("the product of digits is %d",a);
}
int product (int n)
{
 static int s=1;
 int q,r;
 if(n!=0)
 {
  q=n/10;
  r=n%10;
  s=s*r;
  product(q);
 }
 return s;
}
