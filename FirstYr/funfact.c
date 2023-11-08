#include<stdio.h>
int fact(int);
main()
{
int n,f;
printf("enter a number");
scanf("%d",&n);
f=fact(n);
printf("factorial of %d  is %d",n,f);
}
int fact(int n)
{
if((n==0)||(n==1))
return 1;
else
return(n*fact(n-1));
}

