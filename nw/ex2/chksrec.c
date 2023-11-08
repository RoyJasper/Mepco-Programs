#include<stdio.h>
main()
{
    long int a,b;
    int c[80],e[80],cs[80],f[80],cd[80],y,z,i,d,j,l[80],flag=0;
    FILE *fp;
    fp=fopen("test.txt","r");
    i=0;
    for(i=0; i<8; i++)
    {
        fscanf(fp,"%d",&c[i]);
        if(c[i]==2)
            c[i]=0;
    }
    printf("\n");
    i=0;
    for(i=0; i<8; i++)
    {
        fscanf(fp,"%d",&e[i]);
        if(e[i]==2)
            e[i]=0;
    }
    i=0;
    for(i=0; i<8; i++)
    {
        fscanf(fp,"%d",&cs[i]);
        if(cs[i]==2)
            cs[i]=0;
    }
    for(i=7; i>=0; i--)
    {
        f[i]=add(c[i],e[i]);
    }
    for(i=7; i>=0; i--)
    {
        cd[i]=add1(f[i],cs[i]);
        cd[i]=com(cd[i]);
    }
    for(i=0; i<=7; i++)
    {
        if(cd[i]==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\n Correct Message received   \n");
        rewind(fp);
        i=0;
        while(fscanf(fp,"%d",&l[i])!=EOF)
        {
            if(l[i]!=2)
                printf("%d",l[i]);
            else
                break;
            i++;
        }
    }
    else
        printf("Wrong Message");

}
int add(int x,int y)
{
    static int c=0;
    if((x==0)&&(y==0)&&(c==0))
    {
        c=0;
        return 0;
    }
    if((x==0)&&(y==1)&&(c==0))
    {
        c=0;
        return 1;
    }
    if((x==1)&&(y==0)&&(c==0))
    {
        c=0;
        return 1;
    }
    if((x==1)&&(y==1)&&(c==0))
    {
        c=1;
        return 0;
    }
    if((x==0)&&(y==0)&&(c==1))
    {
        c=0;
        return 1;
    }
    if((x==0)&&(y==1)&&(c==1))
    {
        c=1;
        return 0;
    }
    if((x==1)&&(y==0)&&(c==1))
    {
        c=1;
        return 0;
    }
    if((x==1)&&(y==1)&&(c==1))
    {
        c=1;
        return 1;
    }
}
int com(int x)
{
    if (x==1)
        return 0;
    else
        return 1;
}
int add1(int x,int y)
{
    static int c=0;
    if((x==0)&&(y==0)&&(c==0))
    {
        c=0;
        return 0;
    }
    if((x==0)&&(y==1)&&(c==0))
    {
        c=0;
        return 1;
    }
    if((x==1)&&(y==0)&&(c==0))
    {
        c=0;
        return 1;
    }
    if((x==1)&&(y==1)&&(c==0))
    {
        c=1;
        return 0;
    }
    if((x==0)&&(y==0)&&(c==1))
    {
        c=0;
        return 1;
    }
    if((x==0)&&(y==1)&&(c==1))
    {
        c=1;
        return 0;
    }
    if((x==1)&&(y==0)&&(c==1))
    {
        c=1;
        return 0;
    }
    if((x==1)&&(y==1)&&(c==1))
    {
        c=1;
        return 1;
    }
}

