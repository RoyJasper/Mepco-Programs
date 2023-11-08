#include"headex3.h"
void enqueue(int x,queue rear)
{
	queue temp;
	temp=(queue)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;
}
void dequeue(queue front,queue rear)
{
	queue k;
	if(front->next==NULL)
		printf("Queue is empty");
	else
	{
		k=front->next;
		printf("%d",k->data);
		front->next=front->next->next;
	}
	if(front->next==NULL)
	{
		rear=front;
		printf("Empty");
	}
	free(k);
}
int isempty(queue front,queue rear)
{
	if(front==rear)
		return 1;
	else
		return 0;
}
void makeempty(queue front,queue rear)
{
	while(front.next!=NULL)
		dequeue(front,rear);
}
void display(queue front)
{
	queue t;
	t=front->next;
	while(t!=NULL)
	{
		printf("%d",t.data);
		t=t->next;
	}
}
int search(queue front,int x)
{
	queue t=front->next;
	while(t!=NULL)
		if(t->data==x)
			return 1;
	return 0;
}
void jp(int k,int n,queue front,queue rear)
{
	queue a,b;
	rear->next=front->next;
	a=front;
	for(int i=0;i<n-1;i++)
	{
		for(j=1;j<k;j++,a=a->next);
		b=a->next;
		a->next=a->next->next;
		free(b);
	}
	printf("%d",a->data);
}