#include"avlhead.h"
avl insert (int x,avl t)
{
int d;
if(t==NULL)
{
t=(avl)malloc(sizeof(struct node));
t->data=x;
t->left=NULL;
t->right=NULL;
t->height=0;
return t;
}
else if(x<t->data)
{
t->left=insert(x,t->left);
if(height(t->left)-height(t->right)==2)
{
if(x<t->left->data)
{
t=srl(t);
}
else
{
t=drl(t);
}
}
}
else if(x>t->data)
{
t->right=insert(x,t->right);
if(height(t->left)-height(t->right)==-2)
{
if(x>t->right->data)
{
t=srr(t);
}
else
{
t=drr(t);
}
}
}
d=max(height(t->left),height(t->right));
t->height=d+1;
return t;
}
int height(avl t)
{
if(t==NULL)
{
return -1;
}
else
return t->height;
}
avl srl(avl t1)
{
avl t2;
t2=t1->left;
t1->left=t2->right;
t2->right=t1;
t1->height=max(height(t1->left),height(t1->right))+1;
t2->height=max(height(t2->left),height(t2->right))+1;
return t2;
}
avl drl (avl t1)
{
t1->left=srr(t1->left);
return (srl(t1));
}
avl srr(avl t1)
{
avl t2;
t2=t1->right;
t1->right=t2->left;
t2->left=t1;
t1->height=max(height(t1->left),height(t1->right))+1;
t2->height=max(height(t2->left),height(t2->right))+1;
return t2;
}
avl drr (avl t1)
{
t1->right=srl(t1->right);
return (srr(t1));
}
int max (int b,int c)
{
int a;
a=(b>c)?b:c;
return a;
}
void search(int x,avl t)
{
int c=0;
if(t==NULL)
{
printf("TREE IS EMPTY");
}
else
{
if(x<t->data)
{
search(x,t->left);
}
else if(x>t->data)
{
search(x,t->right);
}
else
{
printf("ELEMENT IS PRESENT");
c=1;
}
}
if(c==0)
{
printf("IT IS NOT PRESENT");
}
}
void inorder(avl t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d",t->data);
inorder(t->right);
}
}
void preorder(avl t)
{
if(t!=NULL)
{
printf("%d",t->data);
preorder(t->left);
preorder(t->right);
}
}
void postorder(avl t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("%d",t->data);
}
}

