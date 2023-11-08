#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
struct sockaddr_in server,client1,client2,client3;
int doit(int ss);
main()
{
 int f=0,sd,b,pid,bn;
char s2[100],s1[40];
sd=socket(AF_INET,SOCK_DGRAM,0);
server.sin_family=AF_INET;
printf("enter the port number:");
scanf("%d",&bn);
server.sin_port=htons(bn);
int cc=0;
server.sin_addr.s_addr=htonl(INADDR_ANY);
b=bind(sd,(struct sockaddr*)&server,sizeof(server));
if(b==0)
printf("\nbinding successful");
int n,i;
for(i=0;i<3;i++){
if((pid=fork())<0)
{
printf("\nchild creation not created");
}
else if(pid==0)
{
printf("\nchild process created");
n=doit(sd);
}
else
break;
}
close(sd);
}

int doit(int sd)
{
int i;
char s3[50],s1[40],s2[50];
for(i=0;i<3;i++)
{
if(i==0)
{
int dd=sizeof(client1);
recvfrom(sd,s1,sizeof(s1),0,(struct sockaddr *)&client1,&dd);
printf("%s\n",s1);
sendto(sd,s1,sizeof(s1),0,(struct sockaddr*)&client1,sizeof(client1));
}
if(i==1)
{
int dd=sizeof(client2);
recvfrom(sd,s2,sizeof(s2),0,(struct sockaddr *)&client2,&dd);
printf("%s\n",s2);
sendto(sd,s2,sizeof(s2),0,(struct sockaddr*)&client2,sizeof(client2));
}
if(i==2)
{
int dd=sizeof(client3);
recvfrom(sd,s3,sizeof(s3),0,(struct sockaddr *)&client3,&dd);
printf("%s\n",s3);
sendto(sd,s3,sizeof(s3),0,(struct sockaddr*)&client3,sizeof(client3));
printf("msg sended %s\n",s3);
}
}
return 0;
}

