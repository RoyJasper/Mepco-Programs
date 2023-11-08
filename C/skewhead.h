#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node *lh;
lh merge(lh,lh);
static lh merge1(lh,lh);
lh insert(int,lh);
lh delet(lh);
void display(lh);
lh swapchild(lh);
