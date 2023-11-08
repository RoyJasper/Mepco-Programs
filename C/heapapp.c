#include"heaphead.h"
main()
{
int choice,ca,x,a;
heap h,k;
printf("ENTER THE CAPACITY");
scanf("%d",&ca);
h=create(ca);
if(h==NULL)
{
printf("ERROR");
exit(0);
}
while(1)
{
printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("ENTER THE VALUE TO BE INSERTED");
scanf("%d",&x);
k=insert(x,h);
break;
case 2:
a=deletemax(h);
printf("%d IS DELETED",a);
break;
case 3:
display(h);
break;
case 4:
exit(0);
break;
}
}
}


