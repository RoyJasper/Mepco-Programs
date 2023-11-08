#include<stdio.h>
extern int yylex();
extern int p;
int main()
{
printf("ENTER THE NUMBER");
yylex();
printf("THE NO IS %d",p);
return 0;
}

