#include"hash.h"
void insert(list head,int x)
{
list temp;
temp=(list)malloc(sizeof(struct node));
temp->data=x;
temp->next=head->next;
head->next=temp;
}
list preadd(list head,int x)
{
list t;
t=head;
while(t!=NULL)
{
if(t->next->data==x)
{
return t;
}
t=t->next;
}
return t;
}
void display(list head[10])
{
int i,k=0;
list t;
for(i=0;i<10;i++)
{
t=head[i]->next;
while(t!=NULL)
{
printf("%d\n",t->data);
k++;
t=t->next;
}
}
if(k==0)
printf("empty");
}
void deletion(list head,int x)
{
int i,n;
list t,k;
n=search(head,x);
if(n==0)
printf("not present");
else
{
t=preadd(head,x);
k=t->next;
t->next=t->next->next;
free(k);
}
}
int search(list head,int x)
{
list t;
t=head->next;
while(t!=NULL)
{
if(t->data==x)
{
return 1;
}
t=t->next;
}
return 0;
}

