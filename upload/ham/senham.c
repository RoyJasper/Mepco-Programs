#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
main()//10110111111
{
    int m,n;
    int a[20],t[20],l[10],i=0,r=1,j,h,k,v,x,b;
    int red[20][20],p=0,flag=0,e,vv[20];
    printf("\n enter the message");
    scanf("%d",&a[i]);
    while(a[i]!=99)
    {
       i++;
       scanf("%d",&a[i]);
    }
    m=i;
    while(pow(2,r)<=(m+r+1))
    {
        r++;
    }
    n=r+m;
    for(i=1;i<=n;i++)
        t[i]=0;
    j=2;
    i=0;
    while(pow(2,i)<n)
    {
        h=pow(2,i);
        t[h]=j;
        j++;
        i++;
    }
    j=0;
    for(i=n;i>0;i--)
    {
        if(t[i]==0)
        {
         t[i]=a[j];
         j++;
        }
    }
   // printf("\nthe binary values \n");
    for(i=1;i<=n;i++)
    {
        k=i;h=r-1;
        while((k!=1)&&(k!=0))
        {
            v=k%2;
            l[h]=v;
            k=k/2;
            h--;
        }
        if(k==1)
        {
            l[h]=1;
            while(h!=0)
            {
                h--;
                l[h]=0;
            }
        }
        else if(k==0)
        {
            l[h]=0;
            while(h!=0)
            {
                h--;
                l[h]=0;
            }

        }

        for(x=0;x<r;x++)
          //  printf("%d",l[x]);
        //printf("\n");
        for(j=r-1;j>=0;j--)
        {
            if(l[j]==1)
                red[i][j]=i;
            else
                red[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<r;j++)
        {
           // printf("%d",red[i][j]);
        }
        //printf("\n");
    }
    b=r-1;
    for(j=0;j<r;j++)
    {
        for(e=1;e<=n;e++)
        {
            if(red[e][j]!=0)
            {
                vv[p]=t[red[e][j]];
               // printf("%d",vv[p]);
                p++;
            }
        }
        printf("\n");
        for(m=0;m<p;m++)
        {
          if(vv[m]==1)
             flag=flag+1;
        }
        if((flag%2)==0)
        {
         h=pow(2,b);
         t[h]=0;
         b=b-1;
        }
        else if((flag%2)==1)
        {
            h=pow(2,b);
            t[h]=1;
            b=b-1;
        }
        flag=0;
        p=0;
    }
   for(i=n;i>0;i--)
     printf("%d",t[i]);
   FILE *fp;
   fp=fopen("ham.txt","w");
   for(i=n;i>0;i--)
        fprintf(fp,"%d",t[i]);
}

