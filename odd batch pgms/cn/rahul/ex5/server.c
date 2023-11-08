#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int ad,b,lac,len,f,i;
        char msg[100];
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NUMBER");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        ad=socket(AF_INET,SOCK_DGRAM,0);
        if(ad>0||ad==0)
                printf("SOCKET SUCCESS");
        else
                printf("ERROR");
        b=bind(ad,(struct sockaddr *) &server,sizeof(server));
        if(b>0||b==0)
                printf("BIND SUCCESS");
        else
                printf("BIND ERROR");
        len=sizeof(client);
        recvfrom(ad,msg,1024,0,(struct sockaddr *) &client,sizeof(client));
        printf("CLIENT:%s",msg);
        sendto(ad,msg,strlen(msg),0,(struct sockaddr *) &client, sizeof(client));
return 0;
}
