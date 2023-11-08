#include"header.h"
#include<math.h>
#include<stdlib.h>
 int main()
{
char un[100],ps[100];
int count=0,flag=1;
int b[100];
char bi[100];
char read[100];
int sd,c,m,i,j,n,k=0,x,p,size,no,ws,sno[100];
char fra[100];
struct sockaddr_in client,server;
server.sin_family=AF_INET;
printf("Enter the port number:");
scanf("%d",&p);
server.sin_port=htons(p);
server.sin_addr.s_addr=htonl(INADDR_ANY);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd>0)
printf("\nSocket created\n");
else
printf("\nSocket failed\n");
c=connect(sd,(struct sockaddr *)&server,sizeof(server));
if(c==0)
printf("\nConnected\n");
else
printf("\nConnection failed\n");
while(1)
{
printf("\nEnter user name:");
scanf("%s",un);
printf("Enter password:");
scanf("%s",ps);
send(sd,un,100,0);
send(sd,ps,100,0);
recv(sd,&flag,100,0);
if(flag==0)
{
printf("\nEnter the File");
scanf("%s",un);
printf("%s",un);
send(sd,un,100,0);
recv(sd,read,100,0);
printf("\n%s",read);
}
else
{
printf("Try again");
count++;
printf("\nCount is %d",count);
}
if(count==3)
goto aa;
}
aa:
printf("Over");
}
