%{
#include<stdio.h>
#include<string.h>
int p=0,pp=0,j=0,t=0;
char str[50][50],str1[50][50];
%}
%%
[a-zA-Z][a-zA-Z0-9]* {p++,strcpy(str[j++],yytext);}
"+"|"-"|"*"|"/"|"=" {pp++,strcpy(str1[t++],yytext);}
%%
int yywrap()
{
return 1;
}
int main(int argc,char * argv[])
{
int i=0;
yyin=fopen("pp3.c","r");
yylex();
if((p-pp)==1)
{
printf("VALID");
printf("\nOPERANDS:");
for(i=0;i<p;i++)
{
printf("%s",str[i]);
}
printf("\nOPERATORS:");
for(i=0;i<pp;i++)
{
printf("%s",str1[i]);
}
}
else
{
printf("NOT VALID");
}
return 0;
}
