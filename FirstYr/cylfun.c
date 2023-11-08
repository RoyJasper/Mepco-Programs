#include<stdio.h>
float volume(int,int);
main()
{
 float a;
 int r,h;
 printf("enter the radius and height");
 scanf("%d%d",&r,&h);
 a=volume(r,h);
 printf("volume is %f",a);
}
float volume(int r,int h)
{
 float s;
 const float pi=3.14;
 s=(pi*r*r*h);
 return s;
}
