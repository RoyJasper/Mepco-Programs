#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *list;
void insert(list,int);
void deletion(list,int);
void display(list[]);
int search(list,int);
list preadd(list,int);
//#include"hash.h"
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
printf("[%d]==--> %d \n",i,t->data);
k++;
t=t->next;
}
}
if(k==0)
printf("Empty");
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
//#include<malloc.h>
//#include<stdlib.h>
int main()
{
list a[10],head;
head=(list)malloc(sizeof(struct node));
head->next=NULL;
int l;
int i,s,r,t,n,y,f;
for(i=0;i<=10;i++)
{
a[i]=(list)malloc(sizeof(struct node));
a[i]->next=NULL;
}
//printf("\n\n\n\t\tWELCOME TO HASHING\n");
while(1)
{
printf("\nEnter your choice");
printf("\n1.insert \n2.search \n3.display \n4.delete \n5.exit ");
scanf("%d",&y);
switch(y)
{
case 1:
printf("\nEnter the number of numbers to be entered");
scanf("%d",&l);
for(i=0;i<l;i++)
{
printf("\nEnter %d no ",(i+1));
scanf("%d",&n);
s=n%10;
insert(a[s],n);
printf("\n Inserted ");
}
break;
case 2:
printf(" Enter no ");
scanf("%d",&f);
s=f%10;
r=search(a[s],f);
if(r==0)
printf("not present");
else
printf("present");
break;
case 3:
display(a);
break;
case 4:
printf(" Enter no ");
scanf("%d",&r);
s=r%10;
deletion(a[s],r);
break;
case 5:
exit(0);
}
}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                               
