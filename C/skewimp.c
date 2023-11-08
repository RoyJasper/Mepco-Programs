#include"skewhead.h"
lh insert(int x,lh h)
{
lh temp;
temp=(lh)malloc(sizeof(struct node));
temp->data=x;
temp->right=NULL;
temp->left=NULL;
temp=merge(temp,h);
return temp;
}
lh merge(lh h1,lh h2)
{
lh temp;
if(h1==NULL)
{
return h2;
}
else if(h2==NULL)
{
return h1;
}
if(h1->data<h2->data)
{
temp=merge1(h1,h2);
return temp;
}
else
{
temp=merge1(h2,h1);
return temp;
}
}
static lh merge1(lh h1,lh h2)
{
if(h1->left==NULL)
{
h1->left=h2;
}
else
{
h1->right=merge(h1->right,h2);
h1=swapchild(h1);
}
return h1;
}
lh swapchild(lh h2)
{
lh temp;
temp=h2->left;
h2->left=h2->right;
h2->right=temp;
return h2;
}
void display(lh h)
{
if(h!=NULL)
{
printf("%d",h->data);
display(h->left);
display(h->right);
}
}
lh delet(lh h)
{
int x;
if(h!=NULL)
{
x=h->data;
printf("THE ELEMENT IS DELETED %d",x);
return merge(h->left,h->right);
}
else
{
printf("empty heap");
return NULL;
}
}

