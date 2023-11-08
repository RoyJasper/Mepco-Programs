#include<stdio.h>
#include<string.h>
main()
{
    int i,j,a,b,c,d,flag=1;
    int r[100],sum=1;
    scanf("%d",&a);
    i=0;
    while(i<a)
    {
        scanf("%d",&b);
        for(j=0; j<b; j++)
        {
            scanf("%d",&r[j]);
            sum=sum*r[j];
        }
        for(j=0; j<b; j++)
        {
            if (sum==r[j])
                flag=0;
        }
        if(flag==0)
            printf("yes\n");
        else
            printf("no\n");
        flag=1;
        sum=1;
        i++;
    }
}

