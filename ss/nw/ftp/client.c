#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int cs,port;
    char str[20],u[20],p[20],fil[20];
    struct sockaddr_in saddr;
    socklen_t alen;
    printf("\n Enter port : ");
    scanf("%d",&port);
    cs = socket(PF_INET, SOCK_STREAM, 0);


    saddr.sin_family = AF_INET;

    saddr.sin_port = htons(port);

    // saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(saddr.sin_zero, '\0', sizeof saddr.sin_zero);


    alen = sizeof saddr;
    connect(cs, (struct sockaddr *) &saddr, alen);

    printf("\n Enter Username  : ");
    scanf("%s",u);
    printf("\n Enter Password  : ");
    scanf("%s",p);
    printf("\n Enter File name  : ");
    scanf("%s",fil);
    send(cs,u,100,0);
    send(cs,p,100,0);
    send(cs,fil,100,0);
    while(recv(cs,str,100,0)>0)
    {
        if(strcmp("Retry",str)==0)
        {
            printf("\n Error in Authorisation Retry.... \n Enter USername :  ");
            scanf("%s",u);
            printf("\n Enter Password  : ");
            scanf("%s",p);
            send(cs,u,100,0);
            send(cs,p,100,0);
            send(cs,fil,100,0);
        }
        if(strcmp("Failure",str)==0)
        {
            printf("\n TOTAL FAILL ");
            return(1);
        }
    }
}
