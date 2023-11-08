#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checknonterminal(char );
int checkterminal(char );
main()
{
    int a,ts,r,si,b,f,ips,m,j,k,i,ip,ss,is,st,c,check;
    char h,t[100],nt[100],y[10],stack[100],input[100],table[100][100][100];
    printf("enter the no of terminals\n");
    scanf("%d",&c);
    printf("enter the no of non terminals\n");
    scanf("%d",&r);
    printf("\n enter the choise \n  1: default   2: new values\n\n ");
    scanf("%d",&f);
    if(f==1)
    {
        strcpy(t,"+*()i#$");
        strcpy(nt,"egtsf");
        strcpy(table[0][2],"tg");
        strcpy(table[0][4],"tg");
        strcpy(table[1][0],"+tg");
        strcpy(table[1][3],"#");
        strcpy(table[1][6],"#");
        strcpy(table[2][2],"fs");
        strcpy(table[2][4],"fs");
        strcpy(table[3][0],"#");
        strcpy(table[3][1],"*fs");
        strcpy(table[3][3],"#");
        strcpy(table[3][6],"#");
        strcpy(table[4][2],"(e)");
        strcpy(table[4][4],"i");
        strcpy(input,"i+i*i$");
        strcpy(stack,"$e");
    }
    else
    {

        printf("enter the terminals\n");
        scanf("%s",t);
        printf("enter the non terminals\n");
        scanf("%s",nt);
        printf("enter the table values\n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                printf("i=%d j==%d  \n",i,j);
                scanf("%s",table[i][j]);
            }
        }
        printf("enter the input");
        scanf("%s",input);
        printf("enter the stack");
        scanf("%s",stack);
    }

    int checknonterminal(char x)
    {
        int i;
        for(i=0; i<r; i++)
        {
            if(nt[i]==x)
                return i;
        }
    }
    int checkterminal(char x)
    {
        int i;
        for(i=0; i<c; i++)
        {
            if(t[i]==x)
                return i;
        }
    }
    void display()
    {
        for(i=0; i<=ts; i++)
            printf("%c",stack[i]);
        printf("\t\t\t");
        for(i=si; i<=is; i++)
            printf("%c",input[i]);

        printf("\t\t  %c  ->%s\n",h,y);

    }
    is=strlen(input);
    ss=strlen(stack);
    ts=ss-1;
    si=0;
    printf("\n\n\n**********************************************\n  STACK                  INPUT          ACTION\n**********************************************\n\n");
    printf("\n%s\t\t\t%s\n",stack,input);
    while((stack[ts+1]!='$') && (input[si-1]!='$'))
    {

        if(stack[ts]==input[si])
        {

            ts=ts-1;
            si=si+1;

            for(i=0; i<=ts; i++)
                printf("%c",stack[i]);
            printf("\t\t\t");
            for(i=si; i<is; i++)
                printf("%c",input[i]);
            printf("\n");
        }
        else
        {

            a=checkterminal(input[si]);
            b=checknonterminal(stack[ts]);
            h=stack[ts];
            strcpy(y,table[b][a]);
            m=strlen(y);
            int g=strcmp(y,"#");
            if(g==0)
            {
                ts--;
                display();


            }
            else
            {
                for(i=m-1; i>=0; i--)
                {

                    stack[ts]=y[i];
                    ts++;

                }
                ts--;
                display();

            }
        }
    }

}
