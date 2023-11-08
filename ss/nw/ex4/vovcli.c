#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int cs;
    char str[20];
    struct sockaddr_in saddr;
    socklen_t alen;

    cs = socket(PF_INET, SOCK_STREAM, 0);


    saddr.sin_family = AF_INET;

    saddr.sin_port = htons(8888);

    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(saddr.sin_zero, '\0', sizeof saddr.sin_zero);


    alen = sizeof saddr;
    connect(cs, (struct sockaddr *) &saddr, alen);

    printf("\n Enter string : ");
    scanf("%s",str);
    send(cs,str,100,0);
    close(cs);
    return 0;
}
