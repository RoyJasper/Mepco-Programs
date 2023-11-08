#include<stdio.h>
int add1(int,int);
int add2(int,int);
main()
{
int r1,r2,i1,i2,i3,r3;
printf("enter real and immaginary part of first complex no");
scanf("%d%d",&r1,&i1);
printf("enter real and immaginary part of second complex no");
scanf("%d%d",&r2,&i2);
r3=add1(r1,r2);
i3=add2(i1,i2);
printf("their sum is %d + %di",r3,i3);
}
int add1(int x,int y)
{
int s;
s=x+y;
return s;
}
int add2(int x,int y)
{
int s;
s=x+y;
return s;
}

