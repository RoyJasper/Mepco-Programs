#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp;
    char a[100],b[]={'s','t','r'},c[]={'e','t','x'};
    int n,i;
    fp=fopen("sender1.txt","w");
    printf("ENTER THE STRING");
    gets(a);
    n=strlen(a);
    for(i=0;i<3;i++)
    {
        putc(b[i],fp);
    }
    for(i=0;i<n;i++)
    {
        putc(a[i],fp);
    }
    for(i=0;i<3;i++)
    {
        putc(c[i],fp);
    }
    fclose(fp);
}

