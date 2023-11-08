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
void display()
{
    FILE *fp;
    struct table t;
    fp=fopen("table.bin","ab+");
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
    char c[4][20]= {"WORD","BYTE","RESW","RESB"};
    for(i=0; i<4; i++)
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
main()
{
    int i,j,k;
    FILE *fp4;
    struct table t;
    char a[20],b[20],*c,*d;
    struct tab tt;
    fp4=fopen("table.bin","wb+");
    while (fread(&t,sizeof(struct table),1,fp4))
    {
        printf("enter");
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
                int lc=strlen(c);
                int ld=strlen(d);
                i=0;
                for(j=0; j<lc; j++)
                {
                    a[i]=c[j];
                    i++;
                }
                for(k=0; k<ld; k++)
                {
                    a[i]=c[k];
                    i++;
                }
                printf("string %s",a);

                strcpy(t.code,a);
            }

        }
    }
    fclose(fp4);
    display();
}
