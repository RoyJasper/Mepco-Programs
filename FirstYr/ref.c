#include<stdio.h>
void swap(int*,int*);
main()
{
 int x,y;
 printf("enter two numbers");
 scanf("%d%d",&x,&y);
 swap(&x,&y);
 printf("the numbers are %d %d",x,y);
}
void swap(int*a,int*b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}
