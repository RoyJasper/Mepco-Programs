#include<stdio.h>
main()
{
 int *p,*q,*r;
 int s=0,t1=-1,t2=1,c=1,n;
 printf("enter the number");
 scanf("%d",&n);
 p=&s;
 q=&t1;
 r=&t2;
 while(c<=n)
 {
  *p=*q+*r;
  *q=*r;
  *r=*p;
  c++;
  printf("%d\n",*p);
 }
}
