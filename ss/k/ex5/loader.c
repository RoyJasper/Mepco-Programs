#include<stdio.h>
#include<string.h>
main()
{

    FILE *fp;
    fp=fopen("pass.c","r");
    char x,s[100],loc[100],n[100],l[100],start[100],name[100],length[100];
    x=fgetc(fp);
    while(x!=EOF)
    {
        if(x=='H')
        {
            x=getc(fp);
            x=getc(fp);
            i=0;
            while(x!='^')
            {
                n[i]=x;
                x=getc(fp);
                i++;
            }
            x=getc(fp);
             i=0;
            while(x!='^')
            {
                s[i]=x;
                x=getc(fp);
                i++;
            }
            x=getc(fp);
               i=0;
            while(x!='^')
            {
                l[i]=x;
                x=getc(fp);
                i++;
            }
            printf("\n enter the program name  :");
            scanf("%s",name);
             if(strcmp(n,name)!=0)
            {
                printf("\n program name is incorrect\n");
                exit(0);
            }
            printf("\n enter the starting address   :");
            scanf("%s",start);
            if(strcmp(s,start)!=0)
            {
                printf("\n program starting address is incorrect\n");
                exit(0);
            }
            printf("\n enter the lenght of the program  : ");
            scanf("%s",length);
            if(strcmp(l,length)!=0)
            {
                printf("\n program length is incorrect\n");
                exit(0);
            }

        }
    }
}
