#include<stdio.h>
#include<math.h>
main()
{
 int a,b,c;
 float x,y;
 printf("Enter variables of a quadratic equation \n");
 scanf("%d%d%d",&a,&b,&c);
 x=((-b)+(sqrt(pow(b,2)+(4*a*c))))/(2*a);
 y=((-b)-(sqrt(pow(b,2)+(4*a*c))))/(2*a);
 printf("The roots of\t %dX^2+%dX+%d\nare %f\t%f",a,b,c,x,y);
}

