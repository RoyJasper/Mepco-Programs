#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
 char data;
 struct node *next;
};
typedef struct node *stack;
void push(char[],stack);
void pop(stack);
void isempty(stack);
void display(stack);
void makeempty(stack);
stack postfix(char[],stack);
void balancing(char[],stack);
int priority(int); 
