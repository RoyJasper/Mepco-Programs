#include"headex2.h"
main()
{
	int c;
	char ex[50];
	stack top;
	top=(stack)malloc(sizeof(struct node));
	top.next='\0';
	while(1)
	{
		printf("\n1]Push\n2]Pop\n3]Check Empty\n4]Make Empty\n5]Display All\n6]Balance Parathesis Check\n7]Infix to Postfix Conversion\n8]Evaluation of Postfix\n9]Exit\nEnter your choice:");
		scanf("%d",c);
		switch (c)
		{
			case 1:printf("Enter the character:");
			       scanf("%c",&x);
			       push(x,top);
			       break;
			case 2:x=pop(top);
			       printf("%c",x);
			       break;
			case 3:if(isempty(top));
					printf("Empty");
			       else
					printf("Not Empty");
			       break;
			case 4:makeempty(top);
			       break;
			case 5:display(top);
			       break;
			case 6:printf("Enter the expression:");
			       scanf("%s",ex);
			       bpara(ex,top);
			       break;
			case 7:printf("Enter the infix expression:");
			       scanf("%s",ex);
			       inpost(ex,top);
			       break;
			case 8:printf("Enter the postfix expression:");
			       scanf("%s",ex);
			       x=posteve(ex,top);
			       break;
			case 9:exit(0);
		}
	}
}
