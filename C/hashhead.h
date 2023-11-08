#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *list;
struct table
{
int tablesize;
list *l;
};
typedef struct table *hash;
hash create(int);
hash delet(int,hash);
hash insert(int,hash);
int search(int,hash);
void display(hash);
