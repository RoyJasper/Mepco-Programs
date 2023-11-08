#include<stdio.h>
void swap(int*,int*);
main()
{
 int a,b;
 printf("Enter two numbers\n");
 scanf("%d%d",&a,&b);
 swap(&a,&b);
 printf("swaped no are%d   %d",a,b);
}

void swap(int*a,int*b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
 
