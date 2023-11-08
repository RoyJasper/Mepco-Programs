#include<stdio.h>
#include<string.h>
main()
{
char s[30];
int choice,len,i,j,temp;
int alphabets=0;
int numerals=0;
int others=0;
printf("the choices are \n");
printf("1.The length of a string\n");
printf("2.Reverse of a string\n");
printf("3.Count the number of characters\n");
printf("Enter your choice \n");
scanf("%d",&choice);
printf("enter the string \n");
scanf("%s",s);
switch(choice)
{
case 1:
//  printf("enter the string \n");
//  gets(s);
 len=0;
  while(s[len]!=0)
  {
  len++;
  }
  printf("the length of the string is %d",len);
break;
case 2:
//  printf("enter the string \n");
//  scanf("%s",s);
 i=0,j=0,len=0;
while(s[len]!='\0')
{
len++;
}
j=len-1;
while(i<j)
{
temp=s[i];
s[i]=s[j];
s[j]=temp;
i++;
j--;
}
printf("reverse of a string is %s",s);
break;
case 3:
  //printf("enter the string \n");

  //gets(s);
i=0;
while(s[i]!='\0')
{if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
{
alphabets++;
i++;
}
else if(s[i]>='0' && s[i]<='9')
{numerals++;
i++;
}
else
{others++;
i++;}
}
printf("number of alphabets =%d \n",alphabets);
printf("number of numerals =%d \n",numerals);
printf("other characters =%d \n",others);
break;
}}
