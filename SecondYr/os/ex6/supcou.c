#include<stdlib.h>
#include<stdio.h>
#define BUFFER_SIZE 5
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    int tin,tout,*in,*out,tc,*c,k,ta,a,cho,nextc,nextp,temc,p;
 ta=shmget(IPC_PRIVATE,sizeof(BUFFER_SIZE * (sizeof(int))),0766|IPC_CREAT);
 a=(int *)shmat(ta,NULL,0);
 tc=shmget(IPC_PRIVATE,sizeof(int),0766|IPC_CREAT);
 c=(int *)shmat(tc,NULL,0);
 tin=shmget(IPC_PRIVATE,sizeof(int),0766|IPC_CREAT);
 in=(int *)shmat(tin,NULL,0);
 tout=shmget(IPC_PRIVATE,sizeof(int),0766|IPC_CREAT);
 out=(int *)shmat(tout,NULL,0);
 out=0;
 in=0;
    while(1)
    {
        k=fork();
        printf("\nEnter the Choice \n1.Consumer \n2.Producer \n3.Exit");
        scanf("%d",&cho);
        switch(cho)
        {
        case 1:
            if(k==0)
            {
            if(*in==*out)
                printf("\nThere is nothing heare....");
            else
            {
                temc=a[out];
                *out=( (*out+1) % BUFFER_SIZE);
                printf("\n%d",temc);
            }
            }
            else 
              printf("Wait");  
            break;
        case 2:
            if(k>0)
            {
            if(*out==(*in+1) % BUFFER_SIZE)
                printf("\nThere are More Items..... ");
            else
            {
                printf("\nEnter the Item to be Inserted " );
                scanf("%d",&p);
                a[in]=p;
                *in=((*in+1)%BUFFER_SIZE);
            }
            }
            else
              printf("Wait");
            break;
        case 3:
            exit(0);
        }
    }
}

