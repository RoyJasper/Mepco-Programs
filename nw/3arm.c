#include<stdio.h>
main()
{
int a,b,s=0,aa;
printf("enter a three digit number\n");
scanf("%d",&a);
aa=a;
while(a!=0)
{
b=a%10;
s=s+(b*b*b);
a=a/10;
}
if(s==aa)
printf("%d is an armstrong number\n",aa);
else
printf("%d is not an armstrong number\n",aa);
}

