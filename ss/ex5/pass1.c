#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
    struct table
{
char loc[10];
char label[10];
char mnemonic[10];
char operand[10];
char code[10];
};
struct tab
{
char mne[10];
char obj[10];
};
void insert(char [],char [],char [],char [],char []);
void display();
int check(char []);
char* valueoptab(char []);
char* valuesymtab(char []);
char* convert(char []);


void insert(char a[],char b[],char c[],char d[],char e[])
{
 FILE *fp;
 struct table t;
  fp=fopen("table2.bin","ab+");
      strcpy(t.loc,a);
       strcpy(t.label,b);
      strcpy(t.mnemonic,c);
      strcpy(t.operand,d);
      strcpy(t.code,e);
      fwrite(&t, sizeof(struct table), 1, fp);
     fclose(fp);
     //printf("\n inserted");
}
void display()
{
     FILE *fp;
     struct table t;
    fp=fopen("table2.bin","ab+");
    while (fread(&t,sizeof(struct table),1,fp) )// != NULL)
    {
        if(strcmp(t.mnemonic,"$")!=0)
        {
            printf("\n  %s",t.loc);
            printf("\t  %s",t.label);
            printf("\t  %s",t.mnemonic);
            printf("\t  %s",t.operand);
            printf("\t  %s",t.code);
        }
    }
    fclose(fp);
}
int check(char xx[10])
{
    int i;
    char c[4][20]={"WORD","BYTE","RESW","RESB"};
for(i=0;i<4;i++)
{
if(strcmp(c[i],xx)==0)
{
    return 1;
}
}
return 0;
}
 char* valueoptab(char a[])
{
    struct tab tt;
     FILE *fp3;
    fp3=fopen("optab.bin","ab+");
    char *aa = (char*)malloc(sizeof(char)*100);
     while (fread(&tt,sizeof(struct tab),1,fp3) )
    {
        if(strcmp(tt.mne,a)==0)
        {
            strcpy(aa,tt.obj);
            return aa;
        }
    }
     fclose(fp3);
}
char* valuesymtab(char a[])
{
    struct tab tt;
     FILE *fp;
  fp=fopen("symtab.bin","ab+");
    char *aa = (char*)malloc(sizeof(char)*100);
     while (fread(&tt,sizeof(struct tab),1,fp) )
    {
        if(strcmp(tt.mne,a)==0)
        {
            strcpy(aa,tt.obj);
            return aa;
        }
    }

     fclose(fp);
}
char* convert(char q[])
{

       int quotient=0,i,n,m;
       quotient=atoi(q);
      int temp,k,j;
i=0;
      char h[100];
        while(quotient!=0)
    {
    temp = quotient % 16;
    if( temp < 10)
      temp=temp + 48;
    else
       temp = temp + 55;
    h[i++]= temp;
    quotient = quotient / 16;
    }
     h[i]='\0';

    k=0;
    char *he = (char*)malloc(sizeof(char)*100);
    for (j = i -1 ;j>= 0;j--)
    he[k++]=h[j];
    he[k]='\0';
    return he;

}
main()
{
    remove("table2.bin");
    int i,j,k;
     FILE *fp4;
     struct table t;
     char a[20],b[20],*c,*d,e[100],f[100];
     struct tab tt;
    fp4=fopen("table.bin","ab+");
    while (fread(&t,sizeof(struct table),1,fp4))
    {
        if(strcmp(t.mnemonic,"$")!=0)
        {
           if(strcmp(t.mnemonic,"START")==0)
           {

           }
           else if(strcmp(t.mnemonic,"END")==0)
           {

           }
           else if(check(t.mnemonic)==0)
           {
               c=valueoptab(t.mnemonic);
               d=valuesymtab(t.operand);
               strcpy(e,c);
               strcpy(f,d);
               i=0;
               for(j=0;j<2;j++)
               {
                   a[i]=e[j];
                   i++;
               }
               for(k=0;k<4;k++)
               {
                   a[i]=f[k];
                   i++;
               }
               a[i]='\0';
               strcpy(t.code,a);
           }
           else if(check(t.mnemonic)==1)
           {
               if(strcmp(t.mnemonic,"BYTE")==0)
               {
                strcpy(a,t.operand);
                int al=strlen(a);
                if(a[0]=='C')
                {
                    int temp,quotient;
                    k=0;
                    for(i=2;i<al-1;i++)
                    {
                        j=0;
                        quotient=a[i];
                         while(quotient!=0)
                          {
            temp = quotient % 16;
            if( temp < 10)
            temp=temp + 48;
            else
            temp = temp + 55;
            e[j++]= temp;
            quotient = quotient / 16;
                    }
            b[k++]=e[1];
            b[k++]=e[0];

                    }
                    b[k]='\0';
                    strcpy(t.code,b);
                }
                else if(a[0]=='X')
                {
                    j=0;
                  for(i=2;i<al-1;i++)
                    {
                        b[j]=a[i];
                        j++;

                    }
                    b[j]='\0';
                    strcpy(t.code,b);
                }
               }
               else if(strcmp(t.mnemonic,"WORD")==0)
               {
                   j=0;k=0;
                  d=convert(t.operand);
                  strcpy(e,d);
                  int el=strlen(e);
                  for(i=1;i<=6-el;i++)
                  {
                      f[j]=48;
                      j++;
                  }
                  for(i=6-el+1;i>=0;i--)
                  {
                      f[j]=e[k];
                      j++;
                      k++;
                  }
                  f[j]='\0';
                  strcpy(t.code,f);
               }
           }
   insert(t.loc,t.label,t.mnemonic,t.operand,t.code);
        }
    }
    fclose(fp4);
    printf("\n    PASS ONE OF TWO PASS ASSEMBLER\n");
   printf("\n***************************************************\n  LOC   LABLE   MNEMONIC OPERAND OPCODE\n***************************************************\n");
display();
printf("\n\n************************************************\n");
}
