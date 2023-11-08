
#include<stdio.h>
#include<stdlib.h>
struct HeapNode
{
  int *a;
  int size;
  int capacity;
};
typedef struct HeapNode * Heap;
Heap create(int capacity);
Heap insert(int x, Heap h);
int deleteMax(Heap h);
int isFull(Heap h);
int isEmpty(Heap h);
void display(Heap);
int main()
{
  int ch,x,p,i;
  Heap h;
  printf("Enter the capacity:");
  scanf("%d",&x);
  h=create(x);
  if(h==NULL)
    return 0;
  do
  {
    printf("\n1.Insert\n2.Delete Max\n3.Display\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
          printf("Enter no of elements:");
          scanf("%d",&p);
					if(x>p)
          {
          printf("Enter the elements:");
          for(i=0;i<p;i++)
          {
            scanf("%d",&x);
            if(insert(x,h)==NULL)
            {
              printf("\nCannot insert Heap Full");
            }
          }
         }
         else
           printf("Error");
          break;
      case 2:
          printf("The deleted element is \t");
          printf("%d",deleteMax(h));
          break;
      case 3:
					printf("The elements are");
          display(h);
    }
  }while(ch<4);
return 1;
}


Heap create(int capacity)
{
  Heap temp=(Heap)malloc(sizeof(struct HeapNode));
  if(temp==NULL)
  {
    printf("\nError: cannot create Heap.\n");
    return NULL;
  }
  temp->a=(int *)malloc(sizeof(int)*(capacity));
  temp->size=0;
  temp->capacity=capacity;
  return temp;
}
Heap insert(int x,Heap h)
{
  int i;
  if(!isFull(h))
  {
    h->size++;
    for(i=h->size;h->a[i/2]<x&&i!=1;i=i/2)
      h->a[i]=h->a[i/2];
    h->a[i]=x;
    return h;
  }
  else
  {
    return NULL;
  }
}
int deleteMax(Heap h)
{
  int child,maxElement,lastElement,i;
  if(!isEmpty(h))
  {
    maxElement=h->a[1];
    lastElement=h->a[h->size--];
    for(i=1;i*2<=h->size;i=child)
    {
      child=i*2;
      if(child!=h->size&&h->a[child+1]>h->a[child])
        child+=1;
      if(lastElement<h->a[child])
        h->a[i]=h->a[child];
      else
        break;
    }
    h->a[i]=lastElement;
    return maxElement;
  }
  else
  {
    printf("Error:Heap Empty");
    return 0;
  }
}
int isFull(Heap h)
{
  return (h->size==h->capacity?1:0);
}
int isEmpty(Heap h)
{
  return (h->size==0?1:0);
}
void display(Heap h)
{
  int i=1;
  for(i=1;i<=h->size;i++)
    printf("%d ",h->a[i]);
}
