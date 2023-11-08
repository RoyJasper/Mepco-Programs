#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{
	int sd,b,ad,lac,l,len,f,c=0,i=0,j,n;
	char msg[100],msg1[100],msg2[100],users[100],pass[100],string[100][100],d;
	FILE *fp,*fp1;
	struct sockaddr_in server,client;
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
	recv(ad,msg1,100,0);
	recv(ad,msg2,100,0);
	fp=fopen("user.c","r");
	while(i!=2)
	{
		fscanf(fp,"%s",users);
		fscanf(fp,"%s",pass);
		if(strcmp(users,msg)==0 && strcmp(pass,msg1)==0)
		{
			c=1;
			printf("hai");
			break;
		}
		i++;
	}
	i=0;
	if(c==1)
	{
		fp1=fopen(msg2,"r");
		i=0;
		//fscanf(fp1,"%s",users);
		while(i!=4)
		{
			strcpy(string[i],users);
			i++;			
			fscanf(fp1,"%s",users);
		}
		n=i;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(strcmp(string[i],string[j])>0)
				{
					strcpy(pass,string[i]);
					strcpy(string[i],string[j]);
					strcpy(string[j],pass);
				}
			}
		}
		fclose(fp1);
		fp1=fopen(msg2,"w");
		for(j=0;j<n;j++)
		{
			fprintf(fp1,"%s",string[j]);
			putc(' ',fp1);
		}
		fclose(fp1);
		send(ad,msg2,100,0);
	}
	else
	{
		send(ad,msg2,100,0);
	}
	send(ad,msg,100,0);
	close(sd);
return 0;
}

