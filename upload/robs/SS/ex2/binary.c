#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol
{
	char name[20],type[20];
	int address,length;
};
FILE *fp;
typedef struct symbol *node;
node initialize();
int sizes();
int search(char []);
int insert(char name[50],char type[50],int address,int length)
{
	int n=0,i,j;
	node nn,mm[50];
	nn=initialize();
	if(sizes()>=0)
	{
		n=search(name);
		fp=fopen("saved.bin","ab+");
	}
//	printf("%d",sizes());
	if(n!=1)
	{
		strcpy(nn->name,name);
		strcpy(nn->type,type);
		nn->address=address;
    		nn->length=length;
    		fwrite(&nn,sizeof(node),1,fp);
		fclose(fp);
		for(i=0;i<50;i++)
			mm[i]=initialize();
		n=sizes();
		i=0;
		fp=fopen("saved.bin","rb");
		if(n!=1)
		{
        		while(i<n)
        		{
				fread(&nn,sizeof(node),1,fp);
               			strcpy(mm[i]->name,nn->name);
        			strcpy(mm[i]->type,nn->type);
                		mm[i]->address=nn->address;
                		mm[i]->length=nn->length;
                		i++;
               			fseek(fp,sizeof(node)*i,SEEK_SET);
        		}
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(strcmp(mm[i]->name,mm[j]->name)>0)
					{
						nn=mm[i];
						mm[i]=mm[j];
						mm[j]=nn;
					}
				}
			}
			fclose(fp);
			fp=fopen("saved.bin","wb");
        		for(i=0;i<n;i++)
        		{
        			fwrite(&mm[i],sizeof(node),1,fp);
        		}
        		fclose(fp);
		}
	}
	else
	{
		printf("ALREADY PRESENT");
		return 0;
	}
	return 1;
}
void display();
node initialize()
{
	node nn;
	nn=(node)malloc(sizeof(struct symbol));
	return nn;
}
int search(char []);
int sizes()
{
	FILE *fp1;
	node nn;
  	char c;
  	int g=0;
  	nn=initialize();
	fp1=fopen("saved.bin","rb");
	while((c = fgetc(fp1)) != EOF)
 	{
		fseek(fp1,sizeof(node)*g,SEEK_SET);
		g++;
	}
	g--;
	fclose(fp1);
	return g;
}
int delete(char name[50])
{	
	node nn[50],mm;
	char c;
	int g,i,n,k;
	mm=initialize();
	for(i=0;i<50;i++)
		nn[i]=initialize();
	g=search(name);
	if(g==1)
	{
		i=0;
		n=sizes();
		fp=fopen("saved.bin","rb");
		while(i<n)
		{	
			fread(&mm,sizeof(node),1,fp);
			strcpy(nn[i]->name,mm->name);
        		strcpy(nn[i]->type,mm->type);
			nn[i]->address=mm->address;
			nn[i]->length=mm->length;
			i++;
			fseek(fp,sizeof(node)*i,SEEK_SET);
		}
		for(i=0;i<n;i++)
		{
			if(strcmp(nn[i]->name,name)==0)
			{
				for(k=i+1;k<n;k++)
				{
					strcpy(nn[k-1]->name,nn[k]->name);
                        		strcpy(nn[k-1]->type,nn[k]->type);
          				nn[k-1]->address=nn[k]->address;
          				nn[k-1]->length=nn[k]->length;
				}
				n--;
			}
		}
		fclose(fp);
		fp=fopen("saved.bin","wb");
		for(i=0;i<n;i++)
		{
			fwrite(&nn[i],sizeof(node),1,fp);
		}
		fclose(fp);
		return 1;
	}
	else
	{
		printf("ELEMENT NOT PRESENT");
	}
}
int search(char name[50])
{
	fp=fopen("saved.bin","rb");
	node nn;
	char c;
	nn=initialize();
	int g=0,i=0;
	g=sizes();
	while(i<g)
	{
		fseek(fp,sizeof(node)*i,SEEK_SET);
		fread(&nn,sizeof(node),1,fp);
		if(strcmp(nn->name,name)==0)
		{
			fclose(fp);
			return 1;
		}
		i++;
	}
	fclose(fp);
	return 0;
}
void display()
{
	fp=fopen("saved.bin","rb");
	node nn;
	int t=0;
	char c;
  	nn=initialize();
	while((c = fgetc(fp)) != EOF)
	{
		fseek(fp,sizeof(node)*t,SEEK_SET);
		fread(&nn,sizeof(node),1,fp);
		printf(" %s\t %s\t %d\t %d\t",nn->name,nn->type,nn->address,nn->length);
		printf("\n");
		t++;
		fseek(fp,sizeof(node)*t,SEEK_SET);
	}
	fclose(fp);
}
int modify(char name[50],char type[50])
{
	int n,i,g;
	node nn[50],mm;
	n=sizes();
	mm=initialize();
	for(i=0;i<50;i++)
		nn[i]=initialize();
	g=search(name);
	i=0;
	if(g==1)
	{
		fp=fopen("saved.bin","rb");
                while(i<n)
                {
                        fread(&mm,sizeof(node),1,fp);
                        strcpy(nn[i]->name,mm->name);
                        strcpy(nn[i]->type,mm->type);
                        nn[i]->address=mm->address;
                        nn[i]->length=mm->length;
                        i++;
                        fseek(fp,sizeof(node)*i,SEEK_SET);
                }
		for(i=0;i<n;i++)
		{
			if(strcmp(nn[i]->name,name)==0)
			{
				strcpy(nn[i]->type,type);
			}
		}
		fclose(fp);
                fp=fopen("saved.bin","wb");
                for(i=0;i<n;i++)
                {
                        fwrite(&nn[i],sizeof(node),1,fp);
                }
                fclose(fp);
		return 1;
	}
        else
        {
                printf("ELEMENT NOT PRESENT");
        }
}
int modify1(char name[50],int address)
{
        int n,i,g;
        node nn[50],mm;
        n=sizes();
        mm=initialize();
        for(i=0;i<50;i++)
                nn[i]=initialize();
        g=search(name);
        i=0;
        if(g==1)
        {
                fp=fopen("saved.bin","rb");
                while(i<n)
                {
                        fread(&mm,sizeof(node),1,fp);
                        strcpy(nn[i]->name,mm->name);
                        strcpy(nn[i]->type,mm->type);
                        nn[i]->address=mm->address;
                        nn[i]->length=mm->length;
                        i++;
                        fseek(fp,sizeof(node)*i,SEEK_SET);
                }
                for(i=0;i<n;i++)
                {
                        if(strcmp(nn[i]->name,name)==0)
                        {
                                nn[i]->address=address;
                        }
                }
                fclose(fp);
                fp=fopen("saved.bin","wb");
                for(i=0;i<n;i++)
                {
                        fwrite(&nn[i],sizeof(node),1,fp);
                }
                fclose(fp);
		return 1;
	}
        else
        {
                printf("ELEMENT NOT PRESENT");
        }
}

int main()
{
  int length,address,j=0,choice,i,t;
  char name[50],type[50];
  while(1)
  {
    printf("\n1.INSERT\n2.SEARCH\n3.MODIFY\n4.DELETE\n5.DISPLAY\n6.EXIT\nENTER THE CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	if(j==0)
		fp=fopen("saved.bin","wb+");
	else
		fp=fopen("saved.bin","ab+");
	j=1;
        printf("ENTER THE NAME,TYPE,ADDRESS,LENGTH:\n");
        scanf("%s%s%d%d",name,type,&address,&length);
        i=insert(name,type,address,length);
        if(i==1)
          printf("\nINSERTED SUCCESSFULLY");
        else
          printf("\nNOT INSERTED SUCCESSFULLY");
        break;
      case 2:
        printf("ENTER THE NAME:");
        scanf("%s",name);
        t=search(name);
        if(t==1)
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
          i=modify(name,type);
          if(i==1)
            printf("MODIFIED");
          else
            printf("NOT MODIFIED");
        }
        else
        {
          printf("ENTER THE VALUE FOR ADDRESS:");
          scanf("%d",&address);
          i=modify1(name,address);
          if(i==1)
            printf("MODIFIED");
          else
            printf("NOT MODIFIED");
        }
        break;
      case 4:
        printf("ENTER THE NAME");
        scanf("%s",name);
        i=delete(name);
        if(i==1)
          printf("DELETED");
        else
          printf("NOT DELETED");
        break;
      case 5:
        display();
        break;
      case 6:
        exit(0);
    }
  }
}
