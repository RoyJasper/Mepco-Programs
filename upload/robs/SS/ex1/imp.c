#include"head.h"
int findhash(char name)
{
  int hash;
  hash=(int)name;
  if(hash>=65 && hash<=90)
    hash=hash-65;
  if(hash>=97 && hash<122)
    hash=hash-97;
  return hash;
}
table initialize()
{
  table t;
  int i;
  t=(table)malloc(sizeof(struct hash));
  t->lists=(list*)malloc(26*sizeof(struct symbol));
  for(i=0;i<26;i++)
  {
    t->lists[i]=(list)malloc(sizeof(struct symbol));
    t->lists[i]->next=NULL;
  }
  return t;
}
int insert(char name[20],char type[20],int address,int length,table t)
{
  int hash;
  list temp,result=NULL,current;
  int r;
  temp=(list)malloc(sizeof(struct symbol));
  current=(list)malloc(sizeof(struct symbol));
  hash=findhash(name[0]);
  result=search(name,t);
  if(result==NULL)
  {
    strcpy(temp->name,name);
    strcpy(temp->type,type);
    temp->address=address;
    temp->length=length;
    temp->next=NULL;
    current=t->lists[hash];
    while(current->next!=NULL)
    {
      if(strcmp(current->next->name,temp->name)<=0)
        current=current->next;
      else
        break;
    }
    temp->next=current->next;
    current->next=temp;
    return 1;
  }
  else
    return 0;
}
list search(char name[20],table t)
{
  int hash;
  list current;
  hash=findhash(name[0]);
  current=t->lists[hash]->next;
  while(current!=NULL)
  {
    if(strcmp(current->name,name)==0)
        return current;
    else
        current=current->next;
  }
  return NULL;
}
int modify(char name[20],char type[20],table t)
{
  int hash;
  list result;
  hash=findhash(name[0]);
  result=search(name,t);
  if(result!=NULL)
  {
    strcpy(result->type,type);
    return 1;
  }
  else
    return 0;
}
int modi(char name[20],int address,table t)
{
  int hash;
  list result;
  hash=findhash(name[0]);
  result=search(name,t);
  if(result!=NULL)
  {
    result->address=address;
    return 1;
  }
  else
    return 0;
}

void display(table t)
{
  int i;
  list current;
  printf("\n\t\tNAME\t\tTYPE\t\tADDRESS\t\tLENGTH\n");
  for(i=0;i<26;i++)
  {
    current=t->lists[i]->next;
    printf("\n%d ::--",i);
    while(current!=NULL)
    {
      printf("\n\t\t%s\t\t%s\t\t%d\t\t%d",current->name,current->type,current->address,current->length);
      current=current->next;
    }
  }
}
list findprev(char name[20],table t)
{
  int hash;
  list current;
  hash=findhash(name[0]);
  current=t->lists[hash];
  while(current->next!=NULL)
  {
    if(strcmp(current->next->name,name)==0)
      return current;
    else
      current=current->next;
  }
}
int delete (char name[20],table t)
{
  list temp,current,k;
  temp=search(name,t);
  if(temp!=NULL)
  {
    current=findprev(name,t);
    k=current->next;
    current->next=current->next->next;
    free(k);
    return 1;
  }
  else
    return 2;
}

