#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int cs, pno;
    char mac[60],ip[60];
    struct sockaddr_in serv;
    socklen_t len;
    cs = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(1789);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(serv.sin_zero, '\0', sizeof serv.sin_zero);
    len = sizeof serv;
    printf("Type a IP :\n");
    scanf("%s",ip);

    sendto(cs,ip,100,0,(struct sockaddr *)&serv,len);
    recvfrom(cs,mac,100,0,(struct sockaddr *)&serv, &len);
    return 0;
}
