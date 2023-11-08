#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
    int p1,p2,p3,a[2],b[2],c[2],l,m;
    int t,n,s1=1,s=0;
    p1=pipe(a);
    p2=pipe(b);
    p3=pipe(c);
    m=fork();
    l=fork();
    if(m<0 && l<0)
    {
        printf("\nError");
    }
    else if(m==0 && l>0)
    {
        printf("\nEnter the number");
        scanf("%d",&n);
        close(a[0]);
        write(a[1],&n,sizeof(n));
    }
    if(l==0 && m>0)
    {
        printf("\nChecking even or odd ");
        close(a[1]);
        read(a[0],&n,sizeof(n));
        if(n%2==0)
        {
            printf("\nEven");
            close(b[0]);
            write(b[1],&n,sizeof(n));
        }
        else
        {
            close(c[0]);
            printf("\nOdd");
            write(c[1],&n,sizeof(n));
        }
    }
    if(m==0 && l>0)
    {
        close(b[1]);
        read(b[0],&n,sizeof(n));
        while(n!=0)
        {
            t=n%10;
            n=n/10;
            s1=s1*t;
        }
        printf("\nMultiplication of digits of the number is %d",s1);
    }
    if(m==0 && l==0)
    {
        close(c[1]);
        read(c[0],&n,sizeof(n));
        while(n!=0)
        {
            t=n%10;
            n=n/10;
            s=s+t;
        }
        printf("\nSum of the digits of the number is %d",s);
    }
}

