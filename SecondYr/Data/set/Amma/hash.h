#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *list;
void insert(list,int);
void deletion(list,int);
void display(list[]);
int search(list,int);
list preadd(list,int);

