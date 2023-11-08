#include"headex5.h"
avl insert(int x,avl t)
{
  avl temp;
	if(t=='\0')
	{
		temp=(avl)malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=0;
	}
	else if(x<t->data)
	{
		t->left=insert(x,t->left);
		if(height(t->left)-height(t->right)==2)
		{
			if(x<t->left->data)
				t=srl(t);
			else
				t=drl(t);
		}
	}
	else if(x>t->data)
	{
		t->right=insert(x,t->left);
		if(height(t->right)-height(t->left)==2)
		{
			if(x>t->right->data)
				t=srr(t);
			else
				t=drr(t);
		}
	}
	t->height=max(t->left->height,t->right->height)+1;
	return t;
}
int height(avl t)
{
	if(t==NULL)
		return -1;
	else
		return t->height;
}
avl srl(avl k1)
{
	avl k2;
	k2=k1->left;
	k1->left=k2->right;
	k2->right=k1;
	k1->height=max(k1->left->height,k1->right->height)+1;
	k2->height=max(k2->left->height,k2->right->height)+1;
	return k2;

}
avl drl(avl k1)
{
	k1->left=srr(k1->left);
	return srl(k1);
}
avl drr(avl k1)
{
	k1->right=srl(k1->right);
	return srr(k1);
}
avl srr(avl k1)
{
	avl k2;
	k2=k1->right;
	k1->right=k2->left;
	k2->left=k1;
	k1->height=max(k1->left->height,k1->right->height)+1;
	k2->height=max(k2->left->height,k2->right->height)+1;
	return k2;
}
int max(int h1,int h2)
{
	return(h1>h2)?h1:h2;
}
void display(avl t)
{
	int c;
	printf("\n1]Inorder\n2]Preorder\n3]Postorder\nEnter your choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:inorder(t);
		       break;
		case 2:preorder(t);
		       break;
		case 3:postorder(t);
		       break;
		default:printf("\nINVALID CHOICE");
	}
}
void inorder(avl t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("\t%d",t->data);
		inorder(t->right);
	}
}
void preorder(avl t)
{
	if(t!=NULL)
	{
		printf("\t%d",t->data);
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
		printf("\t%d",t->data);
	}
}
void search(int x,avl t)
{
	if(t!=NULL)
	{
		if(x==t->data)
			printf("\nData Found");
		else if(x<t->data)
			search(x,t->left);
		else
			search(x,t->right);
	}
  else
    printf("\nNO data found");
}
