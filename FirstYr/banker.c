#include<stdio.h>
#include<stdlib.h>
struct bank
{
 int acc,balance;
 char name[10],add[20];
}*c;
main()
{
 int a,b,i=0,n,choice;
 printf("enter the number of clients");
 scanf("%d",&n);
 c=(struct bank*)malloc(n*sizeof(struct bank));
 begin:
 while(i<n)
 {
  printf("Enter the name,address,account no and balance of %d client",i+1);
  scanf("%s%s%d%d",c[i].name,c[i].add,&c[i].acc,&c[i].balance);
  while(1)
  {
   printf("\nenter your choice\n1.credit\n2.debit\n3.balance\n4.exit");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
           printf("enter the amount to be added");
           scanf("%d",&a);
           c[i].balance=c[i].balance+a;
           printf("The balance is %d",c[i].balance);
           break;
    case 2:
           printf("enter the amount to withdraw");
           scanf("%d",&b);
           c[i].balance=c[i].balance-b;
           printf("The balance is %d",c[i].balance);
           break;
    case 3:
           printf("balance is %d",c[i].balance);
           break;
    case 4:
          printf("Logginng out .......");
           i++;
           goto begin;
    default:
            printf("invalid choice");
            break;
   }
  }
 }
}

