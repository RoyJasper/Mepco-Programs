#include"header.h"
main()
{
int n,choice,a;
printf("ENTER THE NUMBER OF EMPLOYEE");
scanf("%d",&n);
while(1)
{
printf("\n1.ALLOCATION\n2.GET DETAILS\n3.PRINT INDIVIDUAL\n4.PRINT ALL\n5.PRINT INDIVIDUAL SALARY\n6.HIGHEST SALARY\n7.EXIT\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
create(n);
break;
case 2:
getdetail(n);
break;
case 3:
printf("ENTER THE EMPLOYEE NUMBER TO BE DISPLAYED");
scanf("%d",&a);
printindi(n,a);
break;
case 4:
printall(n);
break;
case 5:
printsal(n);
break;
case 6:
topper(n);
break;
case 7:
exit(0);
}
}
}
