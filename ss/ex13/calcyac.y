%{
#include<stdio.h>
int num[26];
int b;
%}
%start list
%union {int value;}
%token DIGIT LETTER
%left '+''-'
%left '*''/'
list: list stat'\n';
stat: expr
{
printf("%d\n",$1.value);
}
LETTER '=' expr
{
num[$1.value=$3.value];
}
;
expr: expr '*' expr
{
$$.value=$1.value*$3.value;
}
|
expr '/' expr
{
$$.value=$1.value/$3.value;
}
|
expr '+' expr
{
$$.value=$1.value+$3.value;
}
|
expr '-' expr
{
$$.value=$1.value-$3.value;
}
|
LETTER
{
$$.value=num[$1.value];
}
|
number
;
number: number DIGIT
{
$$.value=base*$1.value+$2.value;
}
;
%%
int yywrap()
{
return 1;
}
int main()
{
return (yyparse());
}

