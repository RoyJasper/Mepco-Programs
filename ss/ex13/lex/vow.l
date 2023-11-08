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
yyin=fopen("id.txt","r");
yylex();
printf("Number of identifier %d \n",v);
}
