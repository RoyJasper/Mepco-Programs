#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
main()
{
        int sd,i;
        socklen_t l;
        char *msg,ch;
        msg=malloc(sizeof(char)*100);
        struct sockaddr_in ser;
        ser.sin_port=htons(4400);
        ser.sin_family=AF_INET;
        sd=socket(AF_INET,SOCK_DGRAM,0);
        if(sd>0)
                printf("Socket is  created");
        printf("Enter the message:\n");
  /*scanf("%c",&ch);
        i=0;
        while(ch!='`')
        {
                msg[i]=ch;
                scanf("%c",&ch);
                i++;
        }msg[i]='\0';*/
        scanf("%s",msg);
        l=sizeof(ser);
        sendto(sd,msg,strlen(msg),0,(struct sockaddr*)&ser,l);
        recvfrom(sd,msg,strlen(msg),0,(struct sockaddr*)&ser,&l);
        printf("Encrypted Data is: %s",msg);


}

