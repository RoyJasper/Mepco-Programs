#include<stdlib.h>
#include<string.h>
#include<stdio.h>
main()
{
    FILE *fp;
    char a[100],g;
    int c=0,n,i=0,d=0;
    fp=fopen("sender1.txt","r");
    g=fgetc(fp);
    while(g!=EOF)
    {
        a[i]=g;
        g=fgetc(fp);
        i++;
    }
    n=i;
    if(a[0]=='s')
    {
        if(a[1]=='t')
        {
            if(a[2]=='r')
            {
                c=1;
            }
        }
    }
    if(c!=1)
    {
        printf("STR ERROR");
    }
    else
    {
        if(a[n-3]=='e')
        {
            if(a[n-2]=='t')
            {
                if(a[n-1]=='x')
                {
                    d=1;
                }
            }
        }
        if(d!=1)
        {
            printf("ETX ERROR");
        }
        else
        {
            for(i=3;i<n-3;i++)
            {
                putchar(a[i]);
            }
        }
    }
    fclose(fp);
}


