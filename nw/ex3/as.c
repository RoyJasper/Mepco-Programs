#include<stdio.h>
#include<string.h>
main()
{
 FILE *fp;
 char t[100],y;
 int x,f,k,m[20],mm[20],count,j=0,ex,array[20], i;
 fp=fopen("a.c","w");
 int s,n;
 printf("\n enter the message   \n");
 char h;
 scanf("%c",&h);
 i=0;
 while(h!='a')
 {
     t[i]=h;
      scanf("\n%c",&h);
      i++;
 }
 count=i;
  for(i=0;i<count;i++)
 {
     printf("%c ",t[i]);
 }
 printf("\n\n\n");
 for(i=0;i<count;i++)
 {
     y=t[i];
 if((int)y==48)
    m[i]=0;
else if((int)y==49)
    m[i]=1;
else
    m[i]=2;

printf("%d ",m[i]);
 }
          if(count%8==0)
            ex=0;
          else
          {
          ex=8-(count%8);
  for(i=count;i<count+ex;i++)
   {
      m[i]=2;
    }
          }
   count=count+ex;

          printf("\ncount  %d",count);
  for(i=0;i<8;i++)
    array[i]=0;
    for(i=0;i<count;i++)
      {
          k=i%8;


          if(m[i]==1)

               array[k]=array[k]+1;
       }
     for(i=0;i<count;i++)
       {
          fprintf(fp,"%d",m[i]);
        }
        putc('#',fp);
      for(i=0;i<8;i++)
       {
         if(array[i]%2==0)
           putc('0',fp);
         else
           putc('1',fp);
        }
       putc('#',fp);
       k=1;
       for(i=0;i<count;i++)
       {
         if((i/8)==k)
            k++;
         if(m[i]==1)
            array[k]=array[k]+1;
       }
       for(i=1;i<=k;i++)
         {
          if((array[i]%2)==0)
            putc('0',fp);
          else
             putc('1',fp);
          }
     }


