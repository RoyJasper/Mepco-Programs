%{
#include<stdio.h>
int c=0,w=0,l=0,s=0;  //char naa[80];
%}
%%
" " s++;w++;c++;
\n l++;w++;
. {c=c+yyleng;}
%%
int yywrap()
{
 return 1;
}
main(int argc,char *argv())
{
 char naa[70];
 //printf("Enter file name");
 //scanf("%s",naa);
 yyin=fopen("im.txt","r");
 yylex();
 printf("Characters:%d\nWords:%d\nLines:%d\nSpaces:%d",c,w,l,s);
}    
