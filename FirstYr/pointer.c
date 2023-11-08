#include<stdio.h>
void swap(int*,int*);
main()
{
int a,b;
printf("enter two numbers");
scanf("%d%d",&a,&b);
swap(&a,&b);
printf("interchanfed values are %d %d",a,b);
}
void swap(int *x,int *y)
{
int c;
c=*x;
*x=*y;
*y=c;
}

