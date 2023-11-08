#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
int i,n,sd,len,x,dist[10];
struct sockaddr_in ser;
ser.sin_family=AF_INET;
ser.sin_port=htons(8989);
ser.sin_addr.s_addr=htonl(INADDR_ANY);
sd=socket(AF_INET,SOCK_DGRAM,0);
printf("\nEnter the Node");
scanf("%d",&x);
sendto(sd,&x,sizeof(x),0,&ser,sizeof(ser));
recvfrom(sd,&dist,sizeof(dist),0,NULL,NULL);
for(i=0;i<7;i++)
printf("\n%d-->%d",i+1,dist[i]);
close(sd);
}
