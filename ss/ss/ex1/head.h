#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol
{
  char name[20],type[20];
  int address,length;
  struct symbol *next;
};
typedef struct symbol *list;
struct hash
{
  list *lists;
};
typedef struct hash *table;
int findhash(char);
table initialize();
int insert(char[],char[],int,int,table);
list search(char[],table);
int modify(char[],char[],table);
int modi(char[],int,table);
void display(table);
int delete(char[],table);
list findprev(char[],table);

