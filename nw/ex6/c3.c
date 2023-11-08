#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

main()

{

 int sd;

char s2[100];

struct sockaddr_in server;

sd=socket(AF_INET,SOCK_DGRAM,0);

int n;

server.sin_family=AF_INET;

printf("enter the  port number:");

scanf("%d",&n);

server.sin_port=htons(n);

server.sin_addr.s_addr=htonl(INADDR_ANY);

int bb=sizeof(server);


strcpy(s2,"client 3");

sendto(sd,s2,sizeof(s2),0,(struct sockaddr*)&server,sizeof(server));

recvfrom(sd,s2,sizeof(s2),0,(struct sockaddr *)&server,&bb);

printf("msg received\n");

printf("\nThe concatenated message is:%s\n",s2);

close(sd);

}

