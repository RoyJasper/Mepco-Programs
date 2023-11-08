#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int clientSocket, portNum, nBytes;
    char buffer[1024];
    struct sockaddr_in serv;
    socklen_t addr_size;

    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_port = htons(7891);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(serv.sin_zero, '\0', sizeof serv.sin_zero);

    addr_size = sizeof serv;

    while(1)
    {
        printf("Type a sentence to send to server:\n");
        fgets(buffer,1024,stdin);
        printf("You typed: %s",buffer);
        nBytes = strlen(buffer) + 1;
        sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serv,addr_size);
        nBytes = recvfrom(clientSocket,buffer,1024,0,NULL, NULL);
        printf("Received from server: %s\n",buffer);
    }
    return 0;
}
