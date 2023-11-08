#include"pass1.h"
int first=0;
void Pass1(char*src,char*imf,char*symtab)
{
    FILE *fp1;
    fp1 = fopen(src,"r");
    token T;
    char segname[10],a[40][40],b;
    char opr[3][5];
    int x,y;
    int adrs=0,i=0,j=0,count=0;
    segname[0]='\0';

    while(!feof(fp1))
    {
        fscanf(fp1,"%c",&b);
        if(b!='\n')
        {
            a[i][j] = b;
            j++;
        }
        else
        {
            a[i][j] = '\0';
            i++;
            j=0;
        }
    }
    count = i-1;
    printf("%d",count);
    for(i=0;i<count;i++)
    {
       T = seperate_token(a[i]);
       if(strcmp(T.opcode,"ORG")==0)
       {
          adrs = atoi(T.operand);
       }

        T.loc=adrs;
        IntermediateFile(imf,T);
        if(strlen(T.label)!=0)
        {
            table S;
            S.sym_name = (char*)malloc(sizeof(T.label));
            S.type = (char*)malloc(sizeof(char)*5);
            if(search(symtab,T.label,segname)!=1)
            {
                if(strcmp(T.opcode,"DW")==0)
                {
                    strcpy(S.type,"WORD");
                    S.length=2;
                }
                else if(strcmp(T.opcode,"DB")==0)
                {
                    strcpy(S.type,"BYTE");
                    S.length=1;
                }
                else if(strcmp(T.opcode,"SEGMENT")==0)
                {
                    S.type[0]='\0';
                    S.length=0;
                }
                else
                {
                    strcpy(S.type,"NEAR");
                    S.length=2;
                }
                if(strcmp(T.opcode,"SEGMENT")==0)
                    strcpy(segname,T.label);
                if(strcmp(T.opcode,"ENDS")==0)
                    strcpy(segname,"    ");
                S.seg_name = (char*)malloc(sizeof(segname));
                strcpy(S.sym_name,T.label);
                strcpy(S.seg_name,segname);
                S.loc = adrs;
                SymbolTable(symtab,S);
            }
        }
        if(strcmp(T.opcode,"DW")==0)
            adrs+=2;
        else if(strcmp(T.opcode,"DB")==0)
            adrs+=1;
        else if(strcmp(T.opcode,"HLT")==0)
            adrs+=1;
        else if(strcmp(T.opcode,"SEGMENT")==0 || strcmp(T.opcode,"ASSUME")==0 || strcmp(T.opcode,"ENDS")==0 || strcmp(T.opcode,"ORG")==0 )
        {
            adrs+=0;
        }
        else if(strstr(T.operand,",")!=NULL)
        {
            x=0;y=0;
            for(j=0;j<strlen(T.operand);j++)
            {
                if(T.operand[j]!=',')
                {
                    opr[x][y]=T.operand[j];
                    y++;
                }
                else
                {
                    opr[x][y]='\0';
                    y=0;
                    x++;
                }
            }
            opr[x][y]='\0';
            if(search(symtab,opr[0],"DATA")==1 || search(symtab,opr[1],"DATA")==1 )
                adrs+=4;
            else
                adrs+=2;
        }
        else if(strstr(T.label,":")!=NULL)
            adrs+=0;
        else
            adrs+=2;
    }
    fclose(fp1);
}

token seperate_token(char *line)
{
    token T;
    char a[40][40];
    int i,j=0,count=0,len;
    len = strlen(line);
    for(i=0;i<len;i++)
    {
        if(line[i]==' ' && line[i+1]!=' ' && line[i]!='\t')
        {
            a[count][j]='\0';
            count++;
            j=0;
        }
        else
        {
            a[count][j] = line[i];
            j++;
        }
    }
    a[count][j]='\0';
    count++;
    if(count==2)
    {
        a[2][0]='\0';
    }
    else if(count==1)
    {
        a[1][0]='\0';
        a[2][0]='\0';
    }
        if(strcmp(a[1],"DW")==0 || strcmp(a[1],"DB")==0)
        {
            T.label = (char*)malloc(sizeof(a[0]));
            T.opcode = (char*)malloc(sizeof(a[1]));
            T.operand = (char*)malloc(sizeof(a[2]));
            strcpy(T.label,a[0]);
            strcpy(T.opcode,a[1]);
            strcpy(T.operand,a[2]);

        }

        else if(strcmp(a[1],"SEGMENT")==0 || strcmp(a[1],"ENDS")==0)
        {
            T.label = (char*)malloc(sizeof(a[0]));
            T.opcode = (char*)malloc(sizeof(a[1]));
            T.operand = (char*)malloc(sizeof(char)*4);
            strcpy(T.label,a[0]);
            strcpy(T.opcode,a[1]);
            T.operand[0]='\0';

        }
        else if(strcmp(a[0],"ASSUME")==0)
        {

            T.label = (char*)malloc(sizeof(char)*4);
            T.opcode = (char*)malloc(sizeof(a[0]));
            T.operand = (char*)malloc(sizeof(a[1]));
            T.label[0]='\0';
            strcpy(T.opcode,a[0]);
            strcpy(T.operand,a[1]);
        }
        else if(strstr(a[0],":")!=NULL )
        {
            T.label = (char*)malloc(sizeof(a[0]));
            T.opcode = (char*)malloc(sizeof(a[1]));
            T.operand = (char*)malloc(sizeof(a[2]));
            strcpy(T.label,a[0]);
            strcpy(T.opcode,a[1]);
            strcpy(T.operand,a[2]);
        }
        else if( strcmp(a[0],"END")==0 || strcmp(a[0],"HLT")==0)
        {
            T.label = (char*)malloc(sizeof(char)*4);
            T.opcode = (char*)malloc(sizeof(a[0]));
            T.operand = (char*)malloc(sizeof(char)*4);
            T.label[0]='\0';
            strcpy(T.opcode,a[0]);
            T.operand[0]='\0';
        }
        else
        {
            T.label = (char*)malloc(sizeof(char)*4);
            T.opcode = (char*)malloc(sizeof(a[0]));
            T.operand = (char*)malloc(sizeof(a[1]));
            T.label[0]='\0';
            strcpy(T.opcode,a[0]);
            strcpy(T.operand,a[1]);
        }

    return T;
}

void IntermediateFile(char *imf,token T)
{
    FILE*fp2;
    fp2 = fopen(imf,"a");

    fwrite(&T,sizeof(T),1,fp2);
    fclose(fp2);

}

void SymbolTable(char*sym,table S)
{
    FILE *fp3;
    fp3 = fopen(sym,"ab");
    fwrite(&S,sizeof(S),1,fp3);
    fclose(fp3);
    first++;
}

void DisplayIntermediatefile(char*imf)
{
    FILE*fp;
    token T;
    fp = fopen(imf,"rb");
    while(!feof(fp))
    {
        fread(&T,sizeof(token),1,fp);
        if(feof(fp))
            break;
        printf("\n\n%7s %7s %7s %x",T.label,T.opcode,T.operand,T.loc);
    }
    fclose(fp);
}

void DisplaySymbolTable(char *sym)
{
    FILE*fp;
    table T;
    fp = fopen(sym,"rb");
    while(!feof(fp))
    {
        fread(&T,sizeof(table),1,fp);
        if(feof(fp))
            break;
        printf("\n\n%7s %7s %7s %5x %5d",T.sym_name,T.seg_name,T.type,T.loc,T.length);
    }
    fclose(fp);
}

int search(char*tab,char*symname,char*segname)
{
    if(first==0)
        return -1;
    FILE*fp;
    table T;
    int flag = 0;
    fp = fopen(tab,"rb");
    while(!feof(fp))
    {
        fread(&T,sizeof(table),1,fp);
        if(strcmp(T.sym_name,symname)==0 && strcmp(T.seg_name,segname)==0)
        {
            flag = 1;
        }
    }
    fclose(fp);
    return flag;
}
