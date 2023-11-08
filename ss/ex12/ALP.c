#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k=0;
int assignment(char a[50],int cou)
{
    int j=0,kk=0,i,n;
    char strr[50][50];
    n=strlen(a);
    for(i=0; i<n; i++)
    {
        if(a[i]!='=')
        {
            strr[j][kk]=a[i];
            kk++;
        }
        else
        {
            j++;
            kk=0;
        }
    }
    cou++;
    printf("\n%d\tMOV R%d,%s",cou,k,strr[1]);
    cou++;
    printf("\n%d\tMOV %s,R%d",cou,strr[0],k);
    k++;
    if(k>9)
    {
        k=0;
    }
    for(i=0; i<50; i++)
        strcpy(strr[i],"1");
    return cou;
}
int ari(char str[50],int cou)
{
    int i,n,k1=0,kk=0,cc,j=0,jj,ii,k3,nn;
    char strr[50][50],str2[50],str1[]="R",str3[50];
    for(i=0; i<50; i++)
        strcpy(strr[i],"1");
    n=strlen(str);
    printf("\t%s\t",str);
    for(i=0; i<n; i++)
    {
        if(str[i]!='=' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            strr[j][kk]=str[i];
            kk++;
        }
        else
        {
            str2[k1]=str[i];
            k1++;
            kk=0;
            j++;
        }
    }
    j++;
    cou++;
    //for(ii=0;ii<j;ii++)
    //	printf("\t%s",strr[ii]);
    printf("\n%d\tMOV R%d,%s",cou,k,strr[1]);
    cou++;
    n=1;
    str1[n]=k+48;
    str1[2]='\0';
    strcpy(strr[1],str1);
    k++;
    printf("\n%d\tMOV R%d,%s",cou,k,strr[2]);
    cou++;
    n=1;
    str1[n]=k+48;
    str1[2]='\0';
    //printf("\n%s\n",str1);
    strcpy(strr[2],str1);
    if(str2[1]=='+')
    {
        printf("\n%d\tADD %s,%s",cou,strr[1],strr[2]);
    }
    if(str2[1]=='-')
    {
        printf("\n%d\tSUB %s,%s",cou,strr[1],strr[2]);
    }
    if(str2[1]=='*')
    {
        printf("\n%d\tMUL %s,%s",cou,strr[1],strr[2]);
    }
    if(str2[1]=='/')
    {
        printf("\n%d\tDIV %s,%s",cou,strr[1],strr[2]);
    }
    cou++;
    printf("\n%d\tMOV %s,%s",cou,strr[0],strr[1]);
    if(k>9)
    {
        k=0;
    }
//	k++;
    return cou;
}
int arithmetic(int cou)
{
    FILE *fp1;
    int c=0,i,cc,n,k1=0;
    cc=cou+3;
    //printf("%d",cc);
    char str[50];
    fp1=fopen("input.c","r");
    while(!strcmp(str,"if")==0)
        fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    //printf("%s",str);
    fscanf(fp1,"%s",str);
    fscanf(fp1,"%s",str);
    while(!strcmp(str,"goto")==0)
    {
        //printf("\n%s\n",str);
        n=strlen(str);
        c=0;
        for(i=0; i<n; i++)
        {
            if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            {
                c=1;
                break;
            }
        }
        if(c==0)
        {
            cc=cc+2;
            //	printf("%d",cc);
        }
        else
        {
            cc=cc+4;
            //	printf("%d",cc);
        }
        fscanf(fp1,"%s",str);
        fscanf(fp1,"%s",str);
    }
    //printf("%d",cc);
    return cc;
}
int relation(int cou)
{
    FILE *fp2;
    int k2,c;
    int i,n,k1=0,kk=0,cc,j=0,jj,ii,k3,nn;
    char str[50];
    char strr[50][50],str2[50],str1[]="R",str3[50];
    for(i=0; i<50; i++)
        strcpy(strr[i],"1");
    fp2=fopen("input.c","r");
    while(!strcmp(str,"if")==0)
        fscanf(fp2,"%s",str);
    fscanf(fp2,"%s",str);
    n=strlen(str);
    //printf("\t%s\t",str);
    for(i=0; i<n; i++)
    {
        if(str[i]!='<' && str[i]!='>' && str[i]!='!' && str[i]!=')' && str[i]!='(' && str[i]!='=')
        {
            strr[j][kk]=str[i];
            kk++;
        }
        else
        {
            if(str[i]!=')' && str[i]!='(')
            {
                str2[k1]=str[i];
                k1++;
                kk=0;
                j++;
            }
        }
    }
    strr[j][kk]='\0';
    j++;
    for(ii=0; ii<j; ii++)
        printf("\t%s",strr[ii]);
    cou++;
    printf("\n%d\tMOV R%d,%s",cou,k,strr[0]);
    cou++;
    n=1;
    str1[n]=k+48;
    str1[2]='\0';
    strcpy(strr[0],str1);
    k++;
    printf("\n%d\tMOV R%d,%s",cou,k,strr[2]);
    cou++;
    n=1;
    str1[n]=k+48;
    str1[2]='\0';
    //printf("\n%s\n",str1);
    strcpy(strr[1],str1);
    printf("\n%d\tCOMPR %s,%s",cou,strr[0],strr[1]);
    cou++;
    if(str2[0]=='<')
    {
        printf("\n%d\tJLT %d",cou,cou+2);
    }
    if(str2[0]=='>')
    {
        printf("\n%d\tJGT %d",cou,cou+2);
    }
    if(str2[0]=='!')
    {
        printf("\n%d\tJNZ %d",cou,cou+2);
    }
    if(str2[0]=='=')
    {
        printf("\n%d\tJZ %d",cou,cou+2);
    }
    //cou++;
    return cou;
}
int main()
{
    char strr[50][50],str[50],d,str2[50],str1[]="temp",str3[50];
    int cou=0,c=0,i,j,n,kk=0,ii,jj,k1=0,k3=0,nn,count=0;
    FILE *fp;
    fp=fopen("input.c","r");
    i=0;
    fscanf(fp,"%s",str);
    fscanf(fp,"%s",str);
    n=strlen(str);
    while(!strcmp(str,"exit")==0)
    {
        c=0;
        n=strlen(str);
        for(i=0; i<n; i++)
            if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && strcmp(str,"if")!=0 && strcmp(str,"goto")!=0)
                c=c+1;
        if(c==n)
        {
            c=0;
            cou=assignment(str,cou);
        }
        else
        {
            k1=0;
            j=0;
            if(!strcmp(str,"if")==0 && !strcmp(str,"goto")==0)
            {
                cou=ari(str,cou);
            }
            else if(!strcmp(str,"goto")==0)
            {
                count=cou+1;
                cou=relation(cou);
                fscanf(fp,"%s",str);
                fscanf(fp,"%s",str);
                fscanf(fp,"%s",str);
                //printf("\n%d\n",cou);
                kk=1;
            }
            else
            {
                if(kk==1)
                {
                    k1=arithmetic(cou);
                    cou++;
                    printf("\n%d\tJSUB %d",cou,k1);
                    //cou++;
                    fscanf(fp,"%s",str);
                    kk=0;
                }
                else
                {
                    cou++;
                    printf("\n%d\tJSUB %d",cou,count);
                    fscanf(fp,"%s",str);
                }
            }
        }
        fscanf(fp,"%s",str);
        fscanf(fp,"%s",str);
        //printf("\n%s\n",str);
        for(i=0; i<50; i++)
            strcpy(strr[i],"1");
    }
    if(strcmp(str,"exit")==0)
    {
        cou++;
        printf("\n%d\tEND",cou);
    }
}
