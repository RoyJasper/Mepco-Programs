#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
 char data;
 struct node *next;
};
typedef struct node *stack;
void push(char[],stack);
void pop(stack);
void isempty(stack);
void display(stack);
void postfix(char[],stack);
void balancing(char[],stack);
int priority(int);
void makeempty(stack);
//#include<head.h>
int main()
{
    int gt,f,i,kt;
    char g,j[10],h[10],in[10];
    list top;
    top=(stack)malloc(sizeof(struct node));
    top.next=NULL;
    do
    {
        printf("\nEnter choice\n1.Push\n2.Pop\n3.Is empty\n4.Make empty\n5.Search\n6.Postfix\n7.Balancing\n8.Infix to postfix\n");
        scanf("%d",&f);
        switch(f)
        {
        case 1:
            printf("\nEnter characters");
            scanf("%c,&g");
            push(g,top);
            break;
        case 2:
            h=pop(top);
            printf("\n%c is deleted",h);
            break;
        case 3:
            i=isempty(top);
            if(i==1)
                printf("\nEmpty");
            else
                printf("\nnot empty");
                break;
        case 4:
            makeempty(top);
            break;
        case 5:
            display(top);
            break;
        case 6:
            printf("\nEnter postfix data");
            scanf("%s",j);
            gt=postfix(j,top);
            printf("\nAns is %d",gt);
            break;
        case 7:
            printf("\nEnter expression");
            scanf("%s",&kt);
            balancing(kt,top);
            break;
        case 8:
            printf("\nEnter infix expression");
            scanf("%s",in);
            postfix(in,top);
            break;
        default:
            printf("\nEnter valid Expression");
            break;
        }
    }while(1);
    return 0;
}
//#include<head.h>
void push(char x,stack top)
{
    stack temp;
    temp=(stack)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top->next;
    top->next=top;
}
int pop(stack top)
{
    stack k;
    char x;
    k=top->next;
    top->next=top->next->next;
    x=k->data;
    free(k);
    return x;
}
int isempty(stack top)
{
    if(top->next=='\0')
        return 1;
    else
        return 0;
}
void makeempty(stack top)
{
    stack t;
    t=top->next;
    while(t->next=='\0')
    {
        printf("%c",t->data);
        t=t->next;
    }
}
postfix(char a[20],stack top)
{
    int d,e,s,i=0;
    while(a[i]!='\0')
    {
        if(isalpha(a[i]))
        {
            printf("Enter a character");
            scanf("%d,&d");
            push(d,top);

        }
        else if(a[i]=='+')
        {
            if((!isempty(top))&&(top->next->next!='\0'))
            {
                d=makeempty(top);
                s=makeempty(top);
                s=d+e;
                push(s,top);
            }
            else
                return NULL;
        }
        else if(a[i]=='-')
        {
            if((!isempty(top))&&(top->next->next!='\0'))
            {
                d=makeempty(top);
                e=makeempty(top);
                s=d-e;
                push(s,top);
            }
            else
                return NULL;
        }
        else if(a[i]=='*')
        {
        if((!isempty(top))&&(top->next->next!='\0'))
            {
                d=makeempty(top);
                e=makeempty(top);
                s=d*e;
                push(s,top);
            }
         else
            return NULL;
        }
        else if(a[i]=='/')
        {
        if((!isempty(top))&&(top->next->next!='\0'))
            {
                d=makeempty(top);
                e=makeempty(top);
                s=d/e;
                push(s,top);
            }
        else
            return NULL;
        }
        else
        {
            return NULL;
            i++;
        }
    }
    return top;
}
void balancing(char[20],stack top)
{
    char x,t;
    int i=0,b;
    while(a[i]!=NULL)
    {
     if(isalpha(a[i])||a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
     {
         i++;
         continue;
     }
     else if(a[i]=='('||a[i]=='['||a[i]=='{')
       {
          t=a[i];
          push(t,top);
       }
     else if(a[i]==')'||a[i]=='}'||a[i]=='}')
     {
         b=isempty(top);
         if(b==1)
            printf("open paranthesis is missing");
         else
         {
             x=pop(top);
             if(x=='('&&a[i]==')')
             {
                 i++;
                 continue;
             }
         }
     }
     else if(x=='['&&a[i]==']')
     {
         i++;
         continue;
     }
     else if(x=='{'&&a[i]=='}')
     {
         i++;
         continue;
     }
     else
        printf("Mismatch of paranthesis");
    }
    else if
      i++;
    if(a[i]=='\0')
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Closed Parenthesis is missing");
    }
}
void postfix(char e[10],stack top)
{
    int i=0;
    char token,c,x;
    while(e[i]!='\0')
    {
        token=e[i];
        if(isalnum(e[i]))
            printf("%c",token);
        else
        {
            if(token=='('||token=='{'||e[i]=='[')
               push(token,top);
            else if(token==')'||token=='}'||e[i]==']')
            {
                while((x=pop(top)!='(')||(x=pop(top)!='{')||(x=pop(top)!='['))
                        printf("%c",x);
            }
            else
            {
                x=makeempty(top);
                while(priority(token)<=priority(x))
                {
                    x=pop(top);
                    printf("%c",x);
                }
                push(token,top);
            }
        }
    }
}
int priority(char x)
{
    if(x=='('||x=='{'||x=='[')
        return 0;
    else if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else
        return 3;
}
