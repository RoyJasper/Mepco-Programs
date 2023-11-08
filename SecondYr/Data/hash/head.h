#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum type{empty,legitimate,deleted};
struct cell
{
  char a[100];
  enum  type info;
};
typedef struct cell * Cell;
struct hashtable
{
  Cell* element;
  int tablesize;
};
typedef struct hashtable * HashTable;
HashTable create(int n);
void insert(char *s,HashTable h);
void Delete(char *s,HashTable h);
Cell find(char *s,HashTable h);
int hash(char *s, int n);
int hash1(char *s,int n,int c);


