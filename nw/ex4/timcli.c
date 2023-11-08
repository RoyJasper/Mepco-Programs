#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void client()
{
    int sid,conn,nsend,nrecv,nclose;
    char smsg[50],rmsg[50];
    struct sockaddr_in server;
    sid=socket(AF_INET,SOCK_STREAM,0);
    if(sid==-1)
    {
        printf("\nSocket failure\n");
    }
    else
    {
        server.sin_addr.s_addr = htonl(INADDR_ANY);
        server.sin_family = AF_INET;
        server.sin_port = htons(1478);
        conn=connect(sid,(struct sockaddr *)&server,sizeof(server));
        if(conn==-1)
            printf("Connection Problem\n");
        else
        {
            printf("\nConnected\n");
            while(strcmp(rmsg,"exit")!=0)
            {
                strcpy(smsg,"");
                strcpy(rmsg,"");
                printf("\n>>");
                scanf("%[^\n]",smsg);
                nsend=send(sid,smsg,strlen(smsg),0);
                if(nsend==-1)
                {
                    printf("\nMessage Send Failed\n");
                }
                else
                {
                    nrecv=recv(sid,rmsg,2000,0);
                    if(nrecv==-1)
                    {
                        printf("\nReceive failed\n");
                    }
                    else
                    {
                        printf("\n>>");
                        printf("%s\n",rmsg);
                    }
                }
            }
        }
    }
    close(sid);
}
main()
{
    client();
}
