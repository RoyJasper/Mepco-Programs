#include"stackhead.h"
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
printf("Missing of open paranthesis");
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
printf("Miss match of paranthesis");
return 0;
}
}
}
if(!isempty(top))
{
printf("Missing of closing paranthesis");
makeempty(top);
return 0;
}
else
{
printf("VALID EXPRESSION");
return 0;
}
}
void postfix(char a[20],stack top)
{
int e,i,s,x,d;
while(a[i]!='\0')
{
if(isalpha(a[i]))
{
printf("Enter the value of %c:",a[i]);
scanf("%d",&d);
push(d,top);
i++;
}
else if(a[i]=='+')
{
d=pop(top);
e=pop(top);
s=d+e;
push(s,top);
i++;
}
else if(a[i]=='-')
{
d=pop(top);
e=pop(top);
s=e-d;
push(s,top);
i++;
}
else if(a[i]=='*')
{
d=pop(top);
e=pop(top);
s=d*e;
push(s,top);
i++;
}
else if(a[i]=='/')
{
d=pop(top);
e=pop(top);
s=e/d;
push(s,top);
i++;
}
}
x=pop(top);
printf("The Answer is %d",x);
}
void infix(char b[50],stack top)
{
int i=0,q,j;
char t,d,f,x,g,c;
while(b[i]!='\0')
{
if(isalpha(b[i]))
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
d=pop(top);
while(d!='('||d!='{'||d!='[')
{
printf("%c",d);
d=pop(top);
}
i++;
}
else
{
if(isempty(top))
{
push(b[i],top);
i++;
}
else
{
begin:
g=pop(top);
//if(g=='*'||g=='+'||g=='-'||g=='/')
//{
if(priority(g)>=priority(b[i]))
{
//push(b[i],top);
printf("%c",g);
if(!isempty(top))
{
goto begin;
}
push(b[i],top);
i++;
}
else
{
push(g,top);
push(b[i],top);
i++;
}
//}
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

