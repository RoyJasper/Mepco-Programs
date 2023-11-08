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
#include<math.h>
int main()
{
    char msg[100],m[100],ss[100],nk[100],nk1[100];
    time_t t;
    int f,o,j;
    int sd,b,l,a,len,n1,z,n,c,i,k,se[100],se1[100];
    int res,winsize,s,sk,w,q,r,ki;
    struct sockaddr_in server,client;
    server.sin_family=AF_INET;
    printf("enter the port number");
    scanf("%d",&k);
    server.sin_port=htons(k);
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    sd=socket(AF_INET,SOCK_STREAM,0);

    b=bind(sd,(struct sockaddr *)&server,sizeof(server));
    if(b==0)
        printf("bind was successful");
    else
        printf("bind unsuccssful");
    l=listen(sd,3);
    if(l==0)
        printf("listen successful\n");
    else
        printf("listen unsuccessful\n");
    len=sizeof(client);
    a=accept(sd,(struct sockaddr *)&client,&len);
    if(a>0)
        printf("Accepted.... \n");
    else
        printf("accept unsuccessful\n");
    recv(a,&n,100,0);
    recv(a,&f,100,0);
    recv(a,nk,100,0);
    printf("%s",nk);
    recv(a,&ki,100,0);
    printf("\n%d",ki);
    recv(a,&w,100,0);
    winsize=f;
//printf("\n winsize %d",winsize);
    c=0;
    for(i=0; i<winsize; i++)
    {
        se1[i]=c;
//printf("seq no new \n %d",se1[i]);
        c++;
        if(c==w+1)
            c=0;
    }
    recv(a,&k,100,0);

    o=k;
//printf("%d",o);
    i=0;
    while(i!=k)
    {
        recv(a,&se[i],100,0);
//printf("%d\n",se[i]);
        send(a,&i,2,0);
        i++;
    }

    int v;
    for(i=0; i<winsize; i++)
    {
        if(se[i]==se1[i])
            v=1;
        else
            v=0;
    }
    k=(ki*2)+4;
    j=0;
    if(v==1)
    {
        printf("\nNo error");
        printf("\nThe original message is : ");
        for(i=2; i<k-2; i++)
        {
            if(nk[i]=='0')
            {
                printf("%d",0);
                i=i+1;
            }
            else
            {
                printf("%d",1);
                i=i+1;
            }
        }
    }
    else
        printf("error");
}
