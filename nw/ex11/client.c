#include"header.h"
int main(void){
	int sd,len,ch;
	char msg[100],hname[20];
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_addr.s_addr=htonl(INADDR_ANY);
	ser.sin_port=htons(8980);
	sd=socket(AF_INET,SOCK_DGRAM,0);
	len=sizeof(ser);
	do{
		printf("\n1]gethostbyname\n2]gethostbyaddress\n3]getservbyname\n4]getsservbyport\n5]Exit\n\nEnter your choice:");
		scanf("%d",&ch);
		sendto(sd,&ch,sizeof(ch),0,&ser,sizeof(ser));
		switch(ch){
			case 1:printf("\nEnter the host name:");
				scanf("%s",hname);
				sendto(sd,hname,sizeof(hname),0,&ser,sizeof(ser));
				recvfrom(sd,msg,sizeof(msg),0,NULL,NULL);
				printf("Addresses are:\n");
				while(strcmp(msg,"Empty")!=0){
					printf("%s\n",msg);
					recvfrom(sd,msg,sizeof(msg),0,NULL,NULL);
				}
				break;
			case 2:printf("\nEnter the address:");
				scanf("%s",msg);
				sendto(sd,msg,sizeof(msg),0,&ser,sizeof(ser));
				recvfrom(sd,hname,sizeof(hname),0,NULL,NULL);
				printf("The Host Name is %s",hname);
				break;
			case 3:printf("\nEnter servname and prototype:");
				scanf("%s %s",hname,msg);
				sendto(sd,hname,sizeof(hname),0,&ser,sizeof(ser));
				sendto(sd,msg,sizeof(msg),0,&ser,sizeof(ser));
				recvfrom(sd,&len,sizeof(len),0,NULL,NULL);
				printf("The corresponding port no is %d",len);
				break;
			case 4:printf("\nEnter the port number and prototype:");
				scanf("%d %s",&len,msg);
				sendto(sd,&len,sizeof(len),0,&ser,sizeof(ser));
				sendto(sd,msg,sizeof(msg),0,&ser,sizeof(ser));
				recvfrom(sd,hname,sizeof(hname),0,NULL,NULL);
				printf("The corresponding servname is %s",hname);
				break;
		}
	}while(ch!=5);
	close(sd);
	return 0;
}
