#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 int data;
 struct node*queue;
};
typedef struct node*queue;
void enqueue(int,queue);
int dequeue(queue,queue);
int isempty(queue,queue);
void makeempty(queue,queue);
void search(queuq,queuqe,int);
