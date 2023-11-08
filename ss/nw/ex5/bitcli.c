#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int cs, pno, byt,j=0,i,evc=0,odc=0;
    char str[20],strs[20],od[20],ev[20],fin[20],tstr[20];
    struct sockaddr_in serv;
    socklen_t len;
    cs = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(serv.sin_zero, '\0', sizeof serv.sin_zero);
    len = sizeof serv;
    printf("Type a bit sequence to send to server:\n");
    scanf("%s",str);
    printf("You typed: %s\n ",str);
    int n = strlen(str);
    strs[0]='0';
    strs[1]='0';

    j=2;
    for(i=0; i<n; i++)
    {
        if(str[i]=='0')
        {
            strs[j]='0';
            strs[j+1]='1';
        }
        else
        {
            strs[j]='1';
            strs[j+1]='0';
        }
        j+=2;
    }
    strcat(strs,"11");
    printf("%d\n",strlen(strs));
    printf("\n Sending string is %s \n ",strs);
    sendto(cs,strs,100,0,(struct sockaddr *)&serv,len);
    return 0;
}
