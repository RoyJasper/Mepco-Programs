#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int soc,i,j=0,odc=0,evc=0,n ;
  char str[20],nstr[20],od[20],ev[20];
  struct sockaddr_in serv, cli;
  struct sockaddr_storage store;
  socklen_t len, clen;

  soc = socket(PF_INET, SOCK_DGRAM, 0);  
  serv.sin_family = AF_INET;
  serv.sin_port = htons(9999);
  serv.sin_addr.s_addr = htonl(INADDR_ANY);
  
  bind(soc, (struct sockaddr *) &serv, sizeof(serv));

  len = sizeof store;
   
   recvfrom(soc,str,100,0,(struct sockaddr *)&store, &len);
   printf("\n\n%s\n\n",str);
   n=strlen(str);
   for(i=0;str[i]!='$';i++)
   {
     ev[j]=str[i];
     j++;evc++;
   }
   ev[j]='\0';
   int k=0;
	   for(i=j+1;i<n;i++)
   {
     od[k]=str[i];
     k++;odc++;
   }
   od[k]='\0';
   printf("\n\n%s\n\n",od);
   printf("\n\n%s\n\n",ev); 
	j=0;
	for(i=0;i<n;i=i+2) 
	{
		nstr[i]=ev[j];
		j++;
	}
	j=0;
	for(i=1;i<n;i=i+2) 
	{
		nstr[i]=od[j];
		j++;
	}
	 printf("\n\n%s\n\n",nstr); 
   sendto(soc,nstr,100,0,(struct sockaddr *)&store,len);

  return 0;
}
