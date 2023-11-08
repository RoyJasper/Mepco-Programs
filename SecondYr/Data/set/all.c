#include<stdio.h>
#include<stdlib.h>
struct node
{
int *a;
int cap;
};
typedef struct node *set;
void makeset(set,int);
void unionset(set,int);
int findset(int,set);
void dis(set,int);
//#include"set.h"
void makeset(set s,int n)
{
int i;
//printf("\nEnter the capacity");
//scanf("%d",&n);
n=n+1;
s->a=(int*)malloc(sizeof(int)*n);
for(i=1;i<n+1;i++)
{
s->a[i]=-1;
}
}
void unionset(set s,int n)
{
/*
//ARBITARY UNION:
int l1,l2;
printf("\nEnter 2 values ");
scanf("%d%d",&l1,&l2);
s->a[l2]=l1;
//UNION BY HEIGHT:

int r1,r2;
printf("\nEnter the first value");
scanf("%d",&r1);
printf("\nEnter the second value");
scanf("%d",&r2);
if(s->a[r2]<s->a[r1])
{
s->a[r1]=r2;
}
//else if(s->a[r2]>s->a[r1])
//{
//s->a[r2]=r1;
//}
else if(s->a[r1]==s->a[r2])
{
s->a[r1]--;
s->a[r2]=r1;
}*/
//UNION BY SIZE:
int l1,l2,i;
printf("\nEnter 2 values ");
scanf("%d%d",&l1,&l2);
//for(i=1;i<n+1;i++)
//{
//s->a[i]=-1;
//}
if(s->a[l1]>s->a[l2])
{
  s->a[l2]=s->a[l1]+s->a[l2];
  s->a[l1]=l2;
}
else
{
  s->a[l2]=s->a[l1]+s->a[l2];
  s->a[l2]=l1;
}
}
int findset(int x,set s)
{
if(s->a[x]<=0)
return s->a[x];
else
return findset(s->a[x],s);
}
void dis(set s,int n)
{
int i;
printf("\nEnter no of elements");
scanf("%d",&n);
printf("\nThe elements are");
for(i=1;i<n+1;i++)
printf("\n %d ==--> %d ",i,s->a[i]);
}

//#include"setimp.c"
main()
{
set s;
int ch,e,f,n;
s=(set)malloc(sizeof(struct node));
do
{
printf("\nEnter your choice\n1.Makeset\n2.Unionset\n3.Findset\n4.Display ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("\nEnter the capacity");
scanf("%d",&n);
makeset(s,n);
break;
}
case 2:
{
unionset(s,n);
break;
}
case 3:
{
printf("\nEnter the element to search");
scanf("%d",&e);
f=findset(e,s);
if(f==0)
printf("Not found");
else
printf("Element found");
break;
}
case 4:
{
printf("\nElements are");
dis(s,n);
break;
}
}
}while(ch!=5);
}

