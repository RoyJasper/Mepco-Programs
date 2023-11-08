#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
 file *fp;
 fp=fopen("3addr.c","r");
fscanf(fp,"%s",str);
 while(!strcmp(str,"exit")==0)
{
 n=strlen(str);
 for(i=0;i<n;i++)
{
 if(str[i]!='+'&& str[i]!='-'&& str[i]!='*'&& str[i]!=',')
{
 c=c+1;
 }
}
 if(c==n)
{
 for(i=0;i<n;i++)
{
 if(str[i]!='=')
{
 str[j][i]=str[i];
}
else
j++;
}
printf("mov %d %s",k,strr[i]);
printf("mov %s,R %d",strr[0],k);

