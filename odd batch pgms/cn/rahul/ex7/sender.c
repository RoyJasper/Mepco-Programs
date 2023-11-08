#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<time.h>
int main()
{
        int sd,b,n,lac,l,count,f,m,t[100],i,j,k;
        char msg[100][100],a[10],msg1[100];
	time_t start,end;
	struct tm *cpu;
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NUMBER");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd>=0)
                printf("SOCKET SUCCESS");
        else
                printf("ERROR");
        b=connect(sd,(struct sockaddr *) &server,sizeof(server));
	printf("ENTER THE NO OF FRAMES:");
	scanf("%d",&m);
	printf("ENTER THE WINDOW SIZE:");
	scanf("%d",&n);
	printf("ENTER THE MSG");
	for(i=0;i<m;i++)
	{
		scanf("%s",msg[i]);
	}
	printf("LKL");
	a[0]=m+48;
	send(sd,a,10,0);
	a[0]=n+48;
	send(sd,a,10,0);
	//	printf("%d%d",m,n);
	for(i=0;i<m;i++)
	{
		count=0;
		for(j=0;j<strlen(msg[i]);j++)
		{
			if(msg[i][j]=='1')
			{
				count++;
			}
		}
		if(count%2==0)
			msg[i][strlen(msg[i])]='1';
		else
			msg[i][strlen(msg[i])]='0';
		printf("\n%s",msg[i]);
		if(i==1)
			msg[i][strlen(msg[i])-1]='0';
	}
	k=1;
	//printf("%d%d",m,n);
	for(i=0;i<m;i=i+n)
	{
		printf("%d",i);
		time(&start);
		cpu=localtime(&start);
		t[i]=(int)cpu->tm_sec;
		if(k==1)
		{
			for(j=i;j<(i+n);j++)
			{
				send(sd,msg[j],100,0);
			}
			recv(sd,msg1,100,0);
			printf("%s",msg1);
			if(strcmp(msg1,"SEND")==0)
			{
				k=1;
			}
			else
			{
				k=1;
				msg[1][strlen(msg[i])-1]='1';
				i=i-n;
			}
		}
		else
			break;
	}
close(sd);
}
