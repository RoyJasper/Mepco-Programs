#include<stdio.h>
#include<stdlib.h>
struct node
{
int adj;
int cost;
struct node *next;
};
typedef struct node *list;
struct graphentry
{
int nov;
list *a;
};
typedef struct graphentry *graph;
struct tableentry
{
int known;
int dist;
int path;
};
typedef struct tableentry *table;
graph ginit(int);
void readgraph(graph);
table tinit(int,graph);
void dijkstra(graph,table);
int findmin(table,int);
void display(table,int);

