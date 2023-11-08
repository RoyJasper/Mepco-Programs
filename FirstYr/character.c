#include<stdio.h>
void replace(char[],char);
main()
{
 char a[20],x;
 printf("enter the string");
 scanf("%s",a);
 printf("enter the character to be searched");
 scanf(" %c",&x);
 replace(a,x);
}
void replace(char a[20],char x)
{
 char y,*p;
 p=a;
 printf("enter the character to be replaced");
 scanf(" %c",&y);
 for(;p!='\0';p++)
 {
  if(p==x)
  {
   p=y;
  }
 }
 printf("%s",*p);
}
