#include"hash.h"
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
HashTable initialize()
{
	HashTable h;
	int i;
	h=malloc(sizeof(HashTable));
	h->Bucket = malloc(sizeof(list)*26);
	for(i=0;i<26;i++)
  {
		h->Bucket[i] = malloc(sizeof(struct SymbolNode));
        h->Bucket[i]->next = NULL;
  }
  return h;
}

void Insert(HashTable HT,char*symname,char*segname,char*type,int length,int adrs)
{
    list temp;
    list sn = malloc(sizeof(struct SymbolNode));
    strcpy(sn->SymbolName,symname);
    strcpy(sn->SegmentName,segname);
    strcpy(sn->Type,type);
    sn->Length = length;
    sn->Adrs = adrs;
   	int key = Hash(sn->SymbolName);
    temp = HT->Bucket[key];

    while( temp->next!=NULL && strcmp(temp->next->SymbolName,sn->SymbolName) <0 )
	  {
		    temp = temp->next;
	  }

 	  if(temp->next == NULL)
	  {
	    	sn->next = temp->next;
		    temp->next = sn;
		    return;
	  }

	  if(strcmp(temp->next->SymbolName,sn->SymbolName)>0)
	  {
		   sn->next = temp->next;
		   temp->next = sn;
		   return;
	  }

	  if(strcmp(temp->next->SymbolName,sn->SymbolName)==0)
	  {
		    while((temp->next!=NULL) && strcmp(temp->next->SymbolName,sn->SymbolName)==0 && strcmp(temp->next->SegmentName,sn->SegmentName)<0)
		    {
				    temp=temp->next;
		    }
		    sn->next=temp->next;
		    temp->next = sn;
		    return;
	  }

}

int Hash(char*key)
{
    return (toupper(key[0])-65);
}

list Search(HashTable HT,char*sym,char*seg)
{
	list p;
	p=HT->Bucket[Hash(sym)];
	while(p->next!=NULL)
	{
		p=p->next;
		if((strcmp(p->SymbolName,sym)==0) && (strcmp(p->SegmentName,seg)==0))
		{
			return p;
		}
	}
	return NULL;
}

void Delete(HashTable HT,char*sym,char*seg)
{
 	  list p,q;
    p=HT->Bucket[Hash(sym)];
    while(p->next!=NULL)
    {
      q=p;
      p=p->next;
      if((strcmp(p->SymbolName,sym)==0) && (strcmp(p->SegmentName,seg)==0))
      {
        q->next = p->next;
        return;
      }
    }
}

void Display(HashTable HT)
{
    int i;
	list temp;
	printf("\n\n BucketNO   Symbol   Segment  Type  Length   Address");
    for(i=0;i<26;i++)
	{
		temp=HT->Bucket[i];
		temp=temp->next;
        while(temp!=NULL)
		{
			printf("\n %d %13s  %5s  %6s  %5d  %7d ",i,temp->SymbolName,temp->SegmentName,temp->Type,temp->Length,temp->Adrs);
			temp=temp->next;
		}
	}
}

void  Modify(HashTable HT,char*sym,char*seg,char*type,int len,int adrs)
{
	list p;
	p=HT->Bucket[Hash(sym)];
	while(p->next!=NULL)
	{
		p=p->next;
		if((strcmp(p->SymbolName,sym)==0) && (strcmp(p->SegmentName,seg)==0))
		{
            if(strcmp(type,"NULL")!=0)
                strcpy(p->Type,type);
            if(len!=-1)
                p->Length = len;
            if(adrs!=-1)
                p->Adrs = adrs;
            return;
		}
	}
}

void DeAllocated(HashTable HT)
{
	int i;
	list temp,temp1;
	for(i=0;i<26;i++)
	{
  	temp = HT->Bucket[i];
		while(temp->next!=NULL)
    {
      temp1 = temp;
			temp = temp->next;
      free(temp1);
		}
  }
}
