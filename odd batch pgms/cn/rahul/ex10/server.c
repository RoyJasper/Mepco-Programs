#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int sd,b,ad,i,l,len,f,j,n,m,flag[50],v,min,last[50],dis[50],a[100][100];
        char msg[100],aa[10],msg1[50][50],msg2[100];
	strcpy(msg,"1");
	strcpy(msg2,"1");
	i=0;
	while(i!=50)
	{
		last[i]=0;
		i++;
	}
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NUMBER");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd==0)
                printf("SOCKET SUCCESS");
        else
                printf("ERROR");
        b=bind(sd,(struct sockaddr *) &server,sizeof(server));
        if(b==0)
                printf("BIND SUCCESS");
        else
                printf("BIND ERROR");
        l=listen(sd,5);
        if(l==0)
                printf("LISTEN SUCCESS");
        len=sizeof(client);
        ad=accept(sd,(struct sockaddr *) &client,&len);
	recv(ad,aa,10,0);
	m=aa[0]-48;
	printf("\n%d",m);
        if(ad>0)
                printf("ACCEPT SUCCESS");
	i=0;
	while(i<=m)
	{
		recv(ad,msg,100,0);
		strcpy(msg1[i-1],msg);
		i++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<strlen(msg1[i]);j++)
		{
			if(msg1[i][j]!='^')
				a[i][j]=msg1[i][j]-48;
			else
				a[i][j]=999;
		}
	}
	recv(ad,aa,10,0);
	n=aa[0]-48;
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
	{
		msg[i]=dis[i]+48;
	}
	msg[i]='$';
	i++;
	j=0;
	for(;i<(m+m+1);i++)
	{
		msg[i]=last[j]+48;
		j++;
	}
	send(ad,msg,strlen(msg),0);
}
