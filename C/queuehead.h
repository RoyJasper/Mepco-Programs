#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node * next;
};
typedef struct node *queue;
queue enqueue(int,queue);
queue dequeue(queue,queue);
int isempty(queue,queue);
void makeempty(queue,queue);
void search(queue,queue,int);
void palindrome(char[]); 
