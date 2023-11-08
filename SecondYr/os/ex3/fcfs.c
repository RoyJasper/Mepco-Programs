#include<stdio.h>
#include<math.h>
int main()
{
    int su,p[20],j=0,k,d[20],b[20],w[20],t[20],i,v,wt=0,at,sum=0;
    float fw,fr,n;
    printf("\nEnter no of process ");
    scanf("%f",&n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter burst time for  P%d",i+1);
        scanf("%d",&d[i]);
    }
    j=0;
    for(i=0; i<n; i++)
    {
        su=0;
        for(k=0; k<=i; k++)
        {
            su=su+d[k];
        }
        w[j]=su;
        j++;
    }
    t[0]=0;
    t[1]=w[0];
    for(i=2; i<n; i++)
    {
        t[i]=w[i-1];
    }
    for(i=0; i<n; i++)
    {
        printf("\nTurn over time for process P%d: IS  ",i+1);
        printf("%d",w[i]);
        sum=sum+w[i];
    }
    int df=0;
    for(i=0; i<n; i++)
    {
        printf("\nWaiting time for process P%d: IS  ",i+1);
        printf("%d",t[i]);
        df=df+t[i];
    }
    fr=su/n;
    fw=sum/n;
    printf("\nAverage turn over time is %f",fw);
    printf("\nAverage waiting time is  %f",fr);
    return 0;

}
 
