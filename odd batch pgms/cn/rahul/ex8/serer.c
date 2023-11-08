#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,lac,l,len,f,check,i,flag;
	char msg[100];
	char ch,line[100],line1[100],line2[100],line3[100],line4[100],line5[100],line6[1000];
	struct sockaddr_in server,client;
	char *t="/proc/net/arp";
	FILE *fp;
 	fp=fopen(t,"r");
	server.sin_family=AF_INET;
	printf("ENTER THE PORT NUMBER");
	scanf("%d",&f);
	server.sin_port=htons(f);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd>=0)
		printf("SOCKET SUCCESS");
	else
		printf("ERROR");
	b=bind(sd,(struct sockaddr *) &server,sizeof(server));
	if(b>=0)
		printf("BIND SUCCESS");
	else
		printf("BIND ERROR");
	l=listen(sd,5);
	if(l>=0)
		printf("LISTEN SUCCESS");
	len=sizeof(client);
	ad=accept(sd,(struct sockaddr *) &client,&len);
	if(ad>=0)
		printf("ACCEPT SUCCESS");
	recv(ad,msg,100,0);
	printf("\nThe message is %s",msg);
	for(i=0;i<9;i++)
	{
		fscanf(fp,"%s",line);
	}
	check=fscanf(fp,"%s%s%s%s%s%s",line,line1,line2,line3,line4,line5);
	//printf("%d",check);
	while(check>0)
	{
		if(strcmp(msg,line3)==0)
		{
  			flag=1; 
  			break;
		}
  		check=fscanf(fp,"%s%s%s%s%s%s",line,line1,line2,line3,line4,line5);
	//	printf("%s",line);
	}
	//printf("%s",line);
 	send(ad,line,100,0);
 	close(sd);
 	return 0;
}
