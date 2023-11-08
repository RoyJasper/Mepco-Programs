#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct student
{
 int no;
 char name[50];
 struct student *next;
};
static int kk=1;
typedef struct student * list;
void insert(int,int,char[],list);
int search(int,char[],list);
void display(list);
void delet(list,int,char[]);
list preeleadd(int,list);
int isempty(list);
int locate(int,list);
int retrieve(int,list);
//void reverse(list);
void swap(int,int,list);

int main()
{
 int n,p,a,b,c,test=0,choice,y,d,e;
 list head;
 char nam[20],f[20],g[20];
 head=(list)malloc(sizeof(struct student));
 while(1)
 {
  printf("\nEnter choice\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Isempty\n6.Locate\n7.Retrive\n8.Swap\n9.Exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:printf("\nEnter no ,position ,name");
         scanf("%d%d%s",&n,&p,nam);
         if(test==n)
         {
            test++;
            insert(n,p,nam,head);
         }
         else
            printf("Enter no in ascending order");

         break;
  case 2:printf("\nEnter no and name");
         scanf("%d%s",&n,g);
         a=search(n,g,head);
         if(a==1)
           printf("\nPresent");
         else
           printf("\nnot present");
         break;
  case 3:display(head);
         break;

  case 4:printf("\nEnter no and name");
         scanf("%d%s",&n,f);
        delet(head,n,nam);
         break;
  case 5:b=isempty(head);
         if(b==1)
          printf("\nEmpty");
         else
           printf("\nNot Empty");
         break;
  case 6:printf("\nEnter the no");
         scanf("%d",&n);
         c=locate(n,head);
         if(c!=0)
          printf("\nThe position is %d",c);
         else
          printf("\nnot present");
         break;
  case 7:printf("\nEnter position");
         scanf("%d",&p);
         y=retrieve(p,head);
         printf("\nnumber is %d",y);
         break;
 case 8://printf("\nREVERSAL IN PROCESS");
        printf("Enter 2 position");
        scanf("%d%d",&d,&e);
        swap(d,e,head);
        printf("\nSwaped");
        break;
 case 9:exit(0);
}
}
}
void swap(int n1,int n2,list head)
{
 if(n1<=kk&&n2<=kk)
 {
  list t,k,s;
  int i;
  t=head;
  k=head;
  for(i=1;i<n1;i++)
   t=t->next;
  for(i=1;i<n2;i++)
   k=k->next;
  s=k->next->next;
  k->next->next=t->next->next;
  t->next->next=s;
  s=t->next;
  t->next=k->next;
  k->next=s;
 }
 else
  printf("Enter appropriate postion\n");
}


void insert(int n,int p,char nam[20],list head)
{
 int i;
 list temp,t;
 temp=(list)malloc(sizeof(struct student));
 temp->no=n;
 strcpy(temp->name,nam);
 t=head;
 for(i=0;i<p-1;i++)
 {
  t=t->next;
 }
  temp->next=t->next;
  t->next=temp;
 printf("\nInsertion is successfull \n");
}
int search(int n,char nam[20],list head)
{
 list t;
 t=head->next;
 while(t!=NULL)
 {
 if(t->no==n)
  return 1;
 else
  t=t->next;
 }
 if(t=='\0')
  return 0;
}


void display(list head)
{
 list t;
 t=head->next;
 while(t!='\0')
 {
  printf("the student number is %d\n",t->no);
  printf("the name of student is  %s\n",t->name);
  t=t->next;
 }
}

void delet(list head,int n,char nam[50])
{
 int x;
 list t,k;
 x=search(n,nam,head);
 if(x==1)
 {
  t=preeleadd(n,head);
  k=t->next;
  t->next=t->next->next;
  free(k);
 }
 else
  printf("\nElement is not present\n");
}


list preeleadd(int n,list head)
{
 list t;
 t=head->next;
 while(t!=NULL)
 {
  if(t->no==n)
   return t;
  else
   t=t->next;
 }
}

int isempty(list head)
{
 if(head->next==NULL)
  return 1;
  else
  return 0;
}


int locate(int n,list head)
{
 list t;
 int y=1;
 t=head->next;
 while(t!=NULL)
 {
  if(t->no==n)
  {
   return y;
   break;
  }
  else
  {
   t=t->next;
   y=y+1;
  }
 }
 }


int retrieve(int p,list head)
{
 list t;
 int i;
 t=head;
 for(i=0;i<p;i++)
 {
  t=t->next;
 }
  return t->no;

}

/*void reverse (list head)
{
list t,k,r;
t=head;
while(t->next!=NULL)
{
t=t->next;
}
r=t;
while(head->next->next!=NULL)
{
k=head->next;
while(k!=NULL)
{
if(k->next==t)
{
t->next=k;
k->next=NULL;
}
else
k=k->next;
}
t=k;
}
head->next=r;
}
void swap(int a,int b,list head)
{
list k,t,s;
int i;
t=head;
for(i=0;i<a-1;i++)
 {
  t=t->next;
 // k=head;
 }
for(i=0;i<b-1;i++)
  k=k->next;
s=k->next->next;
k->next->next=t->next->next;
t->next->next=s;
s=t->next;
t->next=k->next;
k->next=s;
}
?*/
