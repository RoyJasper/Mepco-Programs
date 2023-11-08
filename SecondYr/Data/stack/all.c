#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
char data;
struct node *next;
};
typedef struct node * stack;
void push(char,stack);
char pop(stack);
int isempty(stack);
void makeempty(stack);
void display(stack);
int paranthesis(char[],stack);
void infix(char[],stack);
int priority(char);

//#include"h.h"
main()
{
int a,i,j,v,choice;
char b,c[20],d[20],e[20];
stack top;
top=(stack)malloc(sizeof(struct node));
top->next=NULL;
while(1)
{

printf("\nenter the choice\n1.Push\n2.Pop\n3.Isempty\n4.Makeempty");
printf("\n5.Display\n6.Paranthesis");
printf(" \n7.Infix to postfix`\n8.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter the character");
scanf("%s",&b);
push(b,top);
break;
case 2:
b=pop(top);
printf("\n%c is Deleted",b);
break;
case 3:
i=isempty(top);
if(i==1)
{
printf("\nStack is Empty");
}
else
{
printf("\nStack is not empty");
}
break;
case 4:
makeempty(top);
break;
case 5:
display(top);
break;
case 6:
printf("\nEnter the expression");
scanf(" %s",d);
v=paranthesis(d,top);
break;
case 7:
printf("\nEnter the expression");
scanf(" %s",c);
infix(c,top);
break;
case 8:
exit (0);
}
}
}
//#include"h.h"
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
stack t;
char a;
t=top->next;
top->next=top->next->next;
a=t->data;
free(t);
return a;
}
int isempty(stack top)
{
if(top->next==NULL)
{
return 1;
}
else
{
return 0;
}
}
void makeempty(stack top)
{
int a;
while(top->next!=NULL)
{
a=pop(top);
printf("%c",a);
}
}
void display(stack top)
{
stack t;
t=top->next;
while(t!=NULL)
{
printf("%c",t->data);
t=t->next;
}
}
int paranthesis(char d[20],stack top)
{
char x,t;
int c,i=0;
while(d[i]!='\0')
{
if(isalnum(d[i])||d[i]=='+'||d[i]=='-'||d[i]=='*'||d[i]=='/')
{
i++;
continue;
}
if(d[i]=='['||d[i]=='('||d[i]=='{')
{
t=d[i];
push(t,top);
i++;
}
else if(d[i]==']'||d[i]==')'||d[i]=='}')
{
c=isempty(top);
if(c==1)
{
printf("\nMissing of open paranthesis");
return 0;
}
else
{
x=pop(top);
if(x=='('&&d[i]==')')
{
i++;
continue;
}
else
if(x=='['&&d[i]==']')
{
i++;
continue;
}
else
if(x=='{'&&d[i]=='}')
{
i++;
continue;
}
else
printf("\nMiss match of paranthesis");
return 0;
}
}
}
if(!isempty(top))
{
printf("\nMissing of closing paranthesis");
makeempty(top);
return 0;
}
else
{
printf("Valid expression");
return 0;
}
}
void infix(char b[50],stack top)
{
int i,q,j;
char t,d,f,x,g,c;
while(b[i]!='\0')
{
if(isalnum(b[i]))
{
printf("%c",b[i]);
i++;
}
else if(b[i]=='('||b[i]=='{'||b[i]=='[')
{
push(b[i],top);
i++;
}
else if(b[i]==')'||b[i]=='}'||b[i]==']')
{
c=pop(top);
while(d!='('||d!='{'||d!='[')
{
printf("%c",d);
c=pop(top);
i++;
}
if(d=='('||d=='{'||d=='[')
i++;
}
else
{
if(isempty(top))
{
if(b[i]=='*'||b[i]=='+'||b[i]=='-'||b[i]=='/')
{
push(b[i],top);
i++;
}
}
else
{
g=pop(top);
if(g=='*'||g=='+'||g=='-'||g=='/')
{
if(priority(g)>=priority(b[i]))
{
push(b[i],top);
printf("%c",g);
i++;
}
else
{
push(g,top);
push(b[i],top);
i++;
}
}
else
{
//push(g,top);
//push(b[i],top);
i++;
}
}
}
}
makeempty(top);
}
int priority(char x)
{
if(x=='-')
return 0;
else if(x=='+')
return 1;
else if(x=='*')
return 2;
else if(x=='/')
return 3;
}


