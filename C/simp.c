#include"slist.h"
int insert(int n,int p,char na[50],list head)
{
static int f=1;
int i;
list temp,t;
if(p==f)
{
temp=(list)malloc(sizeof(struct student));
temp->stid=n;
strcpy(temp->name,na);
t=head;
for(i=0;i<p-1;i++)
{
t=t->next;
}
temp->next=t->next;
t->next=temp;
f++;
return (f);
printf("THE DATA IS INSERTED SUCCESSFULLY");
}
else
printf("ERROR");
}
int search(int n,list head)
{
list t;
t=head->next;
while(t!=NULL)
{
if(t->stid==n)
{
return 1;
}
else
{
t=t->next;
}
}
//if(t==NULL)
{
return 0;
}
}
void display(list head)
{
list t;
t=head->next;
while(t!=NULL)
{
printf("\nTHE STUDENT ID IS %d",t->stid);
printf("\nTHE STUDENT NAME IS %s",t->name);
t=t->next;
}
}
void delet(int n,list head)
{
int r;
list t,k;
r=search(n,head);
if(r==1)
{
printf("\nTHE ELEMENT IS PRESENT");
t=preeleadd(n,head);
k=t->next;
t->next=t->next->next;
free(k);
}
else
{
printf("\nTHE ELEMENT IS NOT PRESENT");
}
}
list preeleadd(int n,list head)
{
list t;
t=head->next;
while(t!=NULL)
{
if(t->stid==n)
{
return t;
}
else
{
t=t->next;
}
}
}
int isempty(list head)
{
if(head->next==NULL)
{
return 0;
}
else
{
return 1;
}
}
int locate(int n,list head)
{
list t;
int a=1;
t=head->next;
while(t!=NULL)
{
if(t->stid==n)
{
return a;
}
else
{
t=t->next;
a++;
}
}
if(t==NULL)
{
return 0;
}
}
list retrive (int p,list head)
{
list t;
int i;
t=head->next;
for(i=0;i<p-1;i++)
{
t=t->next;
}
return (t);
}


void reverse (list head)
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
k=head;
while(k!=NULL)
{
if(k->next==t)
{
t->next=k;
k->next=NULL;
break;
}
else
k=k->next;
}
t=k;
}
head->next=r;
}

