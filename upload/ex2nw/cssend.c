#include<stdio.h>
main()
{
    long int a,b;
    int c[100],e[100],cs[100],y,z,i,d,j,m;
    char f;
    FILE *fp;
    fp=fopen("test.txt","w");
    printf("Enter the DATA");
    scanf("%ld",&a);
    i=0;
    d=0;
    while(a!=0)
    {
        b=a%10;
        a=a/10;
        c[i]=b;
        printf("\n%d",c[i]);
        i++;
        d++;
    }
    j=0;
    for(i=d-1; i>=0; i--)
    {
        e[j]=c[i];
        printf("%d\n",e[j]);
        j++;
    }
    y=d/8;
    y++;
    z=y*8;
    m=2;
    printf("%d\n",z);
    for(i=0; i<z; i++)
    {
        if(i<d)
            fprintf(fp,"%d ",e[i]);
        else
            fprintf(fp,"%d ",m);
    }
    fprintf(fp,"\n");
    for(i=0; i<z; i++)
    {
        if(i>=d)
            e[i]=0;
    }
    j=15;
    for(i=7; i>=0; i--)
    {
        cs[i]=add(e[i],e[j]);
//fprintf(fp,"%d ",cs[i]);
        j--;
    }
    for(i=0; i<=7; i++)
    {
        cs[i]=com(cs[i]);
        fprintf(fp," %d",cs[i]);
    }
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
