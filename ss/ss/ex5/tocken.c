#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void display();
void displayoptab();
void displaysymtab();
void insertoptab();
void insertsymtab();
void insert();
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
char* add(char a[],char b[])
{
    int hex[20], dec,i,  j, k,ch, p;
    i =0;
    p=0;
    dec=0;
    k=0;
    while ((ch=a[k++]) != '\0')
    {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
    }
    for (j = i-1; j >= 0; j-- )
    {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);
        p++;
    }
    i =0;
    p=0;
    k=0;
    while ((ch=b[k++]) != '\0')
    {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
    }
    for (j = i-1; j >= 0; j-- )
    {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);
        p++;
    }
    int temp,quotient;
    char h[100];
    quotient = dec;
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
    for (j = i -1 ; j> 0; j--)
        he[k++]=h[j];
    he[k]='\0';
    return he;
}
char* converttohexa(char q[])
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
    for (j = i -1 ; j>= 0; j--)
        he[k++]=h[j];
    he[k]='\0';
    return he;

}
void displayoptab()
{

    FILE *fp3;
    struct tab tt;
    fp3=fopen("optab.bin","ab+");
    while (fread(&tt,sizeof(struct tab),1,fp3) )//!= NULL)
    {
        if(strcmp(tt.mne,"$")!=0)
        {
            printf("\n  %s",tt.mne);
            printf("\t  %s",tt.obj);
        }
    }
    fclose(fp3);
}
void displaysymtab()
{
    FILE *fp3;
    struct tab tt;
    fp3=fopen("symtab.bin","ab+");
    while (fread(&tt,sizeof(struct tab),1,fp3) )//!= NULL)
    {
        if(strcmp(tt.mne,"$")!=0)
        {
            printf("\n  %s",tt.mne);
            printf("\t  %s",tt.obj);
        }
    }
    fclose(fp3);
}
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
void insert(char a[],char b[],char c[],char d[],char e[])
{
    FILE *fp;
    struct table t;
    fp=fopen("table.bin","ab+");
    strcpy(t.loc,a);
    strcpy(t.label,b);
    strcpy(t.mnemonic,c);
    strcpy(t.operand,d);
    strcpy(t.code,e);
    fwrite(&t, sizeof(struct table), 1, fp);

    fclose(fp);
}
void insertoptab(char a[],char b[])
{
    struct tab tt;
    FILE *fp;
    fp=fopen("optab.bin","ab+");
    strcpy(tt.mne,a);
    strcpy(tt.obj,b);
    fwrite(&tt, sizeof(struct tab), 1, fp);
    fclose(fp);
}
void insertsymtab(char a[],char b[])
{
    struct tab tt;
    FILE *fp;
    fp=fopen("symtab.bin","ab+");
    strcpy(tt.mne,a);
    strcpy(tt.obj,b);
    fwrite(&tt, sizeof(struct tab), 1, fp);
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

int checkmne(char xx[])
{
    int i;
    char d[11][20]= {"ADD","AND","COMP","DIV","J","JLT","JSUB","LDA","STA","STL","TIX"};
    for( i=0; i<11; i++)
    {
        if(strcmp(d[i],xx)==0)
            return i;
    }
    return -1;
}
char* convert(char xs[],int key)
{
    int hex[20], dec,i,  j, k,ch, p;
    i =0;
    p=0;
    dec=0;
    k=0;
    while ((ch=xs[k++]) != '\0')
    {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
    }
    for (j = i-1; j >= 0; j-- )
    {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);
        p++;
    }
    int temp,quotient;
    char h[100];
    quotient = dec+key;
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
    k=0;
    char *he = (char*)malloc(sizeof(char)*100);
    for (j = i -1 ; j> 0; j--)
        he[k++]=h[j];
    he[k]='\0';
    return he;
}
main()
{
    remove("optab.bin");
    remove("symtab.bin");
    remove("table.bin");
    int i,g;
    FILE *fp,*fp3;
    struct table t;
    struct tab tt;
    char e[11][20]= {"18","40","28","24","3C","38","48","00","0C","14","2C"};
    char loc[10],loc2[10],*loc3;
    int m,l;
    int flag=0,j,y;
    FILE *fp2;
    fp2=fopen("code.c","r");
    char x,p[20],q[20],r[20];
    x=getc(fp2);
    while(x!=EOF)
    {
        if(x=='^')
        {
            x=getc(fp2);
            //    printf("\n enter in");
            i=0;
            while(x!='^')
            {
                p[i]=x;
                i++;
                x=getc(fp2);
            }
            p[i]='\0';
            i=0;
            x=getc(fp2);
            while(x!='\n')
            {
                q[i]=x;
                i++;
                x=getc(fp2);
            }
            q[i]='\0';
              printf("\n p==%s\nq==   %s",p,q);
        }
        else
        {
            i=0;
            while(x!='^')
            {
                p[i]=x;
                i++;
                x=getc(fp2);
            }
            p[i]='\0';
            if(strcmp(p,"END")==0)
            {
                insert(loc,"$",p,"$","$");
                goto jas;
            }
            i=0;
            x=getc(fp2);
            while(x!='^')
            {
                q[i]=x;
                i++;
                x=getc(fp2);
            }
            q[i]='\0';

        }

        if(strcmp(q,"START")==0)
        {
            i=0;
            x=getc(fp2);
            while(x!='\n')
            {
                r[i]=x;
                i++;
                x=getc(fp2);
            }
            r[i]='\0';
            strcpy(loc,r);
            insert("$",p,q,r,"$");
        }
        else if(strcmp(p,"START")==0)
        {
            insert("$","$",p,q,"$");
            strcpy(loc,q);
            x=getc(fp2);
        }
        else if(checkmne(p)>-1)
        {
            g=checkmne(p);
            loc3=convert(loc,3);
            strcpy(loc2,loc3);
            insert(loc,"$",p,q,"$");
            strcpy(loc,loc2);
            insertoptab(p,e[g]);
//x=getc(fp2);
        }
        else if(check(q)!=1 && checkmne(q)>-1)
        {
            // printf("\n not in");
            i=0;
            x=getc(fp2);
            while(x!='\n')
            {
                r[i]=x;
                i++;
                x=getc(fp2);
            }
            r[i]='\0';
            g=checkmne(q);
            insertsymtab(p,loc);
            insert(loc,p,q,r,"$");
            loc3 = convert(loc,3);
            strcpy(loc2,loc3);
            strcpy(loc,loc2);
            insertoptab(q,e[g]);
        }
        else if(check(q)==1)
        {
            i=0;
            x=getc(fp2);
            while(x!='\n')
            {
                r[i]=x;
                i++;
                x=getc(fp2);
            }
            r[i]='\0';
            insertsymtab(p,loc);
            if(strcmp(q,"RESW")==0)
            {
                l=strlen(r);
                int uu;
                if(l==1)
                {
                    char u=r[0];
                    m=u-48;
                    uu=3*m;
                    loc3=convert(loc,uu);
                }


                insert(loc,p,q,r,"$");
                strcpy(loc2,loc3);
                strcpy(loc,loc2);
            }
            else if(strcmp(q,"RESB")==0)
            {
                int uu;

                char *u,v[100];
                u=converttohexa(r);
                strcpy(v,u);

                strcpy(loc3,add(loc,v));
                insert(loc,p,q,r,"$");
                strcpy(loc2,loc3);
                strcpy(loc,loc2);
            }
            else if(strcmp(q,"WORD")==0)
            {
                l=strlen(q);
                insert(loc,p,q,r,"$");
                loc3=convert(loc,3);
                strcpy(loc2,loc3);
                strcpy(loc,loc2);
            }

            else if(strcmp(q,"BYTE")==0)
            {
                int l2=strlen(r);
                if(r[0]=='C')
                {
                    insert(loc,p,q,r,"$");
                    loc3=convert(loc,l2-3);
                    strcpy(loc2,loc3);
                    strcpy(loc,loc2);
                }
                else if(r[0]=='X')
                {
                    insert(loc,p,q,r,"$");
                    loc3=convert(loc,(l2-3)/2);
                    strcpy(loc2,loc3);
                    strcpy(loc,loc2);
                }
            }
        }
        x=getc(fp2);
    }
    insert("$","$","$","$","$");
    insertoptab("$","$");
    insertsymtab("$","$");
jas:
    printf("\n***************************************************\n   LOC LABLE MNEMONIC OPERAND OPCODE\n***************************************************\n");
    display();
    printf("\n\n************************************************\n\t\tOPTAB\n************************************************\n");
    displayoptab();
    printf("\n*************************************************\n\t\t SYMTAB\n************************************************\n\n");
    displaysymtab();
    printf("\n*************************************************");

}
