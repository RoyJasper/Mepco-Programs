#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main()
{
int n,s1=0,s2=0,avg,i,d,k,l,s=0,*a;
printf("\nenter the number of element:");
scanf("%d",&n);
d=shmget(IPC_PRIVATE,n*sizeof(int),0766|IPC_CREAT);
a=(int *)shmat(d,NULL,0);
printf("\nenter the elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
k=fork();
l=fork();
if(l==0)
{
for(i=n/2;i<n;i++)
s2=s2+a[i];
printf("\nsum of the last n/2 elements:%d",s2);
}
else
if(k==0 && l>0)
{
for(i=0;i<n/2;i++)
s1=s1+a[i];
printf("\nSum of the  first n/2 elements:%d",s1);
}
else
if(k>0 && l>0)
{
for(i=0;i<n;i++)
s=s+a[i];
avg=s/n;
printf("\nAverage:%d\n",avg);
}
else
printf("\nError\n");
}
