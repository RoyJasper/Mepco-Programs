#include"graph2head.h"
int u=0;
graph ginit(int n)
{
graph g;
int i;
g=(graph)malloc(sizeof(struct graphentry));
g->nov=n;
g->a=(list *)malloc(sizeof(struct node)*(n+1));
for(i=0;i<=n;i++)
{
g->a[i]=(list)malloc(sizeof(struct node));
g->a[i]->next=NULL;
}
return g;
}
graph readgraph(graph g)
{
list t,temp;
int p,c,b,i,ch;
for(i=1;i<=g->nov;i++)
{
do
{
printf("IF U WANT TO ADD VERTEX %d PRESS 1",i);
scanf("%d",&c);
if(c==1)
{
printf("ENTER THE VALUE AND COST");
scanf("%d%d",&p,&b);
t=g->a[i];
temp=(list)malloc(sizeof(struct node));
temp->adj=p;
temp->cost=b;
u++;
temp->next=t->next;
t->next=temp;
t=t->next;
}
}while(c==1);
}
return g;
}
table tinit(int s,graph g)
{
table t;
int i; 
t=(table)malloc(sizeof(struct tableentry)*(u+1));
for(i=1;i<=u;i++)
{
t[i].vertex1=0;
t[i].vertex2=0;
t[i].cost1=9999;
t[i].yes=0;
}
return t;
}
table insert(table t,graph g)
{
int i,j=1;
list f;
for(i=1;i<=g->nov;i++)
{
f=g->a[i]->next;
while(f!=NULL)
{
t[j].vertex1=i;
t[j].vertex2=f->adj;
t[j].cost1=f->cost;
f=f->next;
j++;
}
}
return t;
}
table sort(table t)
{
int i,j,l,k,m;
for(i=1;i<=u;i++)
{
for(j=i+1;j<=u;j++)
{
if(t[i].cost1>t[j].cost1)
{
l=t[i].cost1;
t[i].cost1=t[j].cost1;
t[j].cost1=l;
k=t[i].vertex1;
t[i].vertex1=t[j].vertex1;
t[j].vertex1=k;
m=t[i].vertex2;
t[i].vertex2=t[j].vertex2;
t[j].vertex2=m;
}
}
}
return t;
}
set unionarbi(table t,set s)
{
int i,j=0,c=0;
for(i=1;i<=u;i++)
{
j=findset(t[i].vertex1,s);
c=findset(t[i].vertex2,s);
if(j!=c)
{
if(s->b[t[i].vertex2]==0)
s->b[t[i].vertex2]=t[i].vertex1;
}
}
return s;
}
set makeset(int n,set s)
{
int i;
s=(set)malloc(sizeof(struct node1));
s->b=(int*)malloc(sizeof(int)*n);
s->capacity=n;
for(i=1;i<=n;i++)
s->b[i]=0;
return s;
}
int findset(int x,set s)
{
if(s->b[x]<=0)
return x;
else
findset(s->b[x],s);
}
void display(table t,int n)
{
int i;
printf("\nVERTEX1\tVERTEX2\tCOST\tSTATUS\n");
for(i=1;i<=u;i++)
{
printf("%d\t%d\t%d\t%d\n",t[i].vertex1,t[i].vertex2,t[i].cost1,t[i].yes);
}
}
void display1(set s)
{
int i;
printf("THE ELEMENT ARE");
for(i=1;i<=s->capacity;i++)
{
printf("\n%d->%d",i,s->b[i]);
}
}
