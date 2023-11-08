#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp1;
int n;
char c,a[10];
printf("Enter name of file 1");
scanf("%s",a);
fp1=fopen(a,"r");
fseek(fp1,20,SEEK_SET);
c=getc(fp1);
 while(c!=EOF)
  {
   printf("%c",c);
   c=getc(fp1);
  }
 fclose(fp1);
}

