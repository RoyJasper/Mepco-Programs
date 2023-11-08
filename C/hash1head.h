#include<stdio.h>
#include<stdlib.h>
struct node
{
int a[20];
int size;
};
typedef struct node *hash;
hash insert(hash,int);
hash delet(hash,int);
void display(hash);
int search(int,hash);
hash insert1(hash,int);

