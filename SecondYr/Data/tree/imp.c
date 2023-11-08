#include"head.h"
bst insert(int x , bst t)
{
bst temp;
if(t==NULL)
{
t = (bst) malloc(sizeof(struct node));
t->data=x;
t->left=NULL;
t->right=NULL;
}
else
if(x<t->data)
t->left=insert(x,t->left);
else if(x>t->data)
t->right=insert(x,t->right);
else 
printf("\n THE ELEMENT PRESENT IN THE TREE IS");
return t;
}
bst deletion(int x , bst t)
{
bst temp;
if(t==NULL)
{
printf("TREE IS EMPTY");
}
if(x<t->data)
t->left=deletion(x,t->left);
else
if(x>t->data)
t->right=deletion(x,t->right);
else
{
if(t->left!=NULL&& t->right!=NULL)
{
temp = findmax(t->left);
t->data = temp->data;
t->right = deletion(t->data,t->left);
}
else
if(t->left==NULL)
{
temp=t;
t=t->right;
}
else if(t->right==NULL)
{
temp=t;
t=t->right;
free(temp);
}
}
return t;
}
bst findmax(bst t)
{
while(t->right!=NULL)
{
t=t->right;
}
return t;
}
void inorder(bst t)
{
if(t!=NULL)
{
inorder(t->left);
printf("\t%d",t->data);
inorder(t->right);
}
}
void preorder(bst t)
{
if(t!=NULL)
{
printf("\t%d",t->data);;
preorder(t->left);
preorder(t->right);
}
}
void postorder(bst t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("\t%d",t->data);
}
}

