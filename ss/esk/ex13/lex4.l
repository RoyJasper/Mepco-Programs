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
yyin=fopen("pp2.c","r");
yylex();
printf("THE NO IS CHARACTER:%d\nWORDS:%d\nBLANK:%d\nEND OF LINE:%d",c,w,p,pp);
return 0;
}
