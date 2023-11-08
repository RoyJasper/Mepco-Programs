#include<stdio.h>
main()
{
int i,*ptr,num,t1,t2,fib[20];
printf("enter number of terms");
scanf("%d",&num);
ptr=fib;
t1=-1;
t2=1;
for(i=0;i<num;i++)
{
*ptr=t1+t2;
t1=t2;
t2=*ptr;
printf("%d\n",*ptr);
}
}

