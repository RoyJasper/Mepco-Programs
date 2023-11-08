#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct  node
{
    char *label;
    char *opcode;
    int loc;
    char *operand;

};

typedef struct node token;

struct sym_node
{
    char *sym_name;
    int  loc;
    char *seg_name;
    int  length;
    char *type;
};

typedef struct sym_node table;

void Pass1(char*,char*,char*);

token seperate_token(char*);

void IntermediateFile(char*,token);

void SymbolTable(char*,table);

int search(char*,char*,char*);

void DisplayIntermediatefile(char*);

void DisplaySymbolTable(char*);

