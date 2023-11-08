%{
#include<stdio.h>
int p=0;
%}
%%
[-][0-9]+[p++]
%%
int yywrap()
{
return 1;
}
