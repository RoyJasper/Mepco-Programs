#include"stackhead.h"
main()
{
int a,i,j,v,choice,r;
char b,c[20],d[20],e[20];
stack top;
top=(stack)malloc(sizeof(struct node));
top->next=NULL;
while(1)
{
printf("\n1.PUSH\n2.POP\n3.ISEMPTY\n4.MAKEEMPTY\n5.DISPLAY\n6.PARANTHESIS\n7.INFIXTOPOSTFIX\n8.POSTFIX EVALUATION\n9.exit\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("ENTER THE CHARACTER");
scanf("%s",&b);
push(b,top);
printf("IT IS INSERTED SUCCESSFULLY");
break;
case 2:
b=pop(top);
printf("%c IS DELETED",b);
break;
case 3:
i=isempty(top);
if(i==1)
{
printf("STACK IS EMPTY");
}
else
{
printf("STACK IS NOT EMPTY");
}
break;
case 4:
makeempty(top);
break;
case 5:
display(top);
break;
case 6:
printf("ENTER THE EXPRESSION");
scanf(" %s",d);
v=paranthesis(d,top);
break;
case 7:
printf("ENTER THE EXPRESSION");
scanf(" %s",c);
//printf("%s",c);
infix(c,top);
break;
case 8:
printf("ENTER THE EXPRESSION");
scanf(" %s",e);
postfix(e,top);
break;
case 9:
exit (0);
}
}
}

