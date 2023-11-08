#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;
void disp();
struct mp1
{
        char addr[50],mnen[20],label[20],operand[20];
};
typedef struct mp1 *node1;
struct symbol
{
	char mnemonic[20],opcode[20];
};
typedef struct symbol *list;
struct hash
{
  	list *lists;
	int size;
};
typedef struct hash *ht;
struct mp
{
	char mnen[20],label[20],operand[20];
};
typedef struct mp *node;
node initialize()
{
	node t;
	t=(node)malloc(sizeof(struct mp));
	return t;
}
node1 initialize2()
{
        node1 t;
        t=(node1)malloc(sizeof(struct mp1));
        return t;
}
int sizes();
int search(char name[50])
{
	FILE *fp2;
        fp2=fopen("opcode.bin","rb");
        node nn;
        char c;
        nn=initialize();
        int g=0,i=0;
        g=sizes();
        while(i<g)
        {
                fseek(fp2,sizeof(node)*i,SEEK_SET);
                fread(&nn,sizeof(node),1,fp2);
                if(strcmp(nn->mnen,name)==0)
                {
                        fclose(fp2);
                        return 1;
                }
                i++;
        }
        fclose(fp2);
        return 0;
}
int sizes()
{
        FILE *fp1;
        node nn;
        char c;
        int g=0;
        nn=initialize();
        fp1=fopen("alp.bin","rb");
        while((c = fgetc(fp1)) != EOF)
        {
                fseek(fp1,sizeof(node)*g,SEEK_SET);
                g++;
        }
        g--;
        fclose(fp1);
        return g;
}
ht initialize1()
{
	int i;
	ht k;
	k=(ht)malloc(sizeof(struct hash));
	k->size=0;
	k->lists=(list*)malloc(50*sizeof(struct symbol));
	for(i=0;i<50;i++)
		k->lists[i]=(list)malloc(sizeof(struct symbol));
	return k;
}
int insert(char name[50],char type[50],char addr[50],FILE *fp)
{
        int n=0,i,j;
        node nn;
        nn=initialize();
        strcpy(nn->label,name);
        strcpy(nn->mnen,type);
        strcpy(nn->operand,addr);
        fwrite(&nn,sizeof(node),1,fp);
//      fclose(fp);
        return 1;
}
void display1()
{
	fp=fopen("alp.bin","rb");
	node nn;
	int t=0;
	char c;
  	nn=initialize();
	while((c = fgetc(fp)) != EOF)
	{
		fseek(fp,sizeof(node)*t,SEEK_SET);
		fread(&nn,sizeof(node),1,fp);
		printf(" %s\t %s\t %s\t",nn->label,nn->mnen,nn->operand);
		printf("\n");
		t++;
		fseek(fp,sizeof(node)*t,SEEK_SET);
	}
	fclose(fp);
}
void insert1()
{
	FILE *fp;
	int t=0;
	fp=fopen("alp.bin","wb+");
	char s[50],label[50],mnen[50],operand[50];
	printf("TO FINISH THE STRING PRESS '$' OR PRESS '#',PLEASE ENTER / FOR NO CHARACTER");
	s[0]='#';
	while(s[0]!='$')
	{
		scanf("%s%s%s%s",label,mnen,operand,s);
		t=insert(label,mnen,operand,fp);
//		printf(" %s\t %s\t %s\t",label,mnen,operand);
	}
	fclose(fp);
}
ht searchop(node nn,ht htt)
{
	int i;
	char opcod[3][10]={"LDA","ADD","STA"};
	char opnum[3][10]={"00","18","0C"};
	for(i=0;i<3;i++)
	{
		if(strcmp(nn->mnen,opcod[i])==0)
		{
			strcpy(htt->lists[htt->size]->mnemonic,nn->mnen);
			strcpy(htt->lists[htt->size]->opcode,opnum[i]);
			htt->size++;
		}
	}
	return htt;
}
int optabseperation()
{
	FILE *fp,*fp3;
        fp3=fopen("opcode.bin","wb+");
        int t=0,i,j=0,m=0;
	node nn;
	nn=initialize();
        fp=fopen("alp.bin","rb+");
	ht htt;
	htt=initialize1();
//	display1();
	t=sizes();
	for(i=0;i<t;i++)
	{
		fseek(fp,sizeof(node)*m,SEEK_SET);
                fread(&nn,sizeof(node),1,fp);
//		printf("\n\n%s",nn->mnen);
		if(search(nn->mnen))
		{
			m++;
                	fseek(fp,sizeof(node)*m,SEEK_SET);
			continue;
		}
		else
		{
			htt=searchop(nn,htt);
			fwrite(&htt,sizeof(ht),1,fp3);
		}
		m++;
                fseek(fp,sizeof(node)*m,SEEK_SET);
	}
	fclose(fp3);
	fclose(fp);
	return 0;
}
void displayy()
{
	fp=fopen("opcode.bin","rb+");
        ht nn;
        int t=0;
        char c;
        nn=initialize1();
	printf("\nOPTAB");
	printf("\nMNEMONIC\tOPCODE\n");
        while((c = fgetc(fp)) != EOF)
        {
                fseek(fp,sizeof(ht)*t,SEEK_SET);
                fread(&nn,sizeof(ht),1,fp);
                printf(" %s\t %s\t",nn->lists[t]->mnemonic,nn->lists[t]->opcode);
                printf("\n");
                t++;
                fseek(fp,sizeof(ht)*t,SEEK_SET);
        }
        fclose(fp);
}
char convert(int add)
{
	if(add<9)
	{
		return add+48;
	}
	else
	{
		switch(add)
		{
			case 10:	return 'A';
					break;
			case 11:        return 'B';
                                        break;
			case 12:        return 'C';
                                        break;
			case 13:        return 'D';
                                        break;
			case 14:        return 'E';
                                        break;
			case 15:        return 'F';
                                        break;
		}
	}
	return '\0';
}
void address()
{
	 FILE *fp4,*fp;
        node1 nn1;
	char addr1[50],add[50];
        fp4=fopen("toksep.bin","wb+");
        nn1=initialize2();
        int t=0,i,j=0,m=0,addr=0,n,k;
	char a[50];
        node nn;
        nn=initialize();
        fp=fopen("alp.bin","rb+");
	fseek(fp,sizeof(node),SEEK_SET);
        fread(&nn,sizeof(node),1,fp);
	if(strcmp(nn->mnen,"START")==0)
	{
		strcpy(a,nn->operand);
		for(i=0;i<strlen(a);i++)
		{
			j=a[i]-48;
			addr=addr*10+j;
		}
	}
	t=sizes();
	printf("%d",t);
        for(i=1;i<t;i++)
        {
		if(m!=0)
			fp4=fopen("toksep.bin","ab+");
                fseek(fp,sizeof(node)*i,SEEK_SET);
                fread(&nn,sizeof(node),1,fp);
		printf("%s",nn->mnen);
		if(strcmp(nn->mnen,"RESW")!=0||strcmp(nn->mnen,"RESB")!=0||strcmp(nn->mnen,"BYTE")!=0)
		{
			addr=addr+3;
		}
		else if(strcmp(nn->mnen,"RESW")!=0)
		{
			j=strlen(nn->operand);
			addr=addr+(j*3);
		}
		else if(strcmp(nn->mnen,"RESB")!=0)
                {
                        j=strlen(nn->operand);
                        addr=addr+(j*1);
                }
		else if(strcmp(nn->mnen,"BYTE")!=0)
                {
                        if(nn->operand[0]=='c')
			{
				j=strlen(nn->operand)-3;
				addr=addr+j;
			}
			else
			{
				j=strlen(nn->operand)-3;
                                addr=addr+(j/2);
			}
                }
//		printf("%d",addr);
		n=addr;
		k=0;
		while(n!=0)
		{
			j=n%10;
			n=n/10;
			addr1[k]=convert(j);
			k++;
		}
//		printf("%s",addr1);
		n=k;
		k=0;
		for(j=n-1;j>=0;j--)
		{
			add[k]=addr1[j];
			k++;
		}
		printf("\t%s",add);
		strcpy(nn1->addr,add);
		strcpy(nn1->mnen,nn->mnen);
		strcpy(nn1->label,nn->label);
		strcpy(nn1->operand,nn->operand);
		printf("%s",nn1->operand);
		fwrite(&nn1,sizeof(node1),1,fp4);
		m=1;
		fclose(fp4);
		disp();
	}
//	fclose(fp4);
	fclose(fp);
}
void disp()
{
	FILE *fp;
	fp=fopen("toksep.bin","rb");
        node1 nn;
        int t=0;
        char c;
        nn=initialize2();
        while((c = fgetc(fp)) != EOF)
        {
                fseek(fp,sizeof(node1)*t,SEEK_SET);
                fread(&nn,sizeof(node1),1,fp);
                printf(" %s\t %s\t %s\t %s\t",nn->addr,nn->label,nn->mnen,nn->operand);
                printf("\n");
                t++;
                fseek(fp,sizeof(node1)*t,SEEK_SET);
        }
        fclose(fp);
}
void symtabseperation()
{
	node nn;
	int t=0,i,j=0,m=0;
        nn=initialize();
        fp=fopen("alp.bin","rb+");
	
}
int main()
{
	int i;
	insert1();
//	display1();
	i=optabseperation();
	displayy();
	address();
	disp();
	return 0;
}
