#include<stdio.h>
#include<stdlib.h>
struct node
{
int *a;
int cap;
};
typedef struct node *set;
void makeset(set);
void unionset(set);
int findset(int,set);
void dis(set,int);
