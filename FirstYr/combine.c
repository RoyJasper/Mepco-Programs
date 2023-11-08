#include<stdio.h>
#include<stdlib.h>
main()
{
int n,i,c,m,*p,*q;
printf("enter number of elements of a and b");
scanf("%d%d",&n,&m);
p=(int *)malloc(n*sizeof(int));
q=(int *)malloc(m*sizeof(int));
printf("enter A elements :");
for(i=0;i<n;i++)
 scanf("%d",(p+i));
printf("enter B elements:");
for(i=0;i<m;i++)
 scanf("%d",(q+i));
int j,flag=0;
printf("A combined with B is\n");
for(i=0;i<n;i++)
    {
      printf("%d\t",(p+i));
    }
   for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
      {
       if(*(q+i)!=*(p+j))
        flag=1;
       else
        {
        flag=0;
         break;
        }
      }
       if(flag==1)
      {
       printf("%d\t",q[i]);
      }
    }
  }
/*
}
#include<stdio.h>
main()
{
 int a[10],b[10],i,j,*p,*q,n;
 printf("Enter no of elements of both arrays\n"); 
 scanf("%d",&n);
 printf("Enter array A\n");
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("Enter array B\n");
 for(j=0;j<n;j++)
   scanf("%d",&b[i]);
 p=a;
 q=b;
  printf("Combined array is \n");
 for(i=0;i<n;i++)
   printf("%d\t",*(a+i));
 for(i=0;i<n;i++)
   {
    if(*(a+i)==*(b+i))
      {
       *(b+i)=1212;
      }
   }
   for(i=0;i<n;i++)
    { 
     if(*(b+i)!=1212)
       {
         printf("%d\t",*(b+i));
       }
    }
}*/
