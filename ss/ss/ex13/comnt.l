%{
#include<stdio.h>
int s=0,p=0;
%}
%%
"//" {s++;}
%%
int yywrap()
{
return 1;
}
main()
{
 yyin=fopen("pp5.c","r");
 yylex();
 printf("\n No of cmnt lines : %d \n",s);
}

