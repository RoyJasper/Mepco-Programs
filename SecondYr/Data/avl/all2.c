#include<stdio.h>
#include<stdlib.h>
struct AvlNode
{
  int element;
  struct AvlNode * left;
  struct AvlNode * right;
  int height;
};
typedef struct AvlNode * avlt;
avlt insert(int ,avlt);
void search(int,avlt);
avlt srl(avlt);
avlt srr(avlt);
avlt drl(avlt);
avlt drr(avlt);
int height(avlt);
int max(int,int);
avlt findMin(avlt);
avlt findMax(avlt);
void inOrder(avlt);
void postOrder(avlt);
void preOrder(avlt);
//#include"avl.h"
main()
{
  int ch,x,n,i;
  avlt T=NULL;
  do
  {
    printf("\n1.Insert\n2.Search\n3.Inorder\n4.preorder\n5.postorder\n6.Exit\nChoice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
    printf("Enter no of elements:");
    scanf("%d",&n);
        printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
      scanf("%d",&x);
      T=insert(x,T);
    }
        break;
      case 2:
        printf("\nEnter element:");
        scanf("%d",&x);
        search(x,T);
        break;
      //case 3:
        //printf("Minimum is %d",findMin(T)->element);
        //printf("\nMaximum is %d",findMax(T)->element);
        //break;
      case 3:
        printf("\nINORDER: ");
        inOrder(T);
        break;
      case 4:
        printf("\nPREORDER:");
        preOrder(T);
        break;
      case 5:
        printf("\nPOSTORDER:");
        postOrder(T);
        break;
      case 6:
        exit(0);
        break;
    }
  }while(ch<5);
  printf("\n");
 }
//#include"avl.h"
avlt insert(int x, avlt T)
{
  if(T==NULL)
  {
    T=(avlt)malloc(sizeof(struct AvlNode));
    if(T==NULL)
      printf("\nError-out of Space");
    else
    {
      T->element=x;
      T->height=0;
      T->left=NULL;
      T->right=NULL;
    }
  }
  else if(x<T->element)
  {
    T->left=insert(x,T->left);
    if(height(T->left)-height(T->right)==2)
    {
      if(x<T->left->element)
        T=srl(T);
      else
        T=drl(T);
    }
  }
  else if(x>T->element)
  {
    T->right=insert(x,T->right);
    if(height(T->right)-height(T->left)==2)
    {
      if(x>T->right->element)
        T=srr(T);
      else
        T=drr(T);
    }
  }
  T->height=max(height(T->left),height(T->right))+1;
  return T;
}
avlt srl( avlt k2)
{
  avlt k1=k2->left;
  k2->left=k1->right;
  k1->right=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->left),k2->height)+1;
  return k1;
}
avlt srr( avlt k2)
{
  avlt k1=k2->right;
  k2->right=k1->left;
  k1->left=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->right),k2->height)+1;
  return k1;
}
avlt drl(avlt k3)
{
  k3->left=srr(k3->left);
  return srl(k3);
}
avlt drr(avlt k3)
{
  k3->right=srl(k3->right);
  return srr(k3);
}
void search(int x,avlt T )
{
  if(T!=NULL)
 {
   if(x<T->element)
 search(x,T->left);
  else if(x>T->element)
 search(x,T->right);
  else
  printf("Search element is present");
}
else
 {
 printf("not found");
 }
}
int max(int a, int b)
{
  return (a>b?a:b);
}
int height(avlt T)
{
  if(T==NULL)
    return -1;
  else
    return T->height;
}
avlt findMin(avlt T)
{
  if(T!=NULL)
  {
    while(T->left!=NULL)
      T=T->left;
    return T;
  }
}
avlt findMax(avlt T)
{
  if(T!=NULL)
  {
    while(T->right!=NULL)
      T=T->right;
    return T;
  }
}
void inOrder(avlt T)
{
  if(T!=NULL)
  {
  inOrder(T->left);
    printf(" %d ",T->element);
    inOrder(T->right);
  }
}
void postOrder(avlt T)
{
 if(T!=NULL)
{
 postOrder(T->left);
 postOrder(T->right);
 printf(" %d ",T->element);
}}
void preOrder(avlt T)
{
 if(T!=NULL)
{
 printf(" %d ",T->element);
 preOrder(T->left);
 preOrder(T->right);
}}

