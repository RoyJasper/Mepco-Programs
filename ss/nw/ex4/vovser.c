#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()alen
{
    int wsoc, soc;
    char str[20];
    struct sockaddr_in saddr;
    struct sockaddr_storage serv;
    socklen_t alen;


    wsoc = socket(PF_INET, SOCK_STREAM, 0);


    saddr.sin_family = AF_INET;

    saddr.sin_port = htons(8888);

    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(saddr.sin_zero, '\0', sizeof saddr.sin_zero);


    bind(wsoc, (struct sockaddr *) &saddr, sizeof(saddr));


    if(listen(wsoc,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");


    alen = sizeof serv;
    soc = accept(wsoc, (struct sockaddr *) &serv, &alen);


    recv(soc,str,100,0);
    int cou=0,i,n=strlen(str);
    for(i=0;i<n;i++)
    {
        if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u'))
            cou++;
    }
    printf(" \n No of vowels are %d ",cou);
    return 0;
}
