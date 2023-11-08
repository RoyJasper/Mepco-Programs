#include"header.h"
int main()
{
FILE *fp1,*fp2;
char data[100],inp2[100],inp3[100],inp4[100],inp5[100],read[100],str[100];
char un[100],ps[100],c;
int flag=1;
char x,abc[100];
int sd,b,l,len,ac,n,ws,no,size,p,i=0,j;
struct sockaddr_in server,client;
server.sin_family=AF_INET;
printf("enter the port number:");
scanf("%d",&p);
server.sin_port=htons(p);
server.sin_addr.s_addr=htonl(INADDR_ANY);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd>0)
printf("\nSocket created\n");
else
printf("\n Socket failed");
b=bind(sd,(struct sockaddr *)&server,sizeof(server));
if(b==0)
printf("\nBind successful\n");
else
printf ("\n Bind failed\n");
l=listen(sd,3);
if(l==0)
printf("\nListen successful\n");
else
printf("\nListen failed\n");
len=sizeof(client);
ac=accept(sd,(struct sockaddr *)&client,&len);
if(ac>0)
printf("\nAccepted\n");
else
printf("\n Accept failed\n");
while(1)
{
recv(ac,un,100,0);
recv(ac,ps,100,0);
fp1=fopen("log.txt","r");
while(!feof(fp1))
{
fscanf(fp1,"%s",data);
if(strcmp(un,data)==0)
{
fscanf(fp1,"%s",data);
if(strcmp(data,ps)==0)
{
flag=0;
break;
}
}
}
fclose(fp1);
send(ac,&flag,100,0);
if(flag==0)
{
recv(ac,abc,1000,0);
printf("%s",abc);
fp2=fopen(abc,"r+");
x=fgetc(fp2);
while(x!=EOF)
{
if(x==' ')
{
fseek(fp2,-1,SEEK_CUR);
fprintf(fp2,",");
}
printf(" %c",x);
x=fgetc(fp2);
}
strcpy(abc,"OPERATIONDONE");
send(ac,abc,1000,0);
}
else
{
strcpy(abc,"LOGINFAILED");
send(ac,abc,1000,0);
}
}}
