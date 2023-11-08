#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node* queue;
void enqueue(int,queue);
void depueue(queue,queue);
int isempty(queue,queue);
void makeempty(queue,queue);
void display(queue);
int search(queue,int);
void jp(int,int,queue,queue);
