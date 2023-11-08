#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *left;
struct node *right;
int height;
};
typedef struct node * avl;
avl insert(int,avl);
int height(avl);
avl srl(avl);
avl drl(avl);
avl drr(avl);
avl srr(avl);
void search(int,avl);
void inorder(avl);
void preorder(avl);
void postorder(avl);
int max(int,int);

