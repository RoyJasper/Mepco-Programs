#include<stdio.h>
#include<string.h>
main()
{
    FILE *fp;
    int u,j,count,k,d;
    int m[100],array[100],f[100];
    int i=0,c,g;
    char x;
    fp=fopen("eg.txt","r");
    x=fgetc(fp);

    printf("\n ***** the intermediate message  ******* \n\n\n");
    while((x!='#'))
    {

        if((int)x==48)
            m[i]=0;
        else if((int)x==49)
            m[i]=1;
        else
            m[i]=2;
        x=fgetc(fp);
        printf("%d ",m[i]);
        i++;
    }
    for(j=0; j<i; j++)
        f[j]=m[j];
    c=i;
    //x=fgetc(fp);
    x=fgetc(fp);
    while(x!='#')
    {
        if((int)x==48)
            m[i]=0;
        else
            m[i]=1;
        x=fgetc(fp);
        printf("%d ",m[i]);
        i++;
    }
    count=i;
    u=count-c;
    for(i=0; i<8; i++)
        array[i]=0;
    for(i=0; i<count; i++)
    {
        k=i%8;
        if(m[i]==1)
            array[k]=array[k]+1;
    }

    for(i=0; i<8; i++)
        g=0;
    for(i=0; i<8; i++)
    {

        if(array[i]%2==0)
            g=g+1;
    }
    // printf("\n\n\n **** transmited message  ****\n\n\n");
    /* if(g==8)
     {

         for(i=0;i<c;i++)
     {
        //if(m[i]==1 || m[i]==0)
       //printf("%d",m[i]);
     }
     }
     else
         printf("\n error in transmission");*/
    i=c;
    x=getc(fp);
    while(x!=EOF)
    {
        if((int)x==48)
            f[i]=0;
        else
            f[i]=1;
        x=fgetc(fp);
        printf("%d ",f[i]);
        i++;
    }

    int r[100],h,o;
    h=0;
    d=c;
    k=1;
    for(i=0; i<c; i++)
    {
        if((i/8)==k)
            k++;
        if(f[i]==1)
            array[k]=array[k]+1;
    }
    for(i=1; i<=k; i++)
    {
        //printf("array%d ",array[i]);
    }
    for(i=1; i<=k; i++)
    {
        if((array[i]%2)==0)
            r[h]=0;
        else
            r[h]=1;
        h++;
    }
    for(i=0; i<k; i++)
    {
        //  printf("rrrr%d",r[i]);
    }
    for(i=0; i<h; i++)
    {
        if(r[i]==f[d])
        {

            d++;
            o=0;
        }
        else
            goto aa;
    }


    printf("\n\n   *******   the actual message   ********\n\n\n");
    for(i=0; i<c; i++)
    {
        if(f[i]==1 || f[i]==0)
            printf("%d ",f[i]);
    }
    if(o!=0)
    {
aa:
        printf("\n error");
    }


}

