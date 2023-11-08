%{
#include<stdio.h>
int p=0,pp=0;
%}
%%
"printf" {p++,fprintf(yyout,"writef");}
"scanf" {pp++,fprintf(yyout,"readf");}
. {fprintf(yyout,"%s",yytext);}
\n {fprintf(yyout,"\n");}
%%
int yywrap()
{
return 1;
}
int main(int argc,char * argv[])
{
yyin=fopen("pp1.c","r");
yyout=fopen("p1.c","w");
yylex();
printf("THE NO IS PRINTF:%d\nSCANF:%d",p,pp);
return 0;
}
