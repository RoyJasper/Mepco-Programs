#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,f,l,len,i=0;
        char msg[100],msg1[100],d,msg2[100];
	FILE *fp;
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
	printf("\nENTER THE USERNAME AND PASSWORD");
	scanf("%s%s",msg,msg1);
	printf("ENTER THE FILENAME");
	scanf("%s",msg2);
        send(sd,msg,100,0);
	send(sd,msg1,100,0);
	send(sd,msg2,100,0);
	recv(sd,msg,100,0);
	fp=fopen(msg,"r");
	while(i!=4)
	{
		fscanf(fp,"%s",msg1);
		printf("\n%s",msg1);
		i++;
	}
	close(sd);
}

