#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp,*fp1,*fp2;
{
fp=fopen("ex1.txt","r");
fp2=fopen("ex2.txt","r");
fp1=fopen("ex3.txt","a");
char a,b,c;
a=fgetc(fp);
while(a!=EOF)
{
putc(a,fp1);
a=fgetc(fp);
}
b=fgetc(fp2);
while(b!=EOF)
{
putc(b,fp1);
b=fgetc(fp2);
}
fclose(fp1);
fp1=fopen("ex3.txt","r");
c=fgetc(fp1);
while(c!=EOF)
{
putchar(c);
c=fgetc(fp1);
}
fclose(fp);
fclose(fp1);
fclose(fp2);
}
}



