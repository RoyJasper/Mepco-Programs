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
  serv.sin_port = htons(9999);
  serv.sin_addr.s_addr = htonl(INADDR_ANY);
  memset(serv.sin_zero, '\0', sizeof serv.sin_zero);  

  
    len = sizeof serv;

   
    printf("Type a sentence to send to server:\n");
    scanf("%s",str);
    printf("You typed: %s\n ",str);
    int n = strlen(str);
    for(i=0;i<n;i=i+2)
	{
	  ev[j]=str[i];
	  j++;
	  evc++;
	}
    ev[j]='\0';
    j=0;
    for(i=1;i<n;i=i+2)
	{
	  od[j]=str[i];
	  j++;
	  odc++;
	}
    od[j]='\0';
printf("\n\n%s\n\n",od);
printf("\n\n%s\n\n",ev); 

strcat(ev,"$");
strcat(ev,od);
  
printf("\n\n%s\n\n",ev);

    /*Send message to server*/
    sendto(cs,ev,100,0,(struct sockaddr *)&serv,len);
  
    /*Receive message from server*/
    recvfrom(cs,strs,100,0,NULL, NULL);
    printf("Received from server: %s\n",strs);
    if(strcmp(str,strs)==0)
    {
	printf("\n\n Messages are same !!");
    }
    else
    {
       printf("Wrong message");
    }    
  return 0;
}
