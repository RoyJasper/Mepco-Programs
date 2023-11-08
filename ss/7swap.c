#include<stdio.h>
main()
{
int x,y;
printf("enter the values of x and y");
scanf("%d%d",&x,&y);
void swap(int *,int *);
printf("%d%d\n",x,y);
swap(&x,&y);
printf("%d%d\n",x,y);
}
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}

