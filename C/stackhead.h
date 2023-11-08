#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
char data;
struct node *next;
};
typedef struct node * stack;
void push(char,stack);
char pop(stack);
int isempty(stack);
void makeempty(stack);
void display(stack);
int paranthesis(char[],stack);
void infix(char[],stack);
int priority(char);
void postfix(char[],stack);

