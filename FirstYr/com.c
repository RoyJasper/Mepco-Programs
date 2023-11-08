#include<stdio.h>
int com(int,int);
int com1(int,int);
main()
{
 int a,b,c,d,x,y;
 printf("enter the real and imaginary part of first complex number");
 scanf("%d%d",&a,&b);
 printf("enter the real and imaginary part of second complex number");
 scanf("%d%d",&c,&d);
 x=com(a,c);
 y=com1(b,d);
 printf("sum is %d+%di",x,y);
}
int com(int a,int c)
{
 int s;
 s=a+c;
 return s;
}
int com1(int b, int d)
{
 int r;
 r=b+d;
 return r;
}
