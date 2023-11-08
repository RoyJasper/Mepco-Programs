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
table intialize();
int insert(char[],char[],int,int,table);
list search(char[],table);
int modify(char[],char[],table);
int modi(char[],int,table);
void display(table);
int delete(char[],table);
list findprev(char[],table);
int findhash(char name)
{
	int hash;
	hash=(char)name;
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
main()
{
	table tt;
	tt=initialize();
	int i,choice;
	list t;
	int length,address;
	char name[20],type[20];
	while(1)
	{
		printf("\n1.INSERT\n2.SEARCH\n3.MODIFY\n4.DELETE\n5.DISPLAY\n6.EXIT\nENTER THE CHOICE:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("ENTER THE NAME,TYPE,ADDRESS,LENGTH:\n");
				scanf("%s%s%d%d",name,type,&address,&length);
				i=insert(name,type,address,length,tt);
				if(i==1)
					printf("\nINSERTED SUCCESSFULLY");
				else
					printf("\nNOT INSERTED SUCCESSFULLY");
				break;
			case 2:
				printf("ENTER THE NAME:");
				scanf("%s",name);
				t=search(name,tt);
				if(t!=NULL)
					printf("DATA IS FOUND");
				else
					printf("NOT FOUND");
				break;
			case 3:
				printf("ENTER THE NAME WHICH IS TO MODIFY");
				scanf("%s",name);
				printf("ENTER WHICH IS TO MODIFY TYPE OR ADDRESS");
				scanf("%s",type);
				if(strcmp(type,"type")==0)
				{
					printf("ENTER THE VALUE FOR TYPE:");
					scanf("%s",type); 
					i=modify(name,type,tt);
					if(i==1)
						printf("MODIFIED");
					else
						printf("NOT MODIFIED");
				}
				else
				{
					printf("ENTER THE VALUE FOR ADDRESS:");
          scanf("%d",&address);
          i=modi(name,address,tt);
          if(i==1)
            printf("MODIFIED");
          else
            printf("NOT MODIFIED");
				}
				break;
			case 4:
				printf("ENTER THE NAME");
				scanf("%s",name);
				i=delete(name,tt);
				if(i==1)
					printf("DELETED");
				else
					printf("NOT DELETED");
				break;
			case 5:
				display(tt);
				break;
			case 6:
				exit(0);
		}
	}
}

