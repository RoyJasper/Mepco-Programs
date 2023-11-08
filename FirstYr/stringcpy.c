#include<stdio.h>
main()
{
char a[10],*p[10];
int i,l;
printf("Enter a string");
scanf("%s",a);
for(i=0;a[i]!='\0';i++)
 {
  p[i]=&a[i];
 }
printf("Copied string is %s ",*p);
}
