#include"heaphead.h"
heap create(int n)
{
heap q;
q->data=(int*)malloc(n*sizeof(int));
q->size=0;
q->capacity=n;
q->data[0]=-999;
return q;
}
heap insert(int x,heap h)
{
int i;
if(h->size==h->capacity)
{
printf("IT IS NOT POSSIBLE");
return 0;
}
else
{
h->size++;
for(i=h->size;h->data[i/2]>x;i=i/2)
{
h->data[i]=h->data[i/2];
}
h->data[i]=x;
return h;
//}
}
}
int deletemax(heap h)
{
int child,lastmin,i=1,max;
if(!isempty (h))
{
max=h->data[i];
lastmin=h->data[h->size];
h->size--;
for(i=1;i*2<=h->size;i=child)
{
child=i*2;
if(child!=h->size && h->data[child+1]>h->data[child])
{
child++;
}
if(lastmin<h->data[child])
h->data[i]=h->data[child];
else
break;
}
h->data[i]=lastmin;
return max;
}
}
int isfull(heap h)
{
if(h->size==h->capacity)
{
return 1;
}
else
return 0;
}
int isempty(heap h)
{
if(h->size==0)
{
return 1;
}
else
return 0;
}
void display(heap h)
{
int i;
for(i=1;i<=h->size;i++)
{
printf("%d",h->data[i]);
}
}

