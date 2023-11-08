#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node * left;
struct node * right;
};
typedef struct node * bst;
bst insert(int ,bst);
bst deletion(int ,bst);
bst findmax(bst);
void inorder(bst);
void preorder(bst);
void postorder(bst);
