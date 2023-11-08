#include<stdio.h>
int fib(int);
main()
{
 int j,n;
 printf("enter the number");
 scanf("%d",&n);
 for(j=0;j<n;j++)
 printf("%d\n",fib(j));
}
int fib(int j)
{
 if(j==0)
 return 0;
 else if((j==1)||(j==2))
 return 1;
 else
 return((fib(j-1))+fib(j-2));
}
 

