#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 main()
{
 int n,g=0,i;
 char a[10],ch,rp,b[10];
 printf("Enter a string\n");
 scanf(" %s",a);
 n=strlen(a);
 printf("Enter a character to search\n");
 scanf(" %c",&ch);
 for(i=0;a[i]!='\0';i++)
  {
   if(a[i]==ch)
    g=1;
  }
 if(g==1)
  printf("the character is present\n");
///else
 // {
  // printf("This character is not present\n");
  // exit(0); 
 // }
 printf("Enter the character to replace\n");
 scanf(" %c",&rp);
 for(i=0;a[i]!='\0';i++)
  {
  if(a[i]==ch)
   b[i]=rp;
  else
   b[i]=a[i];  
  }
b[i]='\0';
 printf("the remodified string is %s \n",b);
}















