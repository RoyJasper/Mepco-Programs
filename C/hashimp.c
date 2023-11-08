#include"hashhead.h"
int z=0;
hash create(int n)
{
int i;
hash h;
h=(hash)malloc(sizeof(hash));
h->tablesize=n;
h->l=(list*)malloc(n*sizeof(list));
for(i=0;i<n;i++)
{
h->l[i]=(list)malloc(sizeof(list));
h->l[i]->next=NULL;
}
return h;
}
hash insert(int e,hash head)
{
int z,b,u;
u=e;
b=e%10;
if(head->l[b]->next==NULL)
{
list temp;
temp=(list)malloc(sizeof(struct node));
temp->data=u;
head->l[b]->next=temp;
temp->next=NULL;
z=z+1;
}
else
{
list temp,t;
temp=(list)malloc(sizeof(struct node));
t=head->l[b];
while(t->next!=NULL)
{
t=t->next;
}
temp->data=u;
temp->next=NULL;
t->next=temp;
}
return head;
}
hash delet(int x,hash head)
{
int result,y;
list t,k;
result=search(x,head);
if(result==1)
{
y=x%10;
t=head->l[y];
while(t->next!=NULL)
{
if(t->next->data==x)
{
k=t->next;
t->next=t->next->next;
free(k);
}
else
t=t->next;
}
printf("IT IS DELETED");
}
else
printf("IT IS NOT PRESENT");
return head;
}
void display(hash t)
{
  int i;
	//hash t=head;
  for(i=0;i<t->tablesize;i++)
  {
  printf("\n%d->",i);
	list temp=t->l[i];
    while(temp!=NULL)
		{ 
      printf("%d\t",temp->data);
			temp=temp->next;
		}
  }
//return head;
}
int search(int a,hash head)
{
int i;
for(i=0;i<head->tablesize;i++)
{
while(head->l[i]!=NULL)
{
if(head->l[i]->data==a)
{
return 1;
}
else
{
head->l[i]=head->l[i]->next;
}
}
return 0;
}
}

