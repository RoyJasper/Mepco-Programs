%{
#include<stdio.h>
int p=0,pp=0,w=0,c=0;
%}
%%
" " {p++,w++;}
\n {pp++,w++;}
. {c++;}
%%
int yywrap()
{
return 1;
}
int main(int argc,char * argv[])
{
yyin=fopen("coucwbl.c","r");
yylex();
printf("\n No of :%d\n  :%d\n blank:%d\n eol :%d",c,w,p,pp);
return 0;
}
