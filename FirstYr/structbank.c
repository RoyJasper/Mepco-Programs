#include<stdio.h>
#include<stdlib.h>
struct bank
 {
  int bal;
  long int acc;
  char nam[10],add[30];
 }*b;
main()
{
 int n,c,a,d,i;
 printf("\nEnter number of clients\n");
 scanf("%d",&n);
 b=(struct bank*)malloc(n*sizeof(struct bank));
 for(i=0;i<n;i++)
  {
   printf("Enter\tName\n");
   scanf("%s",b[i].nam);
   printf("Enter Addrerss\n");
   scanf("%s",b[i].add);
   printf("Enter account no\n");
   scanf("%ld",&b[i].acc);
   printf("Enter Balance\n");
   scanf("%d",&b[i].bal);
   c=0;
   while(c!=4)
    {
     printf("Enter your choice\n1.Credit\n2.Debit\n3.balance\n4.logout\n");
     scanf("%d",&c);
     switch(c)
      {
       case 1:
          printf("Enter amount to add\n");
          scanf("%d",&a);
          b[i].bal=b[i].bal+a;
          printf("\nYour current balance is %d\n",b[i].bal);
          break;
       case 2:
          printf("\nEnter amount to withdraw\n");
          scanf("%d",&d);
          b[i].bal=b[i].bal-d;
          printf("\nYour current ballance is %d\n",b[i].bal);
          break;
       case 3:
          printf("\nYour Ballance is %d\n",b[i].bal);
          break;
       case 4:
          printf("\nLogging out........\n");
          break;
       default:
          printf("\nInvalid Input");
          break;
       }
     } 
   }

}

