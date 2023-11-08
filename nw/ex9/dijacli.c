#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
nt main()
{
    int cs,st;
    struct sockaddr_in serv;
    socklen_t len;
    cs = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    len = sizeof serv;
    printf("Enter Starting Node :\n");
    scanf("%d",&st);
    sendto(cs,st,100,0,(struct sockaddr *)&serv,len);
    return 0;
}
