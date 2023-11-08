#include<stdio.h>
int fib(int);
main()
{
int j,n,i;
printf("enter  number of times");
scanf("%d",&n);
for(i=0;i<n;i++)
printf("%d\t",fib(i));
}
int fib(int n)
{
int val;
if(n==0)
return 0;
else if((n==1)||(n==2))
return 1;
else
return(fib(n-1)+fib(n-2));
}


