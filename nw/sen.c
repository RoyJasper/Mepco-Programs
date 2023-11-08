#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp;
    char a[100],d;
    int b,n,i;
    fp=fopen("sender.txt","w");
    printf("ENTER THE STRING");
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        b=(int)a[i];
        fprintf(fp,"%d",b);
        putc(" ",fp);
    }
    printf("ENCRYPTED");
    fclose(fp);
}
