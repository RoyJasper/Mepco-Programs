
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node *left;
left insert(int,left);
left delet(left);
left merge(left,left);
static left ins(left,left);
left swap(left);
void display(left);
