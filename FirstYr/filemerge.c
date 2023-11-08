#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp1,*fp2,*fp3;
int n;
char c,a[10],b[10],d[10];
printf("Enter name of file 1");
scanf("%s",a);
printf("Enter name of file 2");
scanf("%s",b);
printf("Enter filename where mereged file is to be copied.");
scanf("%s",c);
fp1=fopen(a,"r");
fp2=fopen(b,"r");
fp3=fopen(d,"a");

