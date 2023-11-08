#include"bsthead.h"
bst insert(int x,bst t)
{
    bst temp;
    if(t==NULL)
    {
        temp=(bst)malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else
    {
        if(x<t->data)
            t->left=insert(x,t->left);
        else if(x>t->data)
            t->right=insert(x,t->right);
    }
    return t;
}
bst deletion(int x,bst t)
{
    bst temp;
    if(t==NULL)
    {
        printf("IT IS EMPTY");
    }
    else if(x<t->data)
        t->left=deletion(x,t->left);
    else if(x>t->data)
        t->right=deletion(x,t->right);
    else if(t->left!=NULL && t->right!=NULL)
    {
        bst temp;
        temp=findmin(t->right);
        t->data=temp->data;
        t->right=deletion(temp->data,t->right);
    }
    else
    {
        temp=t;
        if(t->left!=NULL)
            t=t->left;
        if(t->right!=NULL)
            t=t->right;
        if(temp==t)
            t=NULL;
        printf("IT IS DELETED SUCCESSFULLY");
        free(temp);
    }
    return t;
}
bst findmin(bst t)
{
    if(t!=NULL)
    {
        while(t->left!=NULL)
            t=t->left;
    }
    return t;
}
bst findmax(bst t)
{
    if(t!=NULL)
    {
        while(t->right!=NULL)
            t=t->right;
    }
    return t;
}
void inorder(bst t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d",t->data);
        inorder(t->right);
    }
}
void preorder(bst t)
{
    if(t!=NULL)
    {
        printf("%d",t->data);
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
        printf("%d",t->data);
    }
}


