%{
#include<stdio.h>
int v=0;
int c=0;
%}
%%
"int"|"float"|"double"|"char" {v++;}
%%
int yywrap()
{
return 1;
}
int main()
{
yyin=fopen("iden.txt","r");
yylex();
printf("\n Number of identifiers  are :  %d \n",v);
}

