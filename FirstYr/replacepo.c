#include<stdio.h>
#include<string.h>
void replace(char[]);
main()
{
 char a[10];
 printf("Enter a string");
 scanf("%s",a);
 replace(a);
}
void replace(char *p)
{
char ch,re;
int l,i;
l=strlen(p);
printf("Enter a character to search");
scanf(" %c",&ch);
printf("Enter a character to replace");
scanf(" %c",&re);
for(i=0;(*(p+i))!='\0';i++)
 {
  if((*(p+i))==ch)
   {
    (*(p+i))=re;
   }
 }
printf("Replaced string is");
for(i=0;(*(p+i))!='\0';i++)
 {
  printf("%c",(*(p+i)));
}
}
