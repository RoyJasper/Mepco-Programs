#include<stdio.h>
main()
{FILE *fp1,*fp2;
int ch;
char fname1[30],fname2[30];
printf("enter source file");
scanf("%s",fname1);
printf("enter destination file");
scanf("%s",fname2);
fp1=fopen(fname1,"r");
fp2=fopen(fname2,"w");
if (fp1==NULL)
{
printf ("cannot open fname1");
}
else if (fp2==NULL)
{
printf ("cannot open fname2");
}
else
{ch=getc(fp1);
while (ch!=EOF)
{putc(ch,fp2);;
ch=getc(fp1);
}
fclose(fp1);
fclose(fp2);
}}
