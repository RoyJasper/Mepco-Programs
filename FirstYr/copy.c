#include<stdio.h>
main()
{
 int i;
 char a[20],b[20],*p;
 printf("enter the string");
 scanf("%s",a);
 p=a;
 for(i=0;*(a+i)!='\0';i++)
 {
  b[i]=*p;
  p++;
 }
 printf("the copied string is %s",b);
}
 
