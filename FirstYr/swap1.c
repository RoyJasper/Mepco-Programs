#include<stdio.h>
void swap(int*,int*);
main()
{
 int a,b;
 printf("enter the two numbers");
 scanf("%d%d",&a,&b);
 swap(&a,&b);
 printf("%d %d",a,b);
}
void swap(int*a,int*b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;  
}
