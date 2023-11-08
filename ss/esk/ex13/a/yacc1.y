%{
#include<stdio.h>
%}
%token NUMBER ID NL 
%left '+''-'
%left '*''/'
%%
stmt: exp NL {printf("VALUE=%d\n",$1);exit(0);}

exp: exp '*' exp { $$=$1*$3;}
|
exp '/' exp { $$=$1/$3;}
|
exp '+' exp { $$=$1+$3;}
|
exp '-' exp { $$=$1-$3;}
|
ID { $$=$1;}
|
NUMBER { $$=$1;}
;
%%
int yyerror(char *msg)
{
printf("\nINVALID EXPRESSION");
exit(0);
}
int main()
{
printf("ENTER THE EXPRESSION:\n");
return (yyparse());
}

