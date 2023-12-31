#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int udpSocket, nBytes;
    char buffer[1024];
    struct sockaddr_in serv, clie;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
    int i;


    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_port = htons(7891);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    //memset(serv.sin_zero, '\0', sizeof serv.sin_zero);

    bind(udpSocket, (struct sockaddr *) &serv, sizeof(serv));

    addr_size = sizeof serverStorage;

    while(1)
    {
        nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);

        for(i=0; i<nBytes-1; i++)
            buffer[i] = toupper(buffer[i]);

        sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
    }

    return 0;
}
