#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
enum type{empty,legitimate,deleted};
struct cell
{
  char a[10];
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

//#include"hashimp.c"
#include<string.h>
main()
{
  int ch;
  char a[10];
  HashTable h=create(10);
  do
  {
    printf("\n1.Insert\n2.Delete\n3.Find\n4.Display\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter a string:");
        scanf("%s",a);
        insert(a,h);
        break;
      case 2:
        printf("Enter a string:");
        scanf("%s",a);
        Delete(a,h);
        break;
      case 3:
        printf("Enter a string:");
        scanf("%s",a);
        if(find(a,h)!=NULL)
          printf("\nString Found.");
        else
          printf("\nString not Found.");
        break;
      case 4:
          display(h);
        break;
    }
}while(ch<5);
}


//#include"hash.h"
HashTable create(int n)
{
  int i;
  HashTable h=(HashTable)malloc(sizeof(struct hashtable));
  if(h!=NULL)
  {
    h->tablesize=n;
    h->element=(Cell *)malloc(sizeof(Cell)*n);
    if(h->element!=NULL)
    {
      for(i=0;i<n;i++)
      {
        h->element[i]=(Cell)malloc(sizeof(struct cell));
        if(h!=NULL)
          h->element[i]->info=empty;
        else
        {
          printf("Cannot allocate Memory\n");
          return NULL;
        }
      }
    }
    else
    {
      printf("Cannot allocate Memory\n");
      return NULL;
    }
    return h;
  }
    else
  {
    printf("Cannot allocate Memory\n");
    return NULL;
  }
}
void insert(char *s, HashTable h)
{
  int pos;
  int collision=0;
  if(find(s,h)==NULL)
  {
    int pos=hash1(s,h->tablesize,collision);
    while(h->element[pos]->info==legitimate)
    {
      collision++;
      if(collision>10)
        goto END;
      pos=hash1(s,h->tablesize,collision);
    }
strcpy(h->element[pos]->a,s);
      h->element[pos]->info=legitimate;
  }
  else
  {
    END:
    printf("error cannot insert");
  }
}
Cell find(char *s,HashTable h)
{
  int collision=0;
  int pos=hash1(s,h->tablesize,collision);
  while(h->element[pos]->info!=empty)
  {
    if(strcmp(h->element[pos]->a,s)==0&&h->element[pos]->info==legitimate)
      return h->element[pos];
    collision++;
    if(collision>10)
      return NULL;
    pos=hash1(s,h->tablesize,collision);
  }
  return NULL;

}
void Delete(char *s,HashTable h)
{
  Cell c=find(s,h);
  if(c!=NULL)
  {
    c->info=deleted;
  }
  else
  {
    printf("not found");
  }
}
int hash(char *s,int n)
{
  int i=0;
int value=0;
  while(s[i]!='\0')
  {
    value+=s[i];
    i++;
  }
return value;
}
int hash1(char *s, int n, int c)
{
 return (hash(s,n)%n+(7-(hash(s,n)%7)));
}
void display(HashTable h)
{
  int i;
  for(i=0;i<h->tablesize;i++)
  {
  printf("\n%d->",i);
    if(h->element[i]->info==legitimate)
      printf("%s",h->element[i]->a);
  }
}


