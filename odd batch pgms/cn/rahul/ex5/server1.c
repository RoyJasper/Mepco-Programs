#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int ad,b,lac,len,f,i=0;
        char msg[100];
	while(i!=100)	
	{
		msg[i]='\0';
		i++;
	}
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NUMBER");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        ad=socket(AF_INET,SOCK_DGRAM,0);
        b=bind(ad,(struct sockaddr *) &server,sizeof(server));
        recvfrom(ad,msg,1024,0,(struct sockaddr *) &client,sizeof(client));
        lac=strlen(msg);
	len=msg[lac-1]-48;
	msg[lac-1]='\0';
//	printf("%d%s",strlen(msg),msg);
	for(i=0;i<strlen(msg);i++)
	{
		b=msg[i];
		b=b-len;
		msg[i]=b;
	}
	printf("%s",msg);
        sendto(ad,msg,strlen(msg),0,(struct sockaddr *) &client, sizeof(client));
return 0;
}

