#include<stdio.h>
#include<stdlib.h>
main(int argc,int *argv[])
{
FILE *fp,*fp1,*fp2;
if(argc==0)
{
printf("NO INPUT FILES");
exit(0);
}
if(argc>1)
{
fp=fopen(argv[1],"r");
fp2=fopen(argv[2],"r");
fp1=fopen(argv[3],"a");
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
fp1=fopen(argv[3],"r");
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





 
 
 

