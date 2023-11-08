#include<stdio.h>
#include<string.h>
int reverse(char[],int);
main()
{
int n,t;
char a[20];
printf("enter the string\n");
scanf("%s",a);
n=strlen(a);
t=reverse(a,n);
if(t==1)
printf("palindrome");
else
printf("not palindrome");
}
int reverse(char a[20],int n)
{
char b[20],*p;
int c=0,j=0,i;
p=a;
for(i=n-1;i>=0;i--)
 {
  b[i]=*p;
  j++;
  p++;
 }
b[n]='\0';
if(strcmp(a,b)==0)
 return 1;
else
 return 0;

