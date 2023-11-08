#include<stdio.h>
main()
{
FILE *fp;
char a[100],b,c[10];
int n,i=0,j,no;
printf("Enter file name:");
scanf("%s",c);
printf("Enter no of characters to skip:");
scanf("%d",&no);
fp=fopen(c,"r+");
fseek(fp,no,SEEK_SET);
while(a[i]!=EOF)
{
a[i]=fgetc(fp);
i=i+1;
}
for(j=0;j<i;j++)
{
printf("%c",a[j]);
}
}



