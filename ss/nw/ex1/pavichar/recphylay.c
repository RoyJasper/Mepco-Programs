#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 FILE *fp;
char d;
int s;
 fp=fopen("summa.txt","r");
 d=getc(fp);
 while(d!=EOF)
 {
  s=(int)d;
 if(s>=65 && s<=127 )
 {
  printf("%c",d);
  }
else
 {
  printf(" ");
 }
d=getc(fp);
}
fclose(fp);
return 0;
}

