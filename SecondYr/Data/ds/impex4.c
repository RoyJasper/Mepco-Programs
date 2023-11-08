#include"headex4.h"
bst insert(int x,bst t)
{
	if(t!=NULL)
	{
		bst temp;
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
		else
      return t;
	}
}
bst removeit(int x,bst t)
{
  bst temp;
	if(t==NULL)
		printf("Empty tree");
	else if(x<t->data)
		t->left=removeit(x,t->left);
	else if(x>t->data)
		t->right=removeit(x,t->right);
	else
	{
		if(t->left!=NULL&&t->right!=NULL)
		{
			bst temp;
			temp=findmin(t->right);
			t->data=temp->data;
			t->right=removeit(temp->data,t->right);
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
			free(temp);
		}
	}
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
			t=t->left;
	}
	return t;
}
void searchit(bst t,int x)
{
	if(t!=NULL)
	{
		if(x==t->data)
			printf("Data is found");
		else if(x<t->data)
			searchit(t->left,x);
		else
			searchit(t->right,x);
	}
	else
		printf("Not Found");
}
void inorder(bst t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%c",t->data);
		inorder(t->right);
	}
}
void preorder(bst t)
{
	if(t!=NULL)
	{
		printf("%c",t->data);
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
		printf("%c",t->data);
	}
}
