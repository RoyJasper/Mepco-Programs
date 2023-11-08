#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int *a;
int capacity;
};
typedef struct node *set;
set makeset(set);
set makesize(set);
set unionarbi(set);
set unionhei(set);
set unionsiz(set);
void findset(int,set);
void display(set);


