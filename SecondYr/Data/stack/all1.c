#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	char data;
	struct node* next;
};
typedef struct node* stack;
void push(char,stack);
char pop(stack);
int isempty(stack);
void makeempty(stack);
void display(stack);
void bpara(char[],stack);
void inpos(char[],stack);
int posteve(char[],stack);
int prio(char);
//#include"headex2.h"
main()
{
	int c,x;
	char ex[50],xe[50];
	stack top;
	top=(stack)malloc(sizeof(struct node));
	top->next='\0';
	while(1)
	{
		printf("\n1]Push\n2]Pop\n3]Check Empty\n4]Make Empty\n5]Display All\n6]Balance Parathesis Check\n7]Infix to Postfix Conversion\n8]Evaluation of Postfix\n9]Exit\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the character:");
			       scanf(" %c",&x);
			       push(x,top);
			       break;
			case 2:x=pop(top);
			       printf("%c",x);
			       break;
			case 3:if(isempty(top))
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
			       scanf("%s",xe);
			       inpos(xe,top);
			       break;
			case 8:printf("Enter the postfix expression:");
			       scanf("%s",ex);
			       x=posteve(ex,top);
						 printf("The Result is %d",x);
			       break;
			case 9:exit(0);
		}

	}
}

//#include"headex2.h"
void push(char x,stack top)
{
	stack temp;
	temp=(stack)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=top->next;
	top->next=temp;
}
char pop(stack top)
{
	stack k;
	k=top->next;
	char a=k->data;
	top->next=top->next->next;
	free(k);
	return a;
}
int isempty(stack top)
{
	if(top->next==NULL)
		return 1;
	else
		return 0;
}
void makeempty(stack top)
{
	char x;
	while(top->next!=NULL)
	{
		x=pop(top);
		printf("%c",x);
	}
}
void display(stack top)
{
	stack t;
	t=top->next;
	while(t!=NULL)
	{
		printf("%C",t->data);
		t=t->next;
	}
}
void bpara(char a[50],stack top)
{
	int i=0,f;
	char x;
	while(a[i]!=0)
	{
		if(isalnum(a[i])||a[i]=='+'||a[i]=='*'||a[i]=='/'||a[i]=='-')
		{
			i++;
			continue;
		}
		else if(a[i]=='('||a[i]=='['||a[i]=='{')
		{
			push(a[i],top);
			i++;
			continue;
		}
		else if(a[i]==')'||a[i]==']'||a[i]=='}')
		{
			if(isempty(top))
			{
				printf("Open paranthesis missing");
				break;
			}
			else
			{
				x=pop(top);
				if(x=='['&&a[i]==']')
				{
					i++;
					continue;
				}
				else if(x=='{'&&a[i]=='}')
				{
					i++;
					continue;
				}
				else if(x=='('&&a[i]==')')
				{
					i++;
					continue;
				}
				else
				{
					printf("Mismatch Paranthesis");
					break;
				}
			}
		}
	}
	if(isempty(top))
		printf("Valid Statement");
	else
		printf("Close paranthesis missins");
}
void inpos(char e[50],stack top)
{
	int i=0;
	printf("%s",e);
	char a;
	while(e[i]!='\0')
	{
		if(isalpha(e[i]))
			printf("%c",e[i]);
		else if(e[i]=='('||e[i]=='['||e[i]=='{')
			push(e[i],top);
		else if(e[i]==')'||e[i]==']'||e[i]=='}')
			while(((a=pop(top))!='(')&&((a=pop(top))!='[')&&((a=pop(top))!='{'))
				printf("%c",a);
		else
		{
			a=pop(top);
			while(prio(e[i])<=prio(a))
			{
				printf("%c",a);
				a=pop(top);
			}
			push(a,top);
			push(e[i],top);
		}
	 i++;
	}
}
int prio(char x)
{
	if(x=='/')
		return 5;
	else if(x=='*')
		return 4;
	else if(x=='+')
		return 3;
	else if(x=='-')
		return 2;
	else
		return 0;
}
int posteve(char a[20],stack top)
{
	int i,d,e,f;
	while(a[i]!='\0')
	{
		if(isalpha(a[i]))
		{
			printf("Enter the value of %c :",a[i]);
			scanf("%d",&d);
			push(d,top);
		}
		else if(a[i]=='+')
		{
			d=pop(top);
			e=pop(top);
			f=d+e;
			push(f,top);
		}
		else if(a[i]=='-')
    {
      d=pop(top);
      e=pop(top);
      f=e-d;
      push(f,top);
    }
		else if(a[i]=='*')
    {
      d=pop(top);
      e=pop(top);
      f=d*e;
      push(f,top);
    }
	  else if(a[i]=='/')
    {
      d=pop(top);
      e=pop(top);
      f=e/d;
      push(f,top);
    }
		else
			 return NULL;
		i++;
	}
return top->next->data;
}
