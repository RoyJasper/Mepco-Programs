#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int sd,len,b,i,j,k,cn;
    char a[100],d[20],c[20];
    struct sockaddr_in serv,cli;
    serv.sin_family=AF_INET;
    serv.sin_port=htons(8090);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    sd=socket(AF_INET,SOCK_DGRAM,0);
    len=sizeof(serv);
    if(sd>0)
    {
        printf("Socket is created");
    }
    else
        printf("socket not created");
    cn=connect(sd,(struct sockaddr*)&serv,sizeof(serv));
    if(cn==0)
    {
        printf("\nEnter the message");
        scanf("%s",a);
        sendto(sd,a,100,0,(struct sockaddr *)&serv,len);
        recvfrom(sd,c,100,0,(struct sockaddr *)&cli,len);
        b=strlen(c);
        if(b%2==0)
        {
            k=(b/2);
        }
        else
            k=(b/2)+1;
        for(i=0; j=0; i<k,i++)
        {
            d[j]=c[i];
            j=j+2;
        }
        d[b]='\0';
        printf("The decrypted value is",d);
    }
}
