#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node *bst;
bst insert(int,bst);
bst removeit(int,bst);
bst findmin(bst);
bst findmax(bst);
void inorder(bst);
void preorder(bst);
void postorder(bst);
void searchit(bst,int);
