#include<stdio.h>
#include<stdlib.h>
struct node
{
	int*a;
};
typedef struct node* hash;
void insert(int*,hash,int);
void del(int,hash,int);
int search(int,hsah,int);
void display(hash,int);	
