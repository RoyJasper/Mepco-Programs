#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    int in=0,out=0,n,c,p,f,i;
    int *a,*b;
    int e,d;
    e=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
    a=(int *)shmat(e,NULL,0);
    d=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0766);
    b=(int *)shmat(d,NULL,0);
    b=malloc(sizeof(int)*5);
    *a=1;
    f=fork();
    if(f==0)
    {
        if(*a==5)
            printf("\nThere are More Items in the shop");
        else
        {
            a=a+1;
            printf("\t\t\t---->%d",a);
            printf("\nEnter the Thing to be Inserted");
            scanf("%d",&p);
            b[in]=p;
            in=in+1;
        }
    }
    else if(f>0)
    {
        getchar();
        printf("--------->%d",a);
        if(*a==1)
            printf("\nThere is nothing in the Shop...Please Wait!!");
        else
        {
            c=b[out];
            out=((out+1)%5);
            printf("\n%d",c);
            a--;
        }
    }
    else if(f<0)
        printf("ERROR");
    else
        printf("Sorry");
}

