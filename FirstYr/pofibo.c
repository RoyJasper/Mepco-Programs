#include<stdio.h>
main()
{
int s=0,t1=-1,t2=1,*p1,*p2,*p3,n,c;
printf("enter number of times");
scanf("%d",&n);
p1=&s;
p2=&t1;
p3=&t2;
for(c=1;c<=n;c++)
 {
  *p1=*p2+*p3;
  printf("%d\t",*p1);
  *p2=*p3;
  *p3=*p1;
 }
}
