#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp;
    char b[100],d;
    int i,n,flag=0;
    fp=fopen("bit.txt","r");
    d=fgetc(fp);
    i=0;
    while(d!=EOF)
    {
        b[i]=d;
        i++;
        d=getc(fp);
    }
    n=i;
    if(b[0]=='0' && b[1]=='0' && b[n-2]=='1' && b[n-1]=='1')
    {
        flag=1;
    }
    if(flag!=1)
    {
        printf("\nStart and End error occured");
    }
    else
    {
        for(i=2; i<n-2; i++)
        {
            if(b[i]=='0' && b[i+1]=='1')
                printf("0");
            else if(b[i]=='1' && b[i+1]=='0')
                printf("1");
            else if((b[i]=='1' && b[i+1]=='1') || (b[i]=='0' && b[i+1]=='0'))
            {
                printf("\nError occured  message is invalid");
                exit(0);
            }
            i++;
        }
    }
}
