#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int i,j,n,a[50][50],dis[50],last[50],flag[50],min,v,m,mm;
     	printf("\nENTER THE NO OF ROUTERS");
	scanf("%d",&m);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	printf("\nENTER THE SOURCE VERTEX");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		flag[i]=0;
		dis[i]=999;
	}
	dis[n]=0;
	for(i=0;i<m;i++)
	{
		min=9999;
		for(j=0;j<m;j++)
		{
			if(flag[j]!=1)
			{
				if(dis[j]<min)
				{
					v=j;
					min=dis[j];
				}
			}
		}
		flag[v]=1;
		for(j=0;j<m;j++)
		{
			if(flag[j]==0);
			{
				if(min+a[v][j]<dis[j])
				{
					dis[j]=min+a[v][j];
					last[j]=v;
				}
			}
		}
		flag[v]=1;
	}
	for(i=0;i<m;i++)
		printf("\n%d\t%d",dis[i],last[i]);

}
