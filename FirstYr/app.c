#include"head.h"
main()
{
int n,ch,crno;
printf("Enter no of students");
scanf("%d",&n);
allocatememory(n);
scandetails(n);
 while(ch!=5)
  {
   printf("Enter your choice\n1.Data of particular student\m2.Data of all students\n3.get rank\n4.topper of class\n5.exit");
   scanf("%d",&ch);
   switch(ch)
    {
     case 1:
       printf("Enter roll no");
       scanf("%d",&crno);
       particularstudent(crno,n);
       break;
     case 2:
       printall();
       break;
     case 3:
       rank(n);
       break;
     case 4:
       top(n);
     case 5:
       break;
     default:
       printf("Invalid input");
       break;
     }
  }
}


