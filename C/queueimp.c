#include"queuehead.h"
queue enqueue(int a,queue rear)
{
queue temp;
temp=(queue)malloc(sizeof(struct node));
temp->data=a;
rear->next=temp;
temp->next=NULL;
rear=temp;
printf("IT IS INSERTED SUCCESSFULLY");
return rear;
}
queue dequeue(queue front,queue rear)
{
queue k;
int a,x;
a=isempty(front,rear);
if(a==1)
{
printf("NOT POSSIBLE");
return NULL;
}
else
{
k=front->next;
x=k->data;
front->next=front->next->next;
printf("%d IS DELETED",x);
if(front->next==NULL)
rear=front;
free(k);
return rear;
}
}
int isempty(queue front,queue rear)
{
if(rear==front)
{
return 1;
}
else 
return 0;
}
void makeempty(queue front,queue rear)
{
int a;
queue k;
while(front->next!=NULL)
{
rear=dequeue(front,rear);
}
printf("QUEUE IS EMPTY");
}
void display(queue front,queue rear)
{
queue k;
k=front->next;
while(k!=NULL)
{
printf("%d",k->data);
k=k->next;
}
}
void search(queue front,queue rear,int x)
{
queue k;
k=front->next;
while(k!=NULL)
{
if(k->data==x)
{
printf("IT IS PRESENT");
break;
}
else
k=k->next;
}
}
void palindrome(char a[10])
{
int size,rear,front=0,i=0,c,n;
n=strlen(a);
rear=n-1;
size=n;
while(i<n)
{
if(a[front]==a[rear])
{

front++;
rear--;
i++;
c=1;
}
else
{
c=0;
break;
}
}
if(c==0)
{
printf("IT IS NOT PALINDROME");
}
else
{
printf("IT IS PALINDROME");
}
}

