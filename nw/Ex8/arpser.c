#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int soc,i,j=0,odc=0,evc=0,n ;
    char nstr[20],od[20],ev[20];
    struct sockaddr_in serv, cli;
    struct sockaddr_storage store;
    socklen_t len, clen;

    FILE *fp;
    char str[20],mas,ip[60],hw[60],f[60],hwa[60],dev[60],ch;
    soc = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(1789);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(soc, (struct sockaddr *) &serv, sizeof(serv));

    len = sizeof store;

    recvfrom(soc,str,100,0,(struct sockaddr *)&store, &len);
    printf("\n IP is : %s",str);

    fp=fopen("/proc/net/arp","r");
    if(fp==-1)
        printf("Error file" );
    fscanf(fp,"%s %s %s %s %s %s %s %s %s",ip,hw,f,hwa,mas,dev,ip,hw,hwa);
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %c %s",ip,hw,f,hwa,&mas,dev);
        if(strcmp(str,ip)==0)
        {
            printf("Mac is : %s",hwa);
        }
    }
    fclose(fp);
    return 0;
}
