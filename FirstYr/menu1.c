#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
main()
{
char a[20],b[20],q,t[20];
int i=0,c=0,n,ch=0,no=0,sp=0,j=0,c1=0,d1=0;
printf("enter a string");
scanf("%s",a);
while(1)
{
printf("\nEnter your choice\n1.length of string\n2.reverse of string\n3.count variables\n4.exit");
scanf("%d",&n);
switch(n)
{
  case 1:
   printf("the length of string is %d\n",strlen(a));
   break;
  case 2:
          while(a[i]!='\0')
       {
        d1=d1+1;
        i=i+1;
       }
       for(i=d1-1;i>=0;i--)
       {
        t[j]=a[i];
        j=j+1;
       }
       t[j]='\0';
       printf("reversed string is %s",t);
   break;
  case 3:
  while(a[i]!='\0')
   {
  if(isdigit(a[i]))
   {
    no=no+1;
    i=i+1;
   }
  else if(isalpha(a[i]))
   {
    ch=ch+1;
    i=i+1;
   }
  else
   {
    sp=sp+1;
    i=i+1;
   }
    }
  printf("there are %d alphabets\nand %dspecial charaters\nand %d numbers\n",ch,sp,no);
  break;
  case 4:
  exit(0);
  break;
  default:
  printf("invalid input\n");
  break;
}
}
}
