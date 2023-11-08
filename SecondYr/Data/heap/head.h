#include<stdio.h>
#include<stdlib.h>
struct heapnode
{
    int a;
    int siz;
    int capacity;
};
typedef struct heapnode *heap;
heap create(int);
heap insertit(int,heap);
int deletemax(heap);
int isfull(heap);
int isempty(heap);
void displayit(heap);
