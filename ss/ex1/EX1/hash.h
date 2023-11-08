struct SymbolNode
{
	char SymbolName[10];
	char SegmentName[10];
	char Type[5];
	int Length;
	int Adrs;
  struct SymbolNode *next;
};

typedef struct SymbolNode* list;

struct SymbolTable
{
	list *Bucket;
};

typedef struct SymbolTable *HashTable;

HashTable HT;

HashTable initialize();
int Hash(char*);
list Search(HashTable,char*,char*);
void Insert(HashTable,char*,char*,char*,int,int);
void Modify(HashTable,char*,char*,char*,int ,int);
void Delete(HashTable,char*,char*);
void Display(HashTable);
void DeAllocated(HashTable);

