%{
#include<stdio.h>
int p=0,pp=0,f=0;
%}
%%
[-][0-9]+ {p++;}
[0-9]*"."[0-9]+ {f++;}
[0-9]+ {pp++;}
%%
int yywrap()
{
return 1;
}
int main(int argc,char * argv[])
{
yyin=fopen("counpf.c","r");
yylex();
printf("\n No of -Ve : %d\t  +ve : %d \t Fraction : %d ",p,pp,f);
return 0;
}
