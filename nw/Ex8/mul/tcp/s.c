#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
struct sockaddr_in server,client1,client2,client3;
char mmsg[20];
int doit(int ss);
void main()
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
    printf("\n Enter Message to send to all Clients  :  ");
    scanf("%s",mmsg);
    printf("\nMsg is %s \n",mmsg);
    printf("\nEnter 1 to send ");
    scanf("%d",&n);
    if(n==1)
    for(i=0; i<3; i++)
    {

        n=doit(sd);

    }
    close(sd);
}

int doit(int sd)
{
    static int i=0;
    char ss[50],s1[40],s2[50];
   // for(i=0; i<3; i++)
    {
        if(i==0)
        {
            int dd=sizeof(client1);
            sendto(sd,mmsg,sizeof(mmsg),0,(struct sockaddr*)&client1,sizeof(client1));
            printf("\nmsg Sent  to C1\n");
        }
        if(i==1)
        {
            int dd=sizeof(client2);
            sendto(sd,mmsg,sizeof(mmsg),0,(struct sockaddr*)&client2,sizeof(client2));
            printf("\nmsg Sent  to C2\n");
        }
        if(i==2)
        {
            int dd=sizeof(client3);
            sendto(sd,mmsg,sizeof(mmsg),0,(struct sockaddr*)&client3,sizeof(client3));
            printf("\nmsg Sent  to C3\n");
        }
    }
    i++;
    return 0;

}
