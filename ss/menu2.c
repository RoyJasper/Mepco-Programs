#include<string.h>
#include<stdio.h>
main()
{
char str[30],ch;
int choice ,i,p,count,flag,len;
printf("\t\t\tThe choices are\n");
printf("1.Search a character and report its position\n");
printf("2.Find out the character at the specified position \n");
printf("3.Display the number of occurences of a particular character\n");
printf("4.Check whether the string is palindriome or not \n");
printf("5.Exit\n");
while(1)
{
printf("Enter your choice \n");
scanf("%d",&choice);
if(choice==5)
{break;}
printf("Enter the string\n");
scanf("%s",str);
switch(choice)
{
case 1:count=1;
 printf("\nEnter the character to be searched\n");
 scanf("\n%c",&ch);
 for(i=0;str[i]!='\0';i++)
 {
 if(str[i]==ch)
 {
 p=i;
 printf("\nThe Position of %c is %d\n ",ch ,count);
 }
count++;
}
 if(count==0)
 printf("\nThe given character is not present\n");
 else
 printf("\nThe character is present\n");
 break;
case 2:
 printf("Enter the position\n");
 scanf("%d",&p);
 printf("the character is %c\n",str[p-1]);
 break;
case 3:count=0;
 printf("Enter the character to be searched: \n");
 scanf("\n%c",&ch);
 for(i=0;str[i]!='\0';i++)
 {
 if(str[i]==ch)
 count++;
 }
 if(count==0)
 printf("The character is not present \n");
 else
 printf("Occurence of character %c is %d\n",ch,count);
 break;
case 4:
 flag=0;
 len=0;
 while(str[len]!='\0')
 {
 len++;
 }
 for(i=0;i<len;i++)
 {
 if(str[i]!=str[len-i-1])
 {
 flag=1;
 break;
 }
 }
 if(flag==1)
 printf("The given string is not a palindrome\n");
 else
 printf("The given string is a palindrome\n");
 break;
default:
 printf("Try again");
}
}
}
