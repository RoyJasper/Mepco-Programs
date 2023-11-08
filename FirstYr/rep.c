#include<stdio.h>
void replace(char *,char,char);
main()
{
char a[50],x,r;
printf("\nEnter a string:");
scanf("%s",a);
printf("\nEnter the character to be replaced");
scanf(" %c",&x);
printf("\nEnter the character to be replaced with");
scanf(" %c",&r);
replace(a,x,r);
printf("\nThe replaced string is %s",a);
}
void replace(char *p,char x,char r)
{
for(;*p!='\0';p++)
{
if(*p==x)
{
*p=r;
}
}
}

