%{
#include<stdio.h>
int p=0,pp=0;
%}
%%
[aeiou] {p++;}
[a-z] {pp++;}
%%
int yywrap()
{
return 1;
}
int main(int argc,char * argv[])
{
yyin=fopen("pp2.c","r");
yylex();
printf("THE NO IS VOWELS:%d\nCONSONANTS:%d",p,pp);
return 0;
}
