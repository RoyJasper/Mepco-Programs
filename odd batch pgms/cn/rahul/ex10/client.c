#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,k,f,l,len,i,j,n,a[50][50];
        char msg[100],msg1[100],aa[50],msg2[100];
	strcpy(msg,"\0");
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
	printf("ENTER THE PORT NO:");
	scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        sd=socket(AF_INET,SOCK_STREAM,0);
        b=connect(sd,(struct sockaddr *) &server,sizeof(server));
	if(b>=0)
		printf("CONNECT SUCCESS");
        printf("\nENTER THE NO OF ROUTERS");
	scanf("%d",&n);
	aa[0]=n+48;
	send(sd,aa,100,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=999)
				msg[j]=a[i][j]+48;
			else
				msg[j]='^';
		}
		send(sd,msg,100,0);
	}
	printf("\nENTER THE SOURCE VERTEX");
	scanf("%d",&n);
	aa[0]=n+48;
	send(sd,aa,100,0);
	recv(sd,msg1,50,0);
	i=0;
	while(msg1[i]!='$')
		i++;
	msg1[i]='\0';
	i++;
	j=i;
	k=0;
	for(;j<(i+i);j++)
	{
		msg2[k]=msg1[j];
		msg1[j]='\0';
		k++;
	}
	//recv(sd,msg2,50,0);
	printf("\nNODE\tCOST\tNEXT");
	for(i=0;i<strlen(msg1);i++)
		printf("\n%d\t%c\t%c",i,msg1[i],msg2[i]);
	close(sd);
}
