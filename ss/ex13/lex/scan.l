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
 yyin=fopen("old.txt","r");
 yylex();
 printf("Number of Comment lines are :%d\n",s);
}

