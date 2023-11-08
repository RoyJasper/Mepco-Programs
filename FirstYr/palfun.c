#include<stdio.h>
#include<string.h>
main()
{
 int b,j=0,x=0,i;
 char a[20],*p,t[20];
 printf("enter the string");
 scanf("%s",a);
 b=strlen(a);
 p=a;
 for(i=b-1;i>=0;i--)
 {
  t[j]=*p;
  j=j+1;
  p++;
 }
 //t[j]='\0';
 if(strcmp(a,t)==0)
 printf("palindrome");
 else
 printf("not a palindrome");
}
