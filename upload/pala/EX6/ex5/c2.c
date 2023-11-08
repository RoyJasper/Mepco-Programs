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

 int sd,n;

char s2[100];

struct sockaddr_in server;

sd=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;


printf("enter port no:");

scanf("%d",&n);

server.sin_port=htons(n);

server.sin_addr.s_addr=htonl(INADDR_ANY);

printf("enter the string:");

scanf("%s",&s2);

sendto(sd,s2,sizeof(s2),0,(struct sockaddr*)&server,sizeof(server));

close(sd);

}
