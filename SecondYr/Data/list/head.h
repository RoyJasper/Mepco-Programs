#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct student
{
 int no;
 char name[50];
 struct student *next;
};
typedef struct student * list;
void insert(int,int,char[],list);
int search(int,char[],list);
void display(list);
void delet(list,int,char[]);
list preeleadd(int,list);
int isempty(list);
int locate(int,list);
int retrieve(int,list);
//void reverse(list);
void swap(int,int,list);

