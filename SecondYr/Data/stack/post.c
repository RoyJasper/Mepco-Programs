#include<stdlib.h>
#include<stdio.h>
struct node1
{
 int eta;
 struct node1*next1;
 };
typedef struct node1*stack1;
void push1(int,stack1);
int pop1(stack1);
int calc(int,int,char);
void push1(int x,stack1 top1)
{
 stack1 temp;
 temp =(stack1)malloc(sizeof(struct node1));
 temp->eta=x;
 temp->next1=top1->next1;
 top1->next1=temp;
 }
int pop1(stack1 top1)
{
 static int j=0;
 int x;
 stack1 k;
 k=top1->next1;
 top1->next1=top1->next1->next1;
 x=k->eta;
 free(k);
 return x;
 }
main()
{
 int g,p,q,r,i=0,j,m;
 char c[20],u;
 stack1 top1;
 top1=(stack1)malloc(sizeof(struct node1));
 top1->next1='\0';
   printf("Enter postfix expression");
        scanf("%s",c);
        while(c[i]!='\0')
        {
         u=c[i];
         if(isalpha(u))
         { printf("Enter value for %c\t",u);
           scanf("%d",&m);
           push1(m,top1);}
           else if((u=='+')||(u=='-')||(u=='*')||(u=='/'))
           {
            if((q=pop1(top1))&&(p=pop1(top1)))
            push1(calc(p,q,u),top1);
            else
            printf("Error in calculation\n");
            }
          else
          continue;
          i++;
         }
        r=pop1(top1);
        if(top1->next1=='\0')
        printf("total answer is %d\n",r);
        else
        printf("Wrong epression\n");
 }
int calc(int p,int q,char u)
{
  switch(u)
  {
    case '+': return p+q;
    case '-': return p-q;
    case '*': return p*q;
    case '/': return p/q;
     }}
