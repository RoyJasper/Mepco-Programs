#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
FILE *fp1,*fp2,*fp;
int i,s,st;
char c;
if(argc==0)
{
printf("\nNot possible to compute");
exit(0);
}
if(argc>1)
{
printf("\nEnter the start character number");
scanf("%d",&s);
printf("\nEnter the stop character number");
scanf("%d",&st);
fp1=fopen(argv[1],"a");
fp2=fopen(argv[2],"r");
fseek(fp2,s,SEEK_SET);
c=fgetc(fp2);
while(st-s>0)
{
fputc(c,fp1);
c=fgetc(fp2);
s++;
}
fclose(fp1);
}
fp=fopen(argv[1],"r");
c=fgetc(fp);
while(c!=EOF)
{
putchar(c);
c=fgetc(fp);
}
fclose(fp);
fclose(fp2);
}
        
