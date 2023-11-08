#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *queue;
queue enqueue(int,queue);
int dequeue(queue,queue);
int isempty(queue);
void makeempty(queue,queue);
void display(queue);
void search(queue,int);
void prob(int,int,queue,queue);

//#include"head4.h"
queue enqueue(int x,queue rear)
{
queue temp;
temp=(queue)malloc(sizeof(struct node));
temp->data=x;
temp->next=rear->next;
rear->next=temp;
rear=temp;
printf("\nQueue enque is done ");
return rear;
}
int dequeue(queue front,queue rear)
{
queue k;
int a,b;
k=front->next;
b=front->data;
front->next=front->next->next;
if(front->next=='\0')
rear=front;
free(k);
return b;
}
int isempty(queue front)
{
if(front->next=='\0')
return 1;
else
return 0;
}
void makeempty(queue front,queue rear)
{
int c;
while(front->next!='\0')
{
c=dequeue(front,rear);
}
printf("\nqueue is now empty");
}
void display(queue front)
{
queue  q;
q=front->next;
while(q!='\0')
{
printf("\t%d",q->data);
q=q->next;
}
}
void search(queue front,int x)
{
queue q;
q=front->next;
while(q!='\0')
{
if(q->data==x)
{
printf("\nSearch element is present");
break;
}
else
q=q->next;
}
if(q=='\0')
printf("\nSearch element is not present");
}
void prob(int k,int n,queue front,queue rear)
{
 int i,j;
 queue a,b;
 rear->next=front->next;
 a=front;
 for(i=0;i<n-1;i++)
 {
  for(j=1;j<k;j++)
   a=a->next;
   b=a->next;
  a->next=a->next->next;
  free(b);
 }
  printf("winning number is %d",a->data);

}
/*void prob(int m,queue front,queue rear)
{
int b,i,j;
queue t,k;
rear->next=front->next;
t=front;
printf("\nEnter the random position");
scanf("%d",&b);
for(i=0;i<m-1;i++)
{
for(j=1;j<b;j++)
{
t=t->next;
k=t->next;
t->next=t->next->next;
free(k);
}
}
printf("\nSuccessive data is %d",t->data);
}
//t=front->next;
//for(i=0;i<b;i++)
//{
//t=t->next;
//}
//printf("\nSuccessive data is %d",t->next->data);
//}
//t=front->next;
//for(i=0;i<b;i++)
//{
//t=t->next;
//}
//printf("\nSuccessive Data is %d",t*/
//#include"head4.h"
main()
{
int n,x,a,b,c,k=0,u;
queue rear,front;
front=(queue)malloc(sizeof(struct node));
front->next='\0';
rear=front;
while(1)
{
printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Isempty\n4.Makeempty\n5.Display\n6.Search\n7.To Solve josephus problem\n8.To exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
printf("\nEnter the element to be inserted");
scanf("%d",&x);
rear=enqueue(x,rear);
k=k+1;
break;
case 2:
a=dequeue(front,rear);
//printf("%d",a);
printf("\nSuccessfully deleted");
break;
case 3:
b=isempty(front);
if(b==1)
printf("\nQueue is empty");
else
printf("\nQueuei is not empty");
break;
case 4:
makeempty(front,rear);
break;
case 5:
display(front);
break;
case 6:
printf("\nEnter Search element");
scanf("%d",&c);
search(front,c);
break;
case 7:
printf("\nEnter the random position");
scanf("%d",&u);
prob(u,k,front,rear);
break;
case 8:
exit(0);
default:
printf("\nInvalid input");
break;
}
}
}
