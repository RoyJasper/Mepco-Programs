nclude<stdio.h>

#include<conio.h>

void creation();

void deposit();

void withdraw();

void bal();

int a=0,i = 101;

struct bank

{

 int no;

 char name[20];

 float bal;

 float dep;

}s[20];

 void main()

 {

 int ch;

 while(1)

  {

   clrscr();

   printf("\n*********************");

   printf("\n BANKING ");

   printf("\n*********************");

   printf("\n1-Creation");

   printf("\n2-Deposit");

   printf("\n3-Withdraw");

   printf("\n4-Balance Enquiry");

   printf("\n5-Exit");

   printf("\nEnter your choice");

   scanf("%d",&ch);

   switch(ch)

   {

    case 1: creation();

            break;

    case 2: deposit();

            break;

   case 3: withdraw();

            break;

   case 4: bal();

            break;

   case 5: exit(0);
   defalut: printf("Enter 1-5 only");

            getch();

   }

  }

}

void creation()

{

 printf("\n*************************************");

 printf("\n ACCOUNT CREATION ");

 printf("\n*************************************");

 printf("\nYour Account Number is :%d",i);

 s[a].no = i;

 printf("\nEnter your Name:");

 scanf("%s",s[a].name);

 printf("\nYour Deposit is Minimum Rs.500");

 s[a].dep=500;

 a++;

 i++;

 getch();

}

void deposit()





        {





                   int no,b=0,m=0;





                   float aa;





                   printf("\n*************************************");





                   printf("\n DEPOSIT ");





                   printf("\n*************************************");


                   printf("\nEnter your Account Number");





                   scanf("%d",&no);





                   for(b=0;b<i;b++)





                       {





                           if(s[b].no == no)





                               m = b;





                       }





                           if(s[m].no == no)





                             {





                                        printf("\n Account Number : %d",s[m].no);





                                        printf("\n Name : %s",s[m].name);





                                        printf("\n Deposit : %f",s[m].dep);





                                        printf("\n How Much Deposited Now:");


                                        scanf("%f",&aa);





                                        s[m].dep+=aa;





                                        printf("\nDeposit Amount is :%f",s[m].dep);





                                        getch();





                             }





                            else





                             {





                                       printf("\nACCOUNT NUMBER IS INVALID");





                                       getch();





                              }





         }





             void withdraw()





         {





                    int no,b=0,m=0;
                    float aa;





                    printf("\n*************************************");





                    printf("\n WITHDRAW ");





                    printf("\n*************************************");





                    printf("\nEnter your Account Number");





                    scanf("%d",&no);





                    for(b=0;b<i;b++)





                        {





                               if(s[b].no == no)





                                 m = b;





                        }
    if(s[m].no == no)





                                 {





                                        printf("\n Account Number : %d",s[m].no);





                                        printf("\n Name : %s",s[m].name);





                                        printf("\n Deposit : %f",s[m].dep);





                                        printf("\n How Much Withdraw Now:");





                                        scanf("%f",&aa);





                                        if(s[m].dep<aa+500)





                                           {





                                                  printf("\nCANNOT WITHDRAW YOUR ACCOUNT HAS MINIMUM BALANCE");





                                                  getch();





                                           }





                                          else





                                           {

                                                                                                                      s[m].dep-=aa;





                                                  printf("\nThe Balance Amount is:%f",s[m].dep);





                                            }





                                 }





                               else





                                {





                                      printf("INVALID");





                                      getch();





                                }





                                      getch();





          }





                void bal()





          {
                  int no,b=0,m=0;





                  float aa;





                  printf("\n*************************************");





                  printf("\n BALANCE ENQUIRY ");





                  printf("\n*************************************");





                  printf("\nEnter your Account Number");





                  scanf("%d",&no);





                  for(b=0;b<i;b++)





                      {





                           if(s[b].no == no)





                             m = b;





                      }

                  

                           if(s[m].no==no)





                              {





                                    printf("\n Account Number : %d",s[m].no);





                                    printf("\n Name : %s",s[m].name);





                                    printf("\n Deposit : %f",s[m].dep);





                                    getch();





                              }





                             else





                             {





                                    printf("INVALID");





                                    getch();





                              }





            }



