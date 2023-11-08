%{
#include<stdio.h>
#include<string.h>
int c=0,d=0,j=0,t=0;
char str[50][50],str1[50][50];
%}
%%
[a-z A-Z][a-z A-Z 0-9]* c++;strcpy(str[j++],yytext);
"="|"+"|"-"|"*"|"/" d++;strcpy(str1[t++],yytext);
%%
int yywrap()
{
  return 1;
}
int main(int argc,char *argv[])
{
  int j=0,t=0,i;
  yyin=fopen("op.txt","r");
  yylex();
  if((c-d)==1)
  {
    printf("\nIt is a Valid Expression");
    printf("\nOperands:\n");
    for(i=0;i<c;i++)
      printf("%s\n",str[i]);
    printf("\nOperators:\n");
    for(i=0;i<d;i++)
      printf("%s\n",str1[i]);
  }
}

