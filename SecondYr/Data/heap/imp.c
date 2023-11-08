#include"head.h"
heap create(int capacity)
{
    heap q;
    q=(heap)malloc(sizeof(struct heapnode));
    q.a=(int*)malloc((sizeof int)*capacity);
    q.size=0;
    q.capacity=capacity;
    q.data[0]=-999;
    return q;
}
heap insertit(int x,heap h)
{
   int i;
   if(!isfull(n))
   {
       h->size++;
      for(i=h->siz;h->a[i/2]<x;i=i/2)
      {
          h->a[i]=h->a[i/2];
      }
      h->a[i]=x;
      return h;
   }
   else
    return NULL;
}
int deletemax(heap h)
{
    int child,last,min,i;
    if(isempty(h))
    {
        max=h->a[1];
        last=h->a[h->siz];
        h->size--;
        for(i=1;i*2<=h->siz;i=child)
        {
            child=i*2;
            if((child!=h.siz)&&(h.a[child+1]>h.a[child]))
                child+=1;
            if(last<h.a[child])
                h.a[i]=h.a[child];
            else
                break;
            h.a[i]=last;
            return max;
        }
        else
        {
            printf("Error");
            return 0;
        }
    }
}
int isfull(heap h)
{
    if(h.siz==h.capacity-1)
        return 1;
    else
        return 0;
}
int isempty(heap h)
{
    return(h.siz==0?1:0);
}
void displayit(heap h)
{
    int i=1;
    for(i=1;i<h.siz;i++)
        printf("\n%d",h->a[i]);
}
