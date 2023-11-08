#include"hash.h"
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

