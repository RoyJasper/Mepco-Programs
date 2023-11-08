#include<math.h>
#include<stdio.h>
main()
{
 float e,f,d,m,n;
 int a,b,c;
 printf("enter the three coefficients");
 scanf("%d%d%d",&a,&b,&c);
 d=sqrt((pow(b,2)-4*a*c));
 e=(-b+d);
 f=(-b-d);
 m=(e/(2*a));
 n=(f/(2*a));
 printf("the roots of the quadratic equation are %f and %f",m,n);
}
