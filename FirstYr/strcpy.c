#include<stdio.h>
main()
{
char a[10],b[10],*p;
int i;
printf("Enter a string");
scanf("%s",a);
p=a;
for(i=0;*(a+i)!='\0';i++)
 b[i]=*(a+i);
printf("The copied string is %s",b);
}

