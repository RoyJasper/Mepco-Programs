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
        sd=socket(AF_INET,SOCK_DGRAM,0);
//        printf("ENTER THE NUMBER");
	memset(server.sin_zero,'\0',sizeof(server.sin_zero));
  //      scanf("%d",&b);
//	msg[0]=b+48;
//	len=sizeof(server);
      //  sendto(sd,msg,strlen(msg),0,(struct sockaddr *) &server,sizeof(server));
        recvfrom(sd,msg1,1024,0,NULL,NULL);
       // if(strcmp(msg,msg1)==0)
                printf("THE MSG IS %s",msg1);
      //  else
        //        printf("ERROR");
}
