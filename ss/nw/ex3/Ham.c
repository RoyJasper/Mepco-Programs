#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
     int a[200],b[200],c[200],d[200],i,k,m,f,n,j,r,p,x,y,z,ch,key,q,v,sum=0;
     char pp[100],yy;
     FILE *fp;
     fp=fopen("d.txt","w");
     printf("\n ENTER THE DATA WORD \n");
     gets(pp);
     k=strlen(pp);
     printf("%d\n",k);
     for(i=1;i<=k;i++)
     {
            yy=pp[i-1];
            if((int)yy==48)
            a[i]=0;
            else if((int)yy==49)
            a[i]=1;
            else
            a[i]=2;
     }
     for(i=1;i<=k;i++)
        printf("%d",a[i]);
     m=1;
     while(pow(m,2)<=(k+m+1))
     {
      m++;
     }
     printf("\n Value of m is : %d",m);
     n=k+m;
     j=1; r=0;
     for(i=1; i<=n; i++){
           p=pow(2,r);
           if(i==p){
                b[i]=3;
                r++;
           }
           else{
                b[i]=a[j];
                j++;
           }
     }
     printf("\n INTERMEDIATE CODE WORD IS \n");
     for(i=1; i<=n; i++)
           printf("%d",b[i]);
     p=0;
     for(i=1; i<=m; i++)
     {
           x=pow(2,p); r=1;
           for(j=x; j<=n; j=j+(x*2)){
                for(y=j; y<(j+x); y++){
                     c[r]=b[y];
                     r++;
                }
           }
           z=0;
           for(y=1; y<=(r-1); y++)
           {
                if(c[y]==1) z++;
           }
           if(z%2==0)
                b[x]=0;
           else
                b[x]=1;
           for(y=1; y<=20; y++)
                c[y]=0;
           p++;
     }
     printf("\n\n THE HAMMING CODE IS \n");
     for(i=n; i>=1; i--)
     {
           fprintf(fp,"%d",b[i]);
           printf("%d",b[i]);
}
     putc('#',fp);
     fprintf(fp,"%d ",k);
     fprintf(fp,"%d ",m);
}
