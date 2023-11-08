#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char yy[10][100];
void binary(char x)
{
    if((int)x==48)
    {
        printf("0000 ");
    }
    else if((int)x==49)
    {
        printf("0001 ");
    }
    else
    {
        int c[10],e[10];
        int r,l,a,i=0,count=0;
        a=(int)x;
        if(a>57)
            a=a-55;
        else
            a=a-48;
        if(a<4)
            printf("00");
        else if(a>=4 && a<8)
            printf("0");
        while(a!=0)
        {
            c[i] = a%2;
            a = a / 2;
            count++;
            i++;
        }
        for(i=count-1; i>=0; i--)
        {
            printf("%d", c[i]);
        }
        printf(" ");

    }

}
char *dectohexa(int quotient)
{
    int temp,i=1,j;
    char h[100];
    while(quotient!=0)
    {
        temp = quotient % 16;
        if( temp < 10)
            temp =temp + 48;
        else
            temp = temp + 55;
        h[i++]= temp;
        quotient = quotient / 16;
    }
    int k=0;
    char *he = (char*)malloc(sizeof(char)*100);
    for (j = i -1 ; j> 0; j--)
        he[k++]=h[j];
    he[k]='\0';
    return he;
}
int check(char x)
{
    if(x=='\n' || x=='^')
        return 0;
    else
        return 1;

}
int count(char x)
{
    if((int)x==48)
    {
        return 0;
    }
    else if((int)x==49)
    {
        return 1;
    }
    else
    {
        int c[10],e[10];
        int r,l,a,i=0,co=0,p=0;
        a=(int)x;
        if(a>57)
            a=a-55;
        else
            a=a-48;
        while(a!=0)
        {
            c[i] = a%2;
            a = a / 2;
            co++;
            i++;
        }
        for(i=co-1; i>=0; i--)
        {
            if(c[i]==1)
                p++;
        }
        return p;
    }

}
main()
{
    FILE *fp;
    fp=fopen("program.c","r");
    char x,y[100],z[100],s[100],loc[100],n[100],l[100],start[100],name[100],length[100];
    int g,h,f;
    printf("Enter Relocation address : ");
    scanf("%s",length);
    sscanf(length,"%X",&f);
    x=fgetc(fp);
    int k=0,i=0,j;
    printf("\n Relocation Loader with Modification Record : \n  ");
    x=fgetc(fp);
    while(x!=EOF)
    {
        if(x=='H')
        {
            x=fgetc(fp);
            while(x!='\n')
            {
                x=fgetc(fp);
            }

        }
        else if(x=='T')
        {
            int cou=0;
            i=0;
            x=getc(fp);
            x=getc(fp);
            while(x!='^')
            {
                y[i]=x;
                i++;
                x=getc(fp);

            }
            y[i]='\0';
            sscanf(y,"%X",&h);
            g=f+h;
            strcpy(loc,dectohexa(g));
            x=getc(fp);
            x=getc(fp);
            x=getc(fp);
            x=getc(fp);
            cou=count(x);
            x=getc(fp);
            cou=cou+count(x);
            x=getc(fp);
            cou=cou+count(x);
            printf("\n");
            x=getc(fp);
            x=getc(fp);
kia:
            while(x!='\n')
            {
                printf("   %s   ",loc);
                binary(x);
                x=fgetc(fp);
                binary(x);
                printf("\n");
                int zz;
                sscanf(loc,"%X",&zz);
                zz=zz+1;
                strcpy(loc,dectohexa(zz));
                i=0;
                x=fgetc(fp);
                while(check(x)!=0)
                {
                    z[i]=x;
                    x=fgetc(fp);
                    i++;
                }
                z[i]='\0';
                int pp=strlen(z);
                if(cou!=0)
                {
                    int ee,g;
                    sscanf(z,"%X",&ee);
                    g=ee+f;
                    strcpy(z,dectohexa(g));
                    cou--;
                }
                for(i=0; i<pp; i++)
                {
                    printf("   %s   ",loc);
                    binary(z[i]);
                    i=i+1;
                    binary(z[i]);
                    printf("\n");
                    int zz;
                    sscanf(loc,"%X",&zz);
                    zz=zz+1;
                    strcpy(loc,dectohexa(zz));

                }
                if(x=='\n')
                    goto kia;
                x=fgetc(fp);
            }
        }
        else if(x=='E')
        {
            exit(0);
        }
        x=getc(fp);
    }
}

