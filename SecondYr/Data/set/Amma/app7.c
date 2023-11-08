
#include"head7.h"
int main()
{
int choice,a;
left h;
printf("\n\n\t\tWELCOME TO LEFTISTHEAP OPERATION");
while(1)
{
printf("\n1.insert\n2.delete\n3.diplay\n4.exit\nenter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter the data");
scanf("%d",&a);
h=insert(a,h);
break;
case 2:
h=delet(h);
printf("\n Deleted");
break;
case 3:
display(h);
break;
case 4:
exit(0);
}
}
return 0;
}
