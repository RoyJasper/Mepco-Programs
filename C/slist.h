#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
int stid;
char name[50];
struct student *next;
};
typedef struct student * list;
int insert(int,int,char[],list);
int search(int,list);
void display(list);
void delet(int,list);
list preeleadd(int,list);
int isempty(list);
int locate(int,list);
list retrive(int,list);
void reverse(list);
