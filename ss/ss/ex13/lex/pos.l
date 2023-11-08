%{
#include<stdio.h>
int posint=0;
int negint=0;
int postfrac=0;
int negfrac=0;
%}
%%
"+"?[0-9]+ {posint++;}
"-"?[0-9]+ {negint++;}
"+"?[0-9]*"."[0-9]+ {postfrac++;}
"-"?[0-9]*"."[0-9]+ {negfrac++;}
%%
int yywrap()
{
return 1;
}
main(int argc,char* argv[])
{
char na[40];
 yyin=fopen("imi.txt","r");
 yylex();
 printf("Postive Integer:%d\nNegative Integer:%d\nPositive Fraction:%d\nNegative Fraction:%d",posint,negint,postfrac,negfrac);
}
