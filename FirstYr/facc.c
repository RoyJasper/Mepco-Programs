#include<stdio.h>
int fact(int);
main()
{
 int n,r;
 float a,b,c,d;
 printf("enter the values of n and r");
 scanf("%d%d",&n,&r);
 a=fact(n);
 b=fact(r);
 c=fact(n-r);
 d=(a/(b*c));
 printf("the result is %f",d);
}
int fact(int n)
{
 if((n==0)||(n==1))
 return 1;
 else
 return (n*fact(n-1));
} 
