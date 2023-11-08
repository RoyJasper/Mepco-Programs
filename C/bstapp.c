#include"bsthead.h"
main()
{
int a,choice;
bst b,c,d,t=NULL;
while(1)
{
printf("\n1.INSERT\n2.DELETE\n3.INORDER\n4.PREORDER\n5.POSTORDER\n6.EXIT\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("ENTER THE NUMBER");
scanf("%d",&a);
t=insert(a,t);
printf("IT IS INSERTED SUCCESSFULLY");
break;
case 2:
printf("ENTER THE NUMBER TO BE DELETED");
scanf("%d",&a);
t=deletion(a,t);
break;
case 3 :
inorder(t);
break;
case 4:
preorder(t);
break;
case 5:
postorder(t);
break;
case 6:
exit(0);
}
}
}
