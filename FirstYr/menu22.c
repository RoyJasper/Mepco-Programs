#include<ctype.h>
#include<stdio.h>
#include<string.h>
main()
{
 int n,choice,b=0,i=0,j=0,num=0,alp=0,spe=0;
 char a[20],t[20];
 printf("enter the string");
 scanf("%s",a);
 while(1)
 {
 printf("\nenter your choice\n1.to find length\n2.to reverse the string");
 printf("\n3.to count no of digits,alphabetsand special characters\n4.exit");
 scanf("%d",&choice);
 switch(choice)
  {
   case 1:
         printf("the string length is %d",strlen(a));
         break;
   case 2: 
        while(a[i]!='\0')
        {
         b=b+1;
         i=i+1;
        }
        for(i=b-1;i>=0;i--)
        {
         t[j]=a[i];
         j=j+1;
        }
        t[j]='\0';
        printf("the reversed string is %s",t); 
        break;
   case 3:
        for(i=0;(a[i]!='\0');i++)
        {
        if(isdigit(a[i]))
         num=num+1;
        else if(isalpha(a[i]))
        alp=alp+1;
        else
         spe=spe+1;
        }
        printf("\ndigits:%d\nalphabets:%d\nspecial characters:%d",num,alp,spe);
        break;
  case 4:
         exit(0);
        default:
        printf("invalid input");
  }
 }
}        
