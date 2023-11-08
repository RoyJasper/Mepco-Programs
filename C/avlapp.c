#include"avlhead.h"
main()
{
avl t,k;
int a,b,choice;
t=NULL;
k=(avl)malloc(sizeof(struct node));
while(1)
{
printf("1.INSERT 2.SEARCH 3.HEIGHT 4.INORDER 5.PREORDER 6.POSTORDER 7.EXIT\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("ENTER THE VALUE TO BE INSERTED");
scanf("%d",&a);
t=insert(a,t);
printf("ELEMENT IS INSERTED SUCCESSFULLY%d",t->data);
break;
case 2:
printf("ENTER ELEMENT TO BE SEARCHED");
scanf("%d",&a);
search(a,t);
break;
case 3:
b=height(t);
printf("THE HEIGHT IS %d",b);
break;
case 4:
inorder(t);
break;
case 5:
preorder(t);
break;
case 6:
postorder(t);
break;
case 7:
exit(0);
}
}
}
 
