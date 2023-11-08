#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<netdb.h>

#include<errno.h>

#include<signal.h>

#include<unistd.h>

#include<arpa/inet.h>

#include<string.h>

#include<sys/wait.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<math.h>

void timer();

void endt();

main()

{

char a[100][100],f1[100],nk[100];

int y,k,j,i,sf,sw,l,l1,f,q,j1;

int c,s,sn,cou=0,o,n,r,w,ws,m,se[100],n1,pp;

struct sockaddr_in server,client;

server .sin_family=AF_INET;

printf("enter the port number");

scanf("%d",&f);

server.sin_port=htons(f);

server.sin_addr.s_addr=htonl(INADDR_ANY);

s=socket(AF_INET,SOCK_STREAM,0);

if(s>0)

printf("\n socket is successfull");

else

printf("\n socket not success");

c=connect(s,(struct sockaddr *)&server,sizeof(server));

if(c==0)

printf("\n connected ");

else

printf("\nnot connected");


scanf("%d",&n);

send(s,&n,100,0);

printf("enter the frame size");

scanf("%d",&f);

send(s,&f,100,0);

printf("enter the frame to send");

for(i=0;i<f;i++)

{

for(j=0;j<n;j++)

{

scanf(" %c",&a[i][j]);

}

}

j=0;

j1=0;

for(i=0;i<f;i++)

{

while(j!=n)

{

f1[j1]=a[i][j];

j1++;

j++;

}

j=0;

}

strcpy(nk,"00");

for(i=0;i<j1;i++)

{

if(f1[i]=='0')

strcat(nk,"01");

else

strcat(nk,"10");

}

strcat(nk,"11");

send(s,nk,100,0);

send(s,&j1,100,0);

printf("window size");

scanf("%d",&m);

k=m-1;

w=pow(2,k);

send(s,&w,100,0);

c=0;

for(i=0;i<f;i++)

{

se[i]=c;

c++;

if(c==w+1)

c=0;

}

k=i;

printf("%d",k);

send(s,&k,100,0);

for(i=0;i<k;i++)

{

timer();

send(s,&se[i],100,0);

recv(s,&pp,2,0);

printf("\nacknow for %dth frame",pp);

endt();

}

printf("to generate negack press 1");

scanf("%d",&q);

r=rand()%f;

n1=rand()%n;

printf("\n%d%d",r,n1);

if(a[r][n1]=='1')

a[r][n1]='0';

else

a[r][n1]='1';

printf("the sequence is");

for(i=0;i<f;i++)

{

for(j=0;j<n;j++)

{

printf(" %c",a[i][j]);

}

}

}

void timer()

{

time_t start;

start=clock();

}

void endt()

{

time_t end;

end=clock();

}
