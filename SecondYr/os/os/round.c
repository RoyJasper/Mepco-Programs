#include <stdio.h> 
int main(void) 
{
int i,n,time,remain,flag=0,ts,j,ku[20];
int sum_wait=0,sum_turnaround=0,at[10],bt[10],rt[10];
printf("Enter no of Processes : ");
scanf("%d",&n);
remain=n;
for(i=0;i<n;i++)
{
at[i]=0;
}
for(i=0;i<n;i++)
{
printf("Enter burst time for Process P%d :",i+1);
//scanf("%d",&at[i]);
scanf("%d",&bt[i]);
rt[i]=bt[i];
}
printf("Enter time slice");
scanf("%d",&ts);
printf("\n\nProcess\tTurnaround time\twaiting time\n\n");
j=0;
for(time=0,i=0;remain!=0;)
{
if(rt[i]<=ts && rt[i]>0)
{
time+=rt[i];
rt[i]=0;
flag=1;
ku[j]=i+1;
j++;
}
else if(rt[i]>0)
{
rt[i]-=ts;
time+=ts;
ku[j]=i+1;
j++;
}
if(rt[i]==0 && flag==1)
{
remain--;
printf("P[%d]\t\t%d\t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
sum_wait+=time-at[i]-bt[i];
sum_turnaround+=time-at[i];
flag=0;
}
if(i==n-1)
i=0;
else if(at[i+1]<=time)
i++;
}
printf("\nAvg sum_wait = %f\n",sum_wait*1.0/n);
printf("Avg sum_turnaround = %f\n",sum_turnaround*1.0/n);
for(i=0;i<j;i++)
printf("p[%d]\t",ku[i]);
return 0;
}
