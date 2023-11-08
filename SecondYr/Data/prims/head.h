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

