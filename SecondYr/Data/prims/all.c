#include<stdio.h>
#include<stdlib.h>
struct node
{
  int adj;
  int cost;
  struct node * next;
};
typedef struct node * List;
struct graphentry
{
  int n_vertex;
  List *array;
};
typedef struct graphentry *Graph;
struct tableentry
{
  int known;
  int dist;
  int path;
};
typedef struct tableentry * Table;
Graph gInit(int n);
Table tInit(int n,int s);
void readGraph(Graph g);
int findMinVertex(Table t,int n);
void prims(Graph g,Table t);
void display(Table t,int n);

//#include"prims.h"
Graph gInit(int n)
{
  int i;
  Graph g=(Graph)malloc(sizeof(struct graphentry));
  g->n_vertex=n;
  g->array=(List *)malloc(sizeof(List)*(n+1));
  for(i=0;i<n+1;i++)
  {
    g->array[i]=(List)malloc(sizeof(struct node));
    g->array[i]->next=NULL;
  }
  return g;
}
void readGraph(Graph g)
{
  List t,temp;
  int a,c,i,ch;
  for(i=1;i<=g->n_vertex;i++)
  {
    do
    {
      printf(" Enter ur choice 1 to add else 0",i);
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("Enter adjacent vertex & its cost:");
        scanf("%d%d",&a,&c);
        t=g->array[i];
        temp=(List)malloc(sizeof(struct node));
        temp->adj=a;
        temp->cost=c;
        temp->next=t->next;
        t->next=temp;
      }
    }while(ch==1);
  }
}
Table tInit(int n,int s)
{
  int i;

 Table t;
  t=(Table)malloc(sizeof(struct tableentry)*(n+1));

  for(i=1;i<=n;i++)
  {
    t[i].known=0;
    t[i].dist=9999;
    t[i].path=0;
}
  t[s].dist=0;
  return t;
}
int findMinVertex(Table t,int n)
{
  int minv=0;
  int min=9999;
  int i;
  for(i=1;i<=n;i++)
  {
    if(t[i].known==0)
    {
      if(min>t[i].dist)
      {
        min=t[i].dist;
        minv=i;
      }
    }
  }
  return minv;
}
void prims(Graph g,Table t)
{
  int v,w,i;
  for(i=1;i<=g->n_vertex;i++)
  {
    v=findMinVertex(t,g->n_vertex);
    if(v<1)
      break;
    t[v].known=1;
    List temp=g->array[v]->next;
    while(temp!=NULL)
    {
w=temp->adj;
      if(t[w].known==0)
      {
        if(temp->cost<t[w].dist)
        {
          t[w].dist=temp->cost;
          t[w].path=v;
        }
      }

      temp=temp->next;
    }
  }
}
void display(Table t,int n)
{
 int i;
  printf("\nvertex\tKnown\tDist\tPath\n");
  for(i=1;i<=n;i++)
  {
    printf("%d\t%d\t%d\t%d\n",i,t[i].known,t[i].dist,t[i].path);
  }
}

//#include"primsimp.c"
main()
{
  int n,s;
  printf("Enter no of vertex");
  scanf("%d",&n);
  Graph g=gInit(n);
  readGraph(g);
  printf("Enter Source Vertex");
  scanf("%d",&s);
  Table t=tInit(n,s);
  prims(g,t);
  display(t,n);
}

