#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
 int d,a[2],n;
 int p=pipe(a);
 d=fork();
 if(d==-1)
  {
   printf("Fork error");
   return 0;
  }
 else if(d==0)
  {
   printf("\nIn child\n enter no");
   scanf("%d",&n);
   close(a[0]);
   write(a[1],&n,sizeof(n));
  }
 else if(d>0)
  {
   printf("\nIn parent");
   close(a[1]);
   read(a[0],&n,sizeof(n));
   if(n%2==0)
    printf("\n Even\n");
   else 
    printf("\n Odd\n");
  } 
}
