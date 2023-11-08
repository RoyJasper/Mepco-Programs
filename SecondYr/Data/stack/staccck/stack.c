#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct node
{
 char data;
 struct node*next;
 };
typedef struct node*stack;
void push(char,stack);
char pop(stack);
int isempty(stack);
void makempty(stack);
int balancing(char[],stack);
void display(stack);
void intopost(char [],char [],stack);
int pope(stack);
int priority(char p[9][2],char);
 char ip[9][2]={{'(',9},{')',0},{'\0',0},{'+',1},{'-',1},{'*',2},{'/',2},{'%',2},{'^',3}};
  char sp[9][2]={{'(',0},{')',-1},{'\0',0},{'+',1},{'-',1},{'*',2},{'/',2},{'%',2},{'^',3}};
main()
{
 int x,z,o,f,i=0;
 char c[20],h,e,y,d[20],u;
stack top;
 top=(stack)malloc(sizeof(struct node));
 top->next='\0';
 printf("\n\n\t\t\tWELCOME TO STACK FUNCTION\n\n\n");
do
{
 printf("\nENTER\n1.PUSH\n2.POP\n3.IS EMPTY\n4.MAKE EMPTY\n5.DISPLAY\n6.POSTFIX\n7.BALANCING\n8.INFIX TO POST\n9.EXIT\n");
 scanf("%d",&x);
 switch(x)
 {
  case 1:
        printf("ENTER A CHARACTER\n");
        scanf(" %c",&h);
        push(h,top);
        break;
  case 2:
        e=pop(top);
        printf("%c IS DELETED\n",e);
        break;
  case 3:
        i=isempty(top);
        if(i==1)
        printf("STACK IS EMPTY\n");
        else
        printf("STACK IS NOT EMPTY\n");
        break;
 case 4:
       makempty(top);
       break;
 case 5:
       display(top);
       break;
 case 6:
       
 case 7:
       printf("ENTER THE EXPRESSION\n");
       scanf("%s",c);
       o=balancing(c,top);
       break;
 case 8:
      printf("ENTER THE EXPRESSION\n");
      scanf("%s",c);
      intopost(c,d,top);
      printf("%s",d);
      break;
 case 9:
       exit(0);
    }
  }
while(1);
}
void push(char x,stack top)
{
 stack temp;
 temp =(stack)malloc(sizeof(struct node));
 temp->data=x;
 temp->next=top->next;
 top->next=temp;
 }
char pop(stack top)
{
 static int j=0;
 j=isempty(top);
 if(j==1)
{ printf("EMPTY STACK NOT TO POP");}
 char x;
 stack k;
 k=top->next;
 top->next=top->next->next;
 x=k->data;
 free(k);
 return x;
 }
int isempty(stack top)
{
 if(top->next=='\0')
 return 1; //1 imples empty
 else
 return 0;
 }
void makempty(stack top)
{
 int x;
 stack t;
 while(top->next!='\0')
 {
  x=pop(top);
  t=t->next;
  }
 }
void display(stack top)
{
 stack t;
 t=top->next;
 while(t!='\0')
 {
  {
  printf("%c\t",t->data);
  t=t->next;
 }
}
}
int pope(stack top)
{
 char x;
 stack k;
 if(top->next=='\0')
 return -1;
 else
 {
 k=top->next;
 top->next=top->next->next;
 x=k->data;
 free(k);
 return 0;
  }
 }
int balancing(char c[],stack top)
{
 int i,j,item,len,r,s,t,k;
 char ob[]={'[','{','('};
 char cb[]={']','}',')'};
 char u,f;
 len=strlen(c);
 for(i=0;i<len;i++)
  {
    for(j=0,k=0;j<3;j++,k++)
    {
     if(c[i]==ob[j])
      {
       push(c[i],top);
       s=j;
       break;
        }
      else if(c[i]==cb[k])
      { 
         u=isempty(top);
         if(u==1)
         { printf("OPEN PARANTHESIS WAS MISSING\n"); return 0;}
         else
         f=pop(top);
         t=k;
         if(s!=t)
         { printf("MISS MATCH\n");return 0;}
         }
        }
      }
      r=isempty(top);
      if(r!=1)
      printf("CLOSE PARANTHESIS WAS MISSING\n");
      else
      printf("VALID EXPRESSION\n");
     }
void intopost(char c[],char d[],stack top)
{
 char k,y;
 int i=0,j=0,f,g;
 push('\0',top);
 while((k=c[j++])!='\0')
 {
  if((k=='{')||(k=='}')||(k=='[')||(k==']')||(k=='0')||(k=='('))
  continue;
  if(isalpha(k))
  d[i++]=k;
  else if(k=='(')
  push(k,top);
  else if(k==')')
  {
  y=pop(top);
  while(y!='(')
  {
   d[i++]=y;
   y=pop(top);
   }
   }
 else
 {
  y=pop(top);
  f=priority(sp,y);
  g=priority(ip,k);
  while(sp[f][1]>=ip[g][1])
  {
   d[i++]=y;
    y=pop(top);
    f=priority(sp,y);
    }
   push(y,top);
   push(k,top);   
 }
 }
k=pop(top);
d[i++]=k;
k=pop(top);
d[i++]=k;
}
int priority(char p[9][2],char x)
{
 int a;
 for(a=0;a<9;a++)
 { if(p[a][0]==x)
   return a;}
   }
