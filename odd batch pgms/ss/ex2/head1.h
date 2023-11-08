#include"../ex1/head.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/*typedef struct node
{
  char symName[20];
  char symType;
  char segName[20];
  unsigned address;
  unsigned length;
  struct node *next;
}node;
typedef node *list;
typedef struct hashTable
{
  list *lists;
}hashTable;
typedef hashTable *hptr;
hptr hp;
hptr createSymTable();
node* searchASymbol(char*,char*,hptr);*/
int byteseparate(char*);
hptr hp;
/*int displaySymTable(hptr);
int modify(char*,char*,char,unsigned,unsigned,hptr);
int insert(char*,char*,char,int,int,hptr);
int isEmpty(hptr);
int computeIndex(char);*/
typedef struct Oneline
{
  char label[20];
  char opcode[20];
  char operand1[20];
  char operand2[20];
  int lc;
}Oneline;
int intermediateFileGenerator();
struct Oneline separateTokens(char *line);
void write(struct Oneline,FILE *op);
void writeIntoFile(struct Oneline,FILE*);
int isRegister(char *);
int searchOPTAB(char *);
