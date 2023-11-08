#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    FILE *fp;
    fp=fopen("ham.txt","r");
    int i=1,a[100],c,n,m,j,k,t[20],r=0,h,l[20],x,v;
    int red[20][20],b,e,vv[20],flag=0,p=0,q[20];
    char z;
    z=fgetc(fp);
     while(z!=EOF)
    {
     c=(int) z;
     if(c==48)
     {
        a[i]=0;
        i=i+1;
     }
     else if(c==49)
     {
         a[i]=1;
         i=i+1;
     }
     z=fgetc(fp);
   }
   m=i-1;
   n=i;
   for(j=1;j<i;j++)
   {
     t[j]=a[m];
      m--;
      printf("%d",t[j]);
   }

   // printf("\nThe binary values \n");
   while(pow(2,r)<n)
    {
        r=r+1;;
    }
    n=n-1;
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
           // printf("%d",l[x]);
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
        //    printf("%d",red[i][j]);
        }
       // printf("\n");
    }
    b=r-1;
    for(j=0;j<r;j++)
    {
        for(e=1;e<=n;e++)
        {
            if(red[e][j]!=0)
            {
                vv[p]=t[red[e][j]];
         //       printf("%d",vv[p]);
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
         q[b]=0;
         b=b-1;
        }
        else if((flag%2)==1)
        {
            q[b]=1;
            b=b-1;
        }
        flag=0;
        p=0;
    }
    int flag1=0,sum=0;
    for(i=0;i<r;i++)
        printf("\t%d",q[i]);
    for(i=0;i<r;i++)
    {
        if(q[i]==0)
            flag1=flag1+1;
    }
    if(flag1==r)
        printf("\n no error");
    else
    {
        for(i=0;i<r;i++)
        {
         sum=sum+(q[i]*pow(2,i));
         //printf("\n%d",sum);
        }
            printf("\n %d  corrupted",sum);
               /*m=i-1;
   n=i;
   printf("\nCorrected msg is \n");
   for(j=1;j<i;j++)
   {
       t[j]=a[m];
       m--;
       if(i==sum)
       {
           if(t[j]==0)
            t[j]=1;
           if(t[j]==1)
            t[j]=0;
       }
       printf("%d",t[j]);
   }*/

    }
}

