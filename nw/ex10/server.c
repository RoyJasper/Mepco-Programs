#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
void dij(int n,int v,int cost[20][20],int dist[])
{
int i,u,count,w,flag[10],min;
for(i=1;i<=n;i++)
{
flag[i]=0;
dist[i]=cost[v][i];
}
count=2;
while(count<=n)
{
min=99;
for(w=1;w<=n;w++)
if((dist[w]<min) && !flag[w])
{
min=dist[w];
u=w;
}
flag[u]=1;
count++;
for(w=1;w<=n;w++)
if((dist[u]+cost[u][w] < dist[w]) && !flag[w])
dist[w]=dist[u]+cost[u][w];
}
}
int main()
{
int sd,clen,x;
struct sockaddr_in ser;
struct sockaddr clt;
ser.sin_family=AF_INET;
ser.sin_port=htons(8989);
ser.sin_addr.s_addr=htonl(INADDR_ANY);
sd=socket(AF_INET,SOCK_DGRAM,0);
bind(sd,&ser,sizeof(ser));
clen=sizeof(clt);
recvfrom(sd,&x,sizeof(x),0,&clt,&clen);
int n,i,j,cost[20][20],dist[10];
printf("\nEnter the number of nodes:");
scanf("%d",&n);
printf("\nEnter the cost matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
//if(cost[i][j]==0)
//cost[i][j]=999;
}
}
dij(n,x,cost,dist);
sendto(sd,dist,sizeof(dist),0,&clt,clen);
close(sd);
}
