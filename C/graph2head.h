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
int vertex1,vertex2;
int cost1;
int yes;
};
typedef struct tableentry *table;
struct node1
{
int *b;
int capacity;
};
typedef struct node1 *set;
graph ginit(int);
graph readgraph(graph);
table tinit(int,graph);
table insert(table,graph);
table sort(table);
void display(table,int);
set makeset(int,set);
set unionarbi(table,set);
int findset(int,set);
