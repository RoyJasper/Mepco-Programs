#include"hash1head.h"
hash insert(hash h1,int b)
{
int s,m,x,i=1;
int k=b;
begin:
s=b%h1->size;
if(h1->a[s]==0)
{
h1->a[s]=k;
}
else
{
b=b+i;
i++;
goto begin;
}
return h1;
}
hash insert1(hash h1,int b)
{
int s,m,x,i=1;
int k=b;
begin:
s=b%h1->size;
if(h1->a[s]==0)
{
h1->a[s]=k;
}
else
{
b=(b+(i*i));
i++;
goto begin;
}
return h1;
}
hash delet(hash h1,int k)
{
int i;
for(i=0;i<h1->size;i++)
{
if(h1->a[i]==k)
{
h1->a[i]=-1;
printf("IT IS DELETED");
}
}
return h1;
}
void display(hash h1)
{
int i;
for(i=0;i<h1->size;i++)
  {
  printf("\n%d->",i);
    if(h1->a[i]!=-1)
    {
      printf("%d\t",h1->a[i]);
    }
  }
}
int search(int c,hash h1)
{
int i;
for(i=0;i<h1->size;i++)
{
if(h1->a[i]==c)
{
return 1;
}
}
return 0;
}

