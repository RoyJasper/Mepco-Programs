#include<stdio.h>
#include<string.h>  
#include<sys/socket.h>
#include<arpa/inet.h>   
#include<unistd.h>  
main()
{
char ip1[100],buf1[100];
int portno,c,size;
//FILE *fp;
struct sockaddr_in clt;
struct sockaddr_storage sersto;
printf("enter the port num");
scanf("%d",&portno);
//socklen_t size;
c=socket(AF_INET,SOCK_STREAM,0);
clt.sin_family=AF_INET;
clt.sin_port=htons(portno);
clt.sin_addr.s_addr=INADDR_ANY;
size=sizeof(clt);
connect(c,(struct sockaddr *)&clt,size);
printf("enter the ip address");
scanf("%s",ip1);
send(c,ip1,sizeof(ip1),0);
recv(c,buf1,sizeof(buf1),0);
printf("MAC address is %s",buf1);
}
