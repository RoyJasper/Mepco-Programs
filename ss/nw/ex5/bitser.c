#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int soc,i,j=0,odc=0,evc=0,n ;
    char str[20],nstr[20],od[20],ev[20];
    struct sockaddr_in serv, cli;
    struct sockaddr_storage store;
    socklen_t len, clen;

    soc = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(soc, (struct sockaddr *) &serv, sizeof(serv));

    len = sizeof store;

    recvfrom(soc,str,100,0,(struct sockaddr *)&store, &len);
    printf("\n\n%s\n\n",str);
    n=strlen(str);
     printf("\nMEssage is \n");
    for(i=2; i<n-2;i=i+2)
    {
        if(str[i]=='0'&&str[i+1]=='1')
        {
            printf("0");
        }
        else
        printf("1");
    }
    return 0;
}
