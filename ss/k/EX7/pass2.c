#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int newrec(FILE *fp,int *lim,int l,int pos,int c,char add[])
{
    if(l>=30)
    {
        *lim=30;
    }
    else
    {
        *lim=l;
    }
    fseek(fp,pos,SEEK_SET);
    fprintf(fp,"%02X",c);
    fseek(fp,0,SEEK_END);
    fprintf(fp,"\nT^00%s^",add);
    pos=ftell(fp);
    fprintf(fp,"--");
    c=0;
    return pos;
}
int convhex(char str[])
{
    int hex=0,l,d,i=0;
    l=strlen(str)-1;
    while(str[i]!='\0')
    {
        switch(str[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            d=str[i]-48;
            break;
        case 'A':
        case'B':
        case'C':
        case'D':
        case'E':
        case'F':
            d=str[i]-55;
            break;
        }
        hex=hex+(d*pow(16,l));
        l--;
        i++;
    }
    return hex;
}
int check(char op[])
{
    int i;
    for(i=0; op[i]!='\0'; i++)
    {
        if(op[i]==',')
        {
            op[i]='\0';
            return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *fint,*ftab,*flen,*fsym,*fobj,*fp1,*fobj1;
    int i,len,l,pos,flag,lim=30,c=0,chk,f=0,sym,prevaddr,prev;
    char add[5],symadd[5],op[5],start[10],address[200];
    char label[20],mne[10],operand[10],symtab[10],opmne[10],ans[200];
    fint=fopen("inter.txt","r");
    ftab=fopen("optab.txt","r");
    fsym=fopen("symtab.txt","r");
    fobj=fopen("objcode.txt","w");
    fobj1=fopen("objcode.txt","r");
    fp1=fopen("inter.txt","r");
    fscanf(fp1,"%s%s%s%s",address,label,mne,operand);
    prev=convhex(operand);
    while(fscanf(fp1,"%s%s%s%s",address,label,mne,operand)>0);
    prevaddr=convhex(address);
    prev=prevaddr-prev;
    int quotient=0,n,m;
    quotient=prev;
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
    fscanf(fint,"%s%s%s%s",add,label,mne,operand);
    if(strcmp(mne,"START")==0)
    {
        strcpy(start,operand);
    }
    fprintf(fobj,"H^%s^00%s^00%s\n",label,start,he);
    l=he;
    fscanf(fint,"%s%s%s%s",add,label,mne,operand);
    fprintf(fobj,"T^00%s^",add);
    pos=ftell(fobj);
    fprintf(fobj,"--");
    while(strcmp(mne,"END")!=0)
    {
        fscanf(ftab,"%s%s",opmne,op);
        while(!feof(ftab))
        {
            if(strcmp(mne,opmne)==0)
            {
                f=0;
                fclose(ftab);
                fscanf(fsym,"%s%s",symadd,symtab);
                chk=check(operand);
                while(!feof(fsym))
                {
                    if(strcmp(operand,symtab)==0)
                    {
                        f=1;
                        sym=convhex(symadd);
                        if(lim<3)
                        {
                            pos=newrec(fobj,&lim,l,pos,c,add);
                            c=0;
                        }
                        lim-=3;
                        l-=3;
                        fprintf(fobj,"^%s%04X",op,(sym|(chk*32768)));
                        c=c+3;
                        break;
                    }
                    else
                        fscanf(fsym,"%s%s",symadd,symtab);
                }
                if(f==0)
                {
                    if(lim<3)
                    {
                        pos=newrec(fobj,&lim,l,pos,c,add);
                        c=0;
                    }
                    lim-=3;
                    l-=3;
                    c+=3;
                    fprintf(fobj,"^%s0000",op);
                }
                break;
            }
            else
                fscanf(ftab,"%s%s",opmne,op);
        }
        if((strcmp(mne,"BYTE")==0)||(strcmp(mne,"WORD")==0))
        {
            if(strcmp(mne,"WORD")==0)
            {
                int b;
                b=atoi(operand);
                if(lim<3)
                {
                    pos=newrec(fobj,&lim,l,pos,c,add);
                    c=0;
                }
                lim-=3;
                l-=3;
                c+=3;
                fprintf(fobj,"^%06X",b);
            }
            else
            {
                int j=0,k=0;
                char str[4];
                len=strlen(operand);
                if((operand[j]=='X'))
                {
                    j=2;
                    while(j<len-1)
                    {
                        str[k++]=operand[j];
                        j++;
                    }
                    str[k]='\0';
                    if(lim<1)
                    {
                        pos=newrec(fobj,&lim,l,pos,c,add);
                        c=0;
                    }
                    lim-=1;
                    l-=1;
                    c+=1;
                    fprintf(fobj,"^%s",str);
                }
                else
                {
                    if(lim<3)
                    {
                        pos=newrec(fobj,&lim,l,pos,c,add);
                        c=0;
                    }
                    lim-=3;
                    l-=3;
                    c+=3;
                    fprintf(fobj,"^");
                    for(i=2; i<len-1; i++)
                    {
                        fprintf(fobj,"%X",operand[i]);
                    }
                }
            }
            fscanf(fint,"%s%s%s%s",add,label,mne,operand);
        }
        else if(strcmp(mne,"RESW")==0||strcmp(mne,"RESB")==0)
        {
            while(strcmp(mne,"RESW")==0||strcmp(mne,"RESB")==0)
            {
                if(strcmp(mne,"RESW")==0)
                {
                    l=l-(3*atoi(operand));
                }
                else
                    l=l-(atoi(operand));
                fscanf(fint,"%s%s%s%s",add,label,mne,operand);
            }
            flag=0;
            if(strcmp(mne,"END")==0)
            {
                flag=1;
            }
            if(flag==0)
            {
                pos=newrec(fobj,&lim,l,pos,c,add);
                c=0;
            }
        }
        else
        {
            fscanf(fint,"%s%s%s%s",add,label,mne,operand);
        }
        ftab=fopen("optab.txt","r");
        fseek(ftab,SEEK_SET,0);
        fseek(fsym,SEEK_SET,0);
    }
    fseek(fobj,pos,SEEK_SET);
    fprintf(fobj,"%02X",c);
    fseek(fobj,0,SEEK_END);
    fprintf(fobj,"\nE^00%s",start);
    fclose(fobj);
    printf("\n Pass 2 of 2 pass assembler  \n Object Code  \n\n");
    while(fscanf(fobj1,"%s",ans)>0)
        printf("%s\n",ans);

    return 0;
}
