#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int sd,len,b,i,j;
    char a[100],c[20],d[20];
    struct sockaddr_in serv,cli;
    serv.sin_family=AF_INET;
    serv.sin_port=htons(8090);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    sd=socket(AF_INET,SOCK_DGRAM,0);
    len=sizeof(serv);
    bind(sd,(struct sockaddr *)&serv,len);
    recvfrom(sd,a,100,0,(struct sockaddr *)&serv,len);
    b=strlen(a);
    for(i=0; j=0; i<b,i++)
    {
        if(i%2==0)
        {
            c[j++]=a[i];
        }
        for(i=0; i<b; i++)
        {
            if(i%2==1)
                c[j++]=a[i];
        }
        c[j]='\0';
        printf("Encrypted text is",c);
        sendto(sd,c,100,0,(struct servaddr *)&cli,len);
    }
}
