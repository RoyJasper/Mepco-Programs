#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
     int a[200],b[200],c[200],d[200],i=1,k,m,f,n,j,r,p,y,z,ch,key,q,v,sum=0;
     char pp[100],x;
     FILE *fp;
     fp=fopen("d.txt","r");
     x=fgetc(fp);
     printf("\n ***** the intermediate message  ******* \n\n\n");
     while((x!='#'))
     {
     if((int)x==48)
     a[i]=0;
     else if((int)x==49)
     a[i]=1;
     else
     a[i]=2;
     x=fgetc(fp);
     printf("%d ",a[i]);
     i++;
     }
     n=i;
     printf("  %d  ",n);
     j=0;
     for(i=n;i>=1;i--)
     {
         b[j]=a[i];
         j++;
     }
     fscanf(fp,"%d",&k);
     fscanf(fp,"%d",&m);
     n=k+m;
        p=0; q=0;
        for(i=1; i<=m; i++)
        {
                x=pow(2,p);
                r=1;
                for(j=x; j<=n; j=j+(x*2))
                {
                        for(y=j; y<(j+x); y++)
                        {
                                c[r]=b[y];
                                r++;
                        }
                }
                z=0;
                for(y=1; y<=(r-1); y++)
                {
                        if(c[y]==1) z++;
                }
                v=z%2;
           d[q]=v;
           sum=sum+(v*pow(2,q));
           q++;
                for(y=1; y<=20; y++)
                        c[y]=0;
                p++;
        }
     if(sum==0)
           printf("\n\n NO ERROR FOUND....... \n\n");
     else
           printf("\n\n ERROR AT POSITION %d",sum);
     printf("\n");
     j=1;
     for(i=n;i>=1;i--)
     {
         if(i==sum)
         {
             if(b[i]==0)
                a[j]=1;
             else
                a[j]=0;;
         }
         else
         a[j]=b[i];
          j++;
      }
      for(i=1;i<=n;i++)
        printf("%d",a[i]);
     return 0;
}
