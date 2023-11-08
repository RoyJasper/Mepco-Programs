#include<stdio.h>
main()
{
 int a,z,b,*p,*q;
 printf("enter two numbers");
 scanf("%d%d",&a,&b);
 p=&a;
 q=&b;
 z=*p;
 *p=*q;
 *q=z;
 printf("the values are %d and %d",*p,*q);
}
