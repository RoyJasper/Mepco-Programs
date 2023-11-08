#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<netdb.h>
int main(){
	int i,sd,len,clen,ch;
	struct sockaddr_in ser;
	struct sockaddr clt;
	struct hostent*hp;
	struct in_addr **addr_list;
	struct in_addr ip;
	struct servent*sp;
	char buffer[100],hname[20];
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(8980);
	ser.sin_addr.s_addr=htonl(INADDR_ANY);
	sd=socket(AF_INET,SOCK_DGRAM,0);
	bind(sd,&ser,sizeof(ser));
	clen=sizeof(clt);
	do{
		recvfrom(sd,&ch,sizeof(ch),0,&clt,&clen);
//		printf("\n1]gethostbyname\n2]gethostbyaddress\n3]getservbyname\n4]getsservbyport\n5]Exit\n\nEnter your choice:");
//		scanf("%d",&ch);
		switch(ch){
			case 1:recvfrom(sd,hname,sizeof(hname),0,&clt,&clen);
				hp=gethostbyname(hname);
				addr_list = (struct in_addr **)hp->h_addr_list;
				for(i = 0; addr_list[i] != NULL; i++) {
					strcpy(buffer,inet_ntoa(*addr_list[i]));
					sendto(sd,buffer,sizeof(buffer),0,&clt,clen);
				}
				strcpy(buffer,"Empty");
				sendto(sd,buffer,sizeof(buffer),0,&clt,clen);
				break;
			case 2:recvfrom(sd,buffer,sizeof(buffer),0,&clt,&clen);
				inet_aton(buffer,&ip);
				hp=gethostbyaddr((const void*)&ip,sizeof(ip),AF_INET);
//				strcpy(hname,hp->h_name);
				sendto(sd,hp->h_name,sizeof(hname),0,&clt,clen);
				break;
			case 3:recvfrom(sd,hname,sizeof(hname),0,&clt,&clen);
				recvfrom(sd,buffer,sizeof(buffer),0,&clt,&clen);
				printf("%s\t%s",hname,buffer);
				sp=getservbyname(hname,buffer);
				len=ntohs(sp->s_port);
				sendto(sd,&len,sizeof(len),0,&clt,clen);
				break;
			case 4:recvfrom(sd,&len,sizeof(len),0,&clt,&clen);
				recvfrom(sd,buffer,sizeof(buffer),0,&clt,&clen);
				printf("%d\t%s",len,buffer);
				sp=(struct servent*)getservbyport(htons(len),buffer);
//				strcpy(hname,sp->s_name);
				sendto(sd,sp->s_name,sizeof(hname),0,&clt,clen);
				break;
		}
	}while(ch!=5);
	close(sd);
	return 0;
}
