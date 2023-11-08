#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
main()
{
FILE *fp;
int a,i,n;
char d,b[50],c[50];
while(1)
{
printf("\nENTER THE COMMAND\n1.read\n2.write\n3.append\n4.exit");
scanf("%d",&a);
switch(a)
{
case 1:
fp=fopen("ex.c","r");
d=fgetc(fp);
while(d!=EOF)
{
putchar(d);
d=fgetc(fp);
}
fclose(fp);
break;
case 2:
fp=fopen("ex.c","w");
printf("ENTER THE WORD TO BE WRITTEN");
scanf(" %s",b);
n=strlen(b);
for(i=0;i<n;i++)
putc(b[i],fp);
fclose(fp);
break;
case 3:
fp=fopen("ex.c","a");
printf("ENTER THE WORD TO BE appended");
scanf(" %s",c);
n=strlen(c);
for(i=0;i<n;i++)
putc(c[i],fp);
fclose(fp);
break;
case 4:exit(1);
}
}
}



