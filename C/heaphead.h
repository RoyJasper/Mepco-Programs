#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
int *data;
int size;
int capacity;
};
typedef struct node * heap;
heap create(int);
heap insert(int,heap);
int deletemax(heap);
int isempty(heap);
int isfull(heap);
void display(heap);

