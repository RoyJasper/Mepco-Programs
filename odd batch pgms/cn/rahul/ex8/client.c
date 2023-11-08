#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,f,l,len;
        char msg[100],msg1[100];
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
        printf("\nEnter a H/W address");
	scanf("%s",msg);
	send(sd,msg,sizeof(msg),0);
	recv(sd,msg1,50,0);
	printf("\nThe IP ADDRESS is: %s",msg1);
	close(sd);
}

