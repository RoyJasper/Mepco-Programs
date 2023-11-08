#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int convert(char );
int convert(char a)
{
    int i,g;
    if(a=='E')
    {
        g=0;
    }
    if(a=='W')
    {
        g=1;
    }
    if(a=='T')
    {
        g=2;
    }
    if(a=='Q')
    {
        g=3;
    }
    if(a=='F')
    {
        g=4;
    }
    if(a=='+')
    {
        g=5;
    }
    if(a=='*')
    {
        g=6;
    }
    if(a=='(')
    {
        g=7;
    }
    if(a==')')
    {
        g=8;
    }
    if(a=='d')
    {
        g=9;
    }
    if(a=='^')
    {
        g=10;
    }
    if(a=='$')
    {
        g=11;
    }
    return g;
}
main()
{
    int g[50][50],n,i,j,m,b[50][50],e[8][7][50],c[50],d[50],f[50][50],k,l;
    char a[50][50];
    printf("ENTER THE NO OF STRINGS");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the string");
        scanf("%s",a[i]);
        for(j=0; j<strlen(a[i]); j++)
            g[i][j]=convert(a[i][j]);
    }
    printf("ENTER THE FIRST");
    for(i=0; i<n; i++)
    {
        printf("ENTER THE %s NUMBER",a[i]);
        scanf("%d",&c[i]);
        for(j=0; j<c[i]; j++)
        {
            printf("5.+ 6.* 7.( 8.) 9.id 10.^ 11.$ ENTER THE CHOICE");
            scanf("%d",&b[i][j]);
        }
    }
    printf("ENTER THE FOLLOW");
    for(i=0; i<n; i++)
    {
        printf("ENTER THE %s NUMBER",a[i]);
        scanf("%d",&d[i]);
        for(j=0; j<d[i]; j++)
        {
            printf("5.+ 6.* 7.( 8.) 9.id 10.^ 11.$ ENTER THE CHOICE");
            scanf("%d",&f[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<c[i]; j++)
        {
            if(b[i][j]!=10)
            {
                for(k=0; k<strlen(a[i]); k++)
                {
                    e[i][b[i][j]-5][k]=g[i][k];
                    printf("%d\n",e[i][b[i][j]-5][k]);
                }

            }
            else
            {
                for(l=0; l<d[i]; l++)
                {
                    for(k=0; k<strlen(a[i]); k++)
                    {
                        e[i][f[i][l]-5][k]=g[i][k];
                    }
                }
            }
        }
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<7; j++)
        {
            for(k=0; k<2; k++)
            {
                printf("%d",e[i][j][k]);
            }
            printf("\t");
        }
        printf("\n");
    }
}
