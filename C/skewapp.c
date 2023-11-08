#include"skewhead.h"
main()
{
int ch,m;
lh temp;
//temp=(lh)malloc(sizeof(struct node));
//temp->data=0;
//temp->left=NULL;
//temp->right=NULL;
while(1)
{
printf("1.INSERT 2.DELETE 3.DISPLAY 4.EXIT ENTER THE CHOICE");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("ENTER THE ELEMENT TO INSERT");
scanf("%d",&m);
temp=insert(m,temp);
break;
case 2:
temp=delet(temp);
break;
case 3:
display(temp);
break;
case 4:
exit(0);
break;
}
}
}

