#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
 int d,a[2],n,num[20],i,s;
 int p=pipe(a);
 d=fork();
 if(d==-1)
  {
   printf("Fork error");
   return 0;
  }
 else if(d==0)
  {
   printf("\nIn child\n enter size");
   scanf("%d",&s);
   close(a[0]);
   printf("\n Enter nos");
   for(i=0;i<s;i++)
     scanf("%d",&num[i]);
   write(a[1],&s,sizeof(s));
   write(a[1],&num,sizeof(num));
  }
 else if(d>0)
  {
   printf("\n in Parent");
   close(a[1]);
   read(a[0],&s,sizeof(s));
   read(a[0],&num,sizeof(num));
   int t=0;
   float avg;
   for(i=0;i<s;i++)
     t+=num[i];
   avg=t/s;
   printf("\nAverage is %f\n",avg);
  }
 return 0;
}
