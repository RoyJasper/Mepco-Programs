#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define BUFFER_SIZE 10
#include<stdlib.h>
int main()
{
char buffer[BUFFER_SIZE];
int n,in=0,out=0;
char c[20],p[20];
while(1)
{
printf("\nEnter the Choice \n1.NextProduced \n2.NextConsumed \n3.Exit");
scanf("%d",&n);
switch(n)
{
case 1:
if(in==out)
printf("\nThere is nothing in the Shop...Please Wait!!");
else
{
strcpy(c,buffer[out]);
out=((out+1)%BUFFER_SIZE);
printf("\n%s",c);
}
break;
case 2:
if(out==(in+1)%BUFFER_SIZE)
printf("\nThere are More Items in the shop");
else
{
printf("\nEnter the Thing to be Inserted");
scanf("%s",p);
printf("----------->%s<-----------",p);
strcpy(buffer[in],p);
in=((in+1)%BUFFER_SIZE);
}
break;
case 3:
exit(0);
}}}



