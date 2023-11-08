#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct symbol
{
	char name[20];
	int address;
	char type[5];
	int length;
	struct symbol *next;
};
typedef struct symbol *list;
struct hashtable
{
list *lists;
};
typedef struct hashtable *ht;
int findhash(char);
ht init();
int insert(char[20],char[5],int,int,ht);
list search(char[20],ht);
int modify(char[20],char[5],int,ht);
void display(ht);
int delete(char[20],ht);
list findprevious(char[20],ht);

main()
{
int i,j,ga,ch;
ht h;
h=init();
list temp;
unsigned int length,address;
char name[20];
char type[5];
while(ch!=6)
{
printf("\n1)INSERT\t2)SEARCH\t3)MODIFY\t4)DISPLAY\t5)DELETE\t6)EXIT");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nENTER THE NAME,TYPE,ADDRESS AND LENGTH");
			 scanf("%s",name);
			 scanf("%s",type);
				scanf("%d",&address);
				scanf("%d",&length);
				i=insert(name,type,address,length,h);
				if(i==1)
						printf("\nSUCCESS");
				else
						printf("\nFAIL");
				break;
case 2:printf("\nENTER THE NAME TO BE SEARCHED");
				scanf("%s",name);
				temp=search(name,h);
				if(temp!=NULL)
					printf("\nPRESENT");
				else
					printf("\nABSENT");
				break;
case 3:printf("\nENTER THE NAME");
				scanf("%s",name);
				printf("ENTER TYPE AND ADDRESS TO MODIFY");
				scanf("%s",type);
				scanf("%d",&address);
				i=modify(name,type,address,h);
				if(i==1)
						printf("\nSUCCESS");
				else
					printf("\nFAILURE");
				break;
case 4:display(h);
				break;
case 5:printf("\nENTER THE NAME TO BE DELETED");
				scanf("%s",&name);
				i=delete(name,h);
				if(i==1)
				printf("\nDELETION SUCCESS");
				else
				printf("\nFAIL");
				break;
}

}
}

ht init()
{
ht h;
int i;
h=(ht)malloc(sizeof(struct hashtable));
h->lists=(list*)malloc(26*sizeof(list));
for(i=0;i<26;i++)
{
	h->lists[i]=(list)malloc(sizeof(struct symbol));
	h->lists[i]->next=NULL;
}
return h;
}

int findhash(char name)
{
int hash=name;
if((hash>=65)&&(hash<=90))
	hash=hash-65;
else if((hash>=97)&&(name<=122))
	hash=hash-97;
	return hash;
}

int insert(char name[20],char type[5],int address,int length,ht h)
{
int hash,ga;
list result,current,temp;
temp=(list)malloc(sizeof(struct symbol));
current=(list)malloc(sizeof(struct symbol));
hash=findhash(name[0]);
result=search(name,h);
if(result==NULL)
{
strcpy(temp->name,name);
strcpy(temp->type,type);
temp->address=address;
temp->length=length;
temp->next=NULL;
current=h->lists[hash];
while(current->next!=NULL)
{
	if(strcmp(current->next->name,temp->name)==0)
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

list search(char name[20],ht h)
{
int hash;
list current;
hash=findhash(name[0]);
current=h->lists[hash]->next;
while(current!=NULL)
{
	if(strcmp(current->name,name)==0)
	{
		return current;
	}
	current=current->next;
}
return NULL;
}


int modify(char name[20],char type[5],int x,ht h)
{
int hash;
list result;
hash=findhash(name[0]);
result=search(name,h);
if(result!=NULL)
{
strcpy(result->type,type);
result->address=x;
return 1;
}
else
return 0;
}

void display(ht h)
{
int i;
list current;
printf("\nNAME\tTYPE\tADDRESS\tLENGTH\n");
for(i=0;i<26;i++)
{
	current=h->lists[i]->next;
	while(current!=NULL)
	{
		printf("\n%s",current->name);
		printf("\t%s",current->type);
		printf("\t%d",current->address);
		printf("\t%d",current->length);
		printf("\n");
		current=current->next;
	}	
}
}
int delete(char name[20],ht h)
{
list temp,current,k;
temp=search(name,h);
if(temp!=NULL)
{
current=findprevious(name,h);
k=current->next;
current->next=current->next->next;
free(k);
}
else
printf("\nELEMENT IS NOT PRESENT");
}

list findprevious(char name[20],ht h)
{
int hash;
list current;
hash=findhash(name[0]);
current=h->lists[hash];
while(current!=NULL)
{
		if(strcmp(current->next->name,name)==0)
			{
				return current;
			}
}
}

