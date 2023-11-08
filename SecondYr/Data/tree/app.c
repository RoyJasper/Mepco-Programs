#include"head.h"
main()
{
int x,n,l;
bst i;
bst t=NULL;
do
{
printf("\nEnter choice \n1.Insert \n2.Delete\n3.inorder\n4.preorder\n5.postorder\n6.Exit\n ");
scanf("%d",&n);
switch(n)
{
case 1:
printf("\nEnter the element ");
scanf("%d",&x);
t=insert(x,t);
//printf("\n INORDER  :\t");inorder(t);
//printf("\n PREORDER :\t");preorder(t);
//printf("\n POSTORDER:\t");postorder(t);
break;
case 2:
printf("\nEnter element to be deleted");
scanf("%d",&x);
t=deletion(x,t);
if(t==NULL)
{
printf("\n PREORDER:");
preorder(t);
}
break;
case 3:
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
break;
default:
printf("Invalid");
break;
}}while(1);
}
