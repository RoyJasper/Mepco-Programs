#include<stdio.h>
main()
{
int a[5],i,j,c;
int *ip[5];
printf("give five values \n");
for(i=0;i<5;i++)
scanf("%d",&a[i]);
for(i=0;i<5;i++)
ip[i]=&a[i];
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(*ip[i]<*ip[j])
{
c=*ip[j];
*ip[j]=*ip[i];
*ip[i]=c;
}
printf("ascending order : \n");
for(i=0;i<5;i++)
{printf("%d \t",*ip[i]);}
printf("\n");
printf("descending order : \n");
for(i=4;i>=0;i--)
{printf("%d \t",*ip[i]);}
}
