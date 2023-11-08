#include<stdio.h>
#include<stdlib.h>
main()
{
 int b,d=0,i=0,choice,j=0,d1=0,x=0;
 char a[20],t[20];
 char c,k;
 printf("enter the string");
 scanf("%s",a);
 while(1)
{
 printf("\nenter your choice\n1.search a character and print its position\n");
 printf ("2.find the character at specified position\n3.number of occurences\n4.palindrome\n5.exit");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
        printf("enter the character");
        scanf("%s",&c);
        for(i=0;a[i]!='\0';i++)
        {
         if(a[i]==c)
         printf("%c is present in %d",c,i+1);
        }
        break;
  case 2:
        printf("\nenter the position");
        scanf("%d",&b);
 			  printf("\nthe character is %c",a[b-1]);
 			  break;
 case 3:
       printf("enter the character");
       scanf("%s",&k);
       for(i=0;a[i]!='\0';i++)
       {
        if(a[i]==k)
        d=d+1;
       }
       printf("\nthe number of occurences is %d",d);
       break;
 case 4:
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
       for(i=0;i<d1;i++)
       {
       if(t[i]==a[i])
       x=x+1;
       }
       if(x==d1)  
       printf("palindrome");
       else
       printf("not palindrome");
       break;
 case 5:
        exit(0);
 default:
       printf("invalid choice");
	}
 }        
}        
     

 
