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
        printf("ENTER THE MSG");
	scanf("%s",msg);
        send(sd,msg,100,0);
	recv(sd,msg1,100,0);
	if(strcmp(msg,msg1)==0)
		printf("THE MSG IS %s",msg1);
	else
		printf("ERROR");
        close(sd);

}

