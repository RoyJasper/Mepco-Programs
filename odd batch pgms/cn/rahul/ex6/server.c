#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
        int sd,b=1,n0,len,f,i,a,n1,n2,n3;
        char msg[100],m1[100],m2[100],m3[100];
        struct sockaddr_in server,client,client1;
        server.sin_family=AF_INET;
        printf("ENTER THE PORT NUMBER");
        scanf("%d",&f);
        server.sin_port=htons(f);
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        sd=socket(AF_INET,SOCK_DGRAM,0);
//	if(sd!=0)
//	{
//		printf("SOCKET ERROR");
//		return 0;
//	}
	b=bind(sd,(struct sockaddr *) &server,sizeof(server));
	f=fork();
	for(i=0;i<=2;i++)
	{
 		if(f>0)
 		{
  			if(i==0)
  			{
   				recvfrom(sd,&m1,100,0,(struct sockaddr*)&client,sizeof(client));
   				n1=atoi(m1);
   				printf("\n The number is %s",m1);
  			}
  			if(i==1)
  			{
   				recvfrom(sd,&m2,100,0,(struct sockaddr*)&client1,sizeof(client1));
   				n2=atoi(m2);
   				printf("\n The number is %d",n2);
  			}
  			if(i==2)
  			{
  				n3=n1+n2;
  				printf("\nThe sum is %d",n3);
  				sprintf(m3,"%d",n3);
				printf("\n\n\nThe m3 is %s",m3);
   				sendto(sd,&m3,sizeof(m3),0,(struct sockaddr*)&client,sizeof(client));
  			}
 		}
	}
	return 0;
}
