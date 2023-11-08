#include"head7.h"
left insert(int x,left h)
{
left t;
t=(left)malloc(sizeof(struct node));
t->data=x;
t->left=NULL;
t->right=NULL;
return merge(t,h);
}
left merge(left h1,left h2)
{
if(h1==NULL)
return h2;
if(h2==NULL)
return h1;
if(h1->data<h2->data)
return ins(h1,h2);
else
return ins(h2,h1);
}
static left ins(left h1,left h2)
{
if(h1->left==NULL)
h1->left=h2;
else
{
h1->right=merge(h1->right,h2);
h1=swap(h1);
}
return h1;
}
left swap(left h1)
{
left t;
t=h1->left;
h1->left=h1->right;
h1->right=t;
return h1;
}
void display(left h1)
{
if(h1!=NULL)
{
display(h1->left);
printf("\n%d",h1->data);
display(h1->right);
}
}
left delet(left h1)
{
int x;
if(h1!=NULL)
{
x=h1->data;
printf("\nDaleted element is %d",x);
return merge(h1->left,h1->right);
}
else
printf("Deleted is impossible");
}
