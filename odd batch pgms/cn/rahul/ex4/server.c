#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,lac,l,len,f;
	char msg[100];
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
	b=bind(sd,(struct sockaddr *) &server,sizeof(server));
	if(b>=0)
		printf("BIND SUCCESS");
	else
		printf("BIND ERROR");
	l=listen(sd,5);
	if(l>=0)
		printf("LISTEN SUCCESS");
	len=sizeof(client);
	ad=accept(sd,(struct sockaddr *) &client,&len);
	if(ad>=0)
		printf("ACCEPT SUCCESS");
	recv(ad,msg,100,0);
	printf("CLIENT:%s",msg);
	send(ad,msg,100,0);
	close(sd);
return 0;
}

