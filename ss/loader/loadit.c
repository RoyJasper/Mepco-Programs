#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char hex(int);
int cou=0;
int u3=0;
int new=0;
int s1;
int flag=1;
int flag1=0;
int count1=0;
void main()
{
    FILE *fp;
    int count=0,p=1;
    char r;
    char c,x1[100][100],x[100];
    char b[100][100];
    int all[100];
    int n,i=0,j=0,k,loc,m=0,fhd,nhd,length[100];
    int u2=0,s=0,u4=4,u,u3=0;
    all[0]=0;
    fp=fopen("obj.bin","rb");
    while((c=fgetc(fp))!='/' && !feof(fp))
    {
        if(c=='T')
        {
            j=0;
            c=fgetc(fp);
            if(c=='^')
            {
                count++;
                c=fgetc(fp);
            }
            while(c!='E')
            {
                if(c=='T')
                {
                    all[p]=count;
                    p++;
                    c=fgetc(fp);
                }
                if(c=='^')
                {
                    c=fgetc(fp);
                    i++;
                    count++;
                    j=0;
                }
                b[i][j]=c;
                j++;
                c=fgetc(fp);
            }
            b[i][j]='\0';
        }
        else if(c=='H' || c=='E' || c=='\0')
        {
            while((c=fgetc(fp))!='\n')
            {}
        }
        else
            continue;
    }
    printf("\n\tAbsolute Loader\n");
    int yy=(count-2)*3/2;
    int y,allnew[100],ss[100],r1=0,mm,ss1=0;
    for(i=0; i<p; i++)
    {
        mm=all[i];
        for(j=3; j>=0; j--)
        {
            r= (b[mm][r1]);
            r=r-48;
            s=s+(r*pow(16,j));
            r1++;
        }
        r1=0;
        ss[ss1]=s;
        ss1++;
        s=0;
    }

    for( y=0; y<p; y++)
        allnew[y]=((all[y+1]-all[y])-2);

    allnew[p-1]=(count-all[p-1])-2;
    int times,all1=1,all2=0,t1=0,exe,enter=0;
    for(i=2; i<=count-1; i++)
    {
        if(allnew[all2]>0)
        {
            for(j=0; j<6; j++)
            {
                binary(b[i][j],ss[all2]);

            }
        }
        else
        {
            i++;
            all2++;
            allnew[all2]+=1;
            flag1++;
            enter++;
            if(enter>=2)
                flag1-=2;

        }
        allnew[all2]-=1;
    }


}
void binary(char cat,int s)
{

    int m,n,i2=0,i1=3,u=0,q,r;
    int d[100],d1[100],b[100][100];
    int count=0,i,j;
    if((cat=='A')||(cat=='B')||(cat=='C')||(cat=='D')||(cat=='E')||(cat=='F'))
    {
        if(cat=='A')
            cat=10;
        if(cat=='B')
            cat=11;
        if(cat=='C')
            cat=12;
        if(cat=='D')
            cat=13;
        if(cat=='E')
            cat=14;
        if(cat=='F')
            cat=15;
    }
    for(i=0; i<100; i++)
        for(j=0; j<4; j++)
            b[i][j]=0;
    while(cat!=0)
    {
        q=cat/2;
        r=cat%2;
        cat=q;
        d[u]=r;
        u++;
        count++;
    }
    for(i=0; i<count; i++)
    {
        b[i2][i1]=d[i];
        i1--;
    }
    m=0;
    count1++;
    if(flag==1)
    {
        s1=s;
        flag++;
    }
    if(flag1==1)
    {
        s1=s;
        flag1++;
    }
    if(count1<2)
        hex(s1);
    else
    {
        count1=0;
        s1=s1+1;
        s=s1;
    }
    for(n=0; n<4; n++)
    {
        printf("%d",b[m][n]);
        u3++;
        cou++;
    }
    printf("\t");
    if((cou/4)==2)
    {
        printf("\n");
        cou=0;
    }
}
char hex(int z)
{
    char c,hex[4],hex1[4];
    int i=0,rem,count=0,k1=0,k;
    while(z!=0)
    {
        rem=z%16;
        switch(rem)
        {
        case 10:
            hex[i]='A';
            break;
        case 11:
            hex[i]='B';
            break;
        case 12:
            hex[i]='C';
            break;
        case 13:
            hex[i]='D';
            break;
        case 14:
            hex[i]='E';
            break;
        case 15:
            hex[i]='F';
            break;
        default:
            hex[i]=rem+'0';
            break;
        }
        ++i;
        count++;
        z/=16;
    }
    for(k=count-1; k>=0; k--)
    {
        hex1[k1]=hex[k];
        k1++;
    }
    for(i=0; i<4; i++)
        printf("%c",hex1[i]);
    printf("\t");

}


