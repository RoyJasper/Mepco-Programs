#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int sd,b,ad,f,l,len,i=0,k;
        char msg[100],msg1[100];
	while(i!=100)
	{
		msg[i]='\0';
		i++;
	}
        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NO:");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        sd=socket(AF_INET,SOCK_DGRAM,0);
        printf("ENTER THE MSG");
       memset(server.sin_zero,'\0',sizeof(server.sin_zero));
        scanf("%s",msg);
	printf("ENTER THE KEY");
	scanf("%d",&len);
	ad=strlen(msg);
	for(i=0;i<ad;i++)
	{
		b=msg[i];
//		printf("%c",msg[i]);
		b=b+len;
		msg[i]=b;
	}
	msg[i]=len+48;
	printf("%d%s",strlen(msg),msg);
       sendto(sd,msg,strlen(msg),0,(struct sockaddr *) &server,sizeof(server));
        recvfrom(sd,msg1,1024,0,NULL,NULL);
       // if(strcmp(msg,msg1)==0)
                printf("THE MSG IS %s",msg1);
      //  else
        //        printf("ERROR");
}

