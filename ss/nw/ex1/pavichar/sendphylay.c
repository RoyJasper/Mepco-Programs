#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fp;
char a[50];
int count=0,n,i,c;
printf("enter the mesage\n");
gets(a);
fp=fopen("summa.txt","w");
n=strlen(a);
for(i=0;i<n;i++)
{
if(a[i]==' ')
{
 count++;
 fprintf(fp,"%d",count);
  count=0;
}
else
{
 putc(a[i],fp);	
 count++;

}
}
fclose(fp);
return 0;
}
