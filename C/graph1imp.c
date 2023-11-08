#include"graph1head.h"
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
void readgraph(graph g)
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
temp->next=t->next;
t->next=temp;
}
}while(c==1);
}
}
table tinit(int s,graph g)
{
table t;
int i;
t=(table)malloc(sizeof(struct tableentry)*(g->nov+1));
for(i=1;i<=g->nov;i++)
{
t[i].known=0;
t[i].dist=9999;
t[i].path=0;
}
t[s].dist=0;
return t;
}
void dijkstra(graph g,table t)
{
int c,b,i;
for(i=1;i<=g->nov;i++)
{
b=findmin(t,g->nov);
if(b<1)
{
break;
}
else
{
t[b].known=1;
list temp;
temp=g->a[b];
while(temp->next!=NULL)
{
c=temp->next->adj;
if(t[c].known==0)
{
if(t[b].dist+temp->next->cost<t[c].dist)
{
t[c].dist=t[b].dist+temp->next->cost;
t[c].path=b;
}
}
temp=temp->next;
}
}
}
}
int findmin(table t,int n)
{
int min=0,m=9999,i;
for(i=1;i<=n;i++)
{
if((t[i].known==0)&&(m>t[i].dist))
{
m=t[i].dist;
min=i;
}
}
return min;
}
void display(table t,int n)
{
int i;
printf("\nVERTEX\tKNOWN\tDISTANCE\tPATH\n");
for(i=1;i<=n;i++)
{
printf("%d\t%d\t%d\t%d\n",i,t[i].known,t[i].dist,t[i].path);
}
}

