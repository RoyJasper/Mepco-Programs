#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp;
    char res[100],c[100],a[]= {'0','0'},b[]= {'1','1'};
    int k=0,n,i;
    printf("\nEnter the message");
    scanf("%s",c);
    fp=fopen("bit.txt","w");
    for(i=0; i<2; i++)
    {
        putc(a[i],fp);
    }
    n=strlen(c);
    for(i=0; i<n; i++)
    {
        if(c[i]=='0')
        {
            res[k]='0';
            res[k+1]='1';
        }
        else
        {
            res[k]='1';
            res[k+1]='0';
        }
        k=k+2;
    }
    n=strlen(res);
//    printf("\n%s",res);
    for(i=0; i<n; i++)
    {
        putc(res[i],fp);
    }
    for(i=0; i<2; i++)
    {
        putc(b[i],fp);
    }
}
