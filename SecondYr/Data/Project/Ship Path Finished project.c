#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct city
{
    char cit[10];
}ci[20];
typedef struct tableentry * Table;
Graph gInit(int n);
Table tInit(int n,int s);
void readGraph(Graph g);
int findMinVertex(Table t,int n);
void dijkstra(Graph g,Table t);
void city(int);
int distance(Graph g,Table t,char [],char[],int n);

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
    printf("\n Enter Data about city %s labeled  as %d  \n",ci[i].cit,i);
    do
    {
      printf(" Enter 1 to add a route with continent %s ",ci[i].cit);
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("Enter adjacent continent label  & its traveling cost:");
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
void dijkstra(Graph g,Table t)
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
        if(t[w].dist>temp->cost)
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
  char a[10];
  printf("\n\n\t\t\t\t\t\t\t\t TABLE IS \n*****************************************************************************************************************\n");
  printf("\ncontinent no\t\tcontinent\t\tVisited\t\t\t\tDist\t\t\t    Path\n");
   for(i=1;i<=n;i++)
  {
    printf("%d\t\t\t%s\t\t\t%d\t\t||\t\t%d\t\t||\t\t%d\n",i,ci[i].cit,t[i].known,t[i].dist,t[i].path);
    printf("----------------------------------------------------------------------------------------------------------------\n");
  }
}
void city(int n)
{
   int i;
   char a[10];
   for(i=1;i<=n;i++)
  {
     printf("\n Enter %d continent name ",i);
     scanf("%s",ci[i].cit);
   }
}

int distance(Graph g,Table t,char s[],char d[],int n)
{
    int i,soc,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
          if((!strcmp(ci[i].cit,s))&&(!strcmp(ci[i].cit,s)))
           {
            soc=i;
           }
        }
        t[i].dist+=t[i].dist;
    }
    return t[i].dist;
}
int main()
{
  int n,st,sho;
   char s[10],d[20],ch,ch1;
  printf("\n\n\t\t************** SHIPPATH PROGRAM USING GRAPH DATA STRUCTURE *************** \n\n");
  printf("\n Enter no of Continents ");
  scanf("%d",&n);
  Graph g=gInit(n);
   city(n);
  readGraph(g);
  printf("\n Enter Starting Contient ");
  scanf("%d",&st);
  Table t=tInit(n,st);
  dijkstra(g,t);
  display(t,n);
    loose:
    //while(ch1!='n')
   {
  printf("\n Enter the ship start continent ");
  scanf("%s",s);
  printf("\n Enter the ship destination continent ");
  scanf("%s",d);
    if(!strcmp(s,d))
    {
        printf("\n You have entered Start and Destination same !!!...\n");
        goto loose;
    }
    else
    {
     sho=distance(g,t,s,d,n);
    }
    if(sho==9999)
        {
        printf("\n Both Continents will not be visited because both are not connected !!!");
        return 1;
        }
    else
       {
         printf("\n Minimum distance to reach %s from %s is  * %d units * ",d,s,sho);
       }

      // printf("\n Do you want to find other path ? Y/N ");
      // scanf("%c",&ch1);
    }
    //while(ch1!='n');
        //  goto roy;
       return 0;
}
