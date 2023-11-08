#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int p1,p2,p3,n1,n2,a[2],b[2],c[2],m=1,l,t=1,s=0,n,t1=0;
    p1=pipe(a);
    p2=pipe(b);
    p3=pipe(c);
    m=fork();
    l=fork();
    if(m<0&&l<0)
    {
        printf("\n Error");
     //   return 1;
    }
   if(m>0&&l>0)
    {
        printf("\nIn P1 \n Enter no ");
        scanf("%d",&n);
        close(a[0]);
        write(a[1],&n,sizeof(n));
    }
    if(l==0&&m>0)
    {
      //  printf("\nChecking odd or even in P2\n");
        read(a[0],&n,sizeof(n));
        if(n%2==0)
        {
           printf("\nChecking odd or even in P2\n");
            printf("\n Even");
            close(b[0]);
            write(b[1],&n,sizeof(n));
        }
        else
        {
           printf("\nChecking odd or even in P2\n");
            close(c[0]);
            printf("\n Odd");
            close(c[0]);
            write(c[1],&n,sizeof(n));
    }
   if(m==0&&l>0)
    {
        close(b[1]);
        read(b[0],&n,sizeof(n));
        n1=n;
        n2=n;
       // printf("%d %d",n,n1);
        while(n!=0)
        {
            t=n2%10;
            n2=n2/10;
            m*=t;
        }
        printf("\nIn P3\n  Multiplication of digits are %d",m);
      //  return 0;
    }
   if(m==0&&l==0)
    {
        close(c[1]);
        read(c[0],&n,sizeof(n));
        while(n!=0)
        {
            t1=n1%10;
            n1=n1/10;
            s+=t1;
        }
        printf("\n in P4 \n Addition of digits are %d",s);
       // return 0;
    }
 //   return 0;

}
}
