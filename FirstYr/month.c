#include<stdio.h>
void month(int);
main()
{
 int ch;
 printf("Enter no between 1 and 12\n");
 scanf("%d",&ch);
 month(ch);
}
void month(int n)
{
 switch(n)
  {
   case 1:  
      printf("\njanuary");
      break;
   case 2:
      printf("\nfeburary");
      break;
   case 3:
      printf("\nmarch");
      break;
   case 4:
      printf("\napril");
      break;
   case 5:
      printf("\nmay");
      break;
   case 6:
      printf("\njune");
      break;
   case 7:
      printf("\njuly");
      break;
   case 8:
      printf("\naugust");
      break;
   case 9:
      printf("\nseptember");
      break;
   case 10:
      printf("\noctober");
      break;
   case 11:
      printf("\nnovember");
      break;
   case 12:
      printf("\ndecrmber");
      break;
   default:
      printf("\ninvalid input");
      break;
  }
 printf("\n");
}




