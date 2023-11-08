#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
	int height;
};
typedef struct node *avl;
avl insert(int,avl);
avl srl(avl);
avl drl(avl);
avl srr(avl);
avl drr(avl);
int height(avl);
int max(int,int);
void display(avl);
void inorder(avl);
void postorder(avl);
void preorder(avl);
void search(int,avl);
