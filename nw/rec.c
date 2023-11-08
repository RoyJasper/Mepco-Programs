#include<stdlib.h>
#include<string.h>
#include<stdio.h>
main()
{
    FILE *fp;
    char a[100],d;
    int b,n,i,numberArray[100];
    fp=fopen("sender.txt","r");
    fscanf(fp, "%d", &numberArray[0]);
    d=fgetc(fp);
    while(d!=EOF)
    {
        a[1]=(char)numberArray[0];
        printf("%c",a[1]);
        fscanf(fp, "%d", &numberArray[0]);
        d=fgetc(fp);
    }
    fclose(fp);
}

