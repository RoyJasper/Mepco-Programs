#include<stdio.h>
#include<string.h>  
#include<sys/socket.h>
#include<arpa/inet.h>   
#include<unistd.h>  
main()
{
char ip[100],type[100],flag[100],addr[100],mask[100],buf[100],dev[100];
int portno,fd,ns;
FILE *fp;
struct sockaddr_in ser;
struct sockaddr_storage sersto;
printf("enter the port num");
scanf("%d",&portno);
socklen_t addr1;
fd=socket(AF_INET,SOCK_STREAM,0);
ser.sin_family=AF_INET;
ser.sin_port=htons(portno);
ser.sin_addr.s_addr=INADDR_ANY;
if(bind(fd,(struct sockaddr *)&ser,sizeof(ser)));
printf("binded");
listen(fd,10);
addr1=sizeof(sersto);
ns=accept(fd,(struct sockaddr *)&sersto,&addr1);
fp=fopen("/proc/net/arp","r");
recv(ns,buf,sizeof(buf),0);
printf("\n%s\n",buf);
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%c%s",ip,type,flag,addr,mask,dev);
printf("%s",addr);
if(strcmp(ip,buf)==0)
{
send(ns,addr,sizeof(addr),0);
}
}
}
