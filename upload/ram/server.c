#include<stdio.h>
#include<math.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
main()
{
 int so,b;
 char mes[20];
  int i,j,k,l,len;
    char a[20],c[20],d[20];
  struct sockaddr_in sin;
 sin.sin_family=AF_INET;
 sin.sin_port=htons(6000);
 sin.sin_addr.s_addr=htonl(INADDR_ANY);
 so=socket(AF_INET,SOCK_DGRAM,0);
 if(so<0)
 printf("error in connection");
 else
 printf("connected");
 len=sizeof(sin);

 b=bind(so,(struct sockaddr*)&sin,sizeof(sin));
 recvfrom(so,&a,sizeof(mes),0,(struct sockaddr*)&sin,&l);
    l=strlen(a);
   
  for(i=0,j=0;i<l;i++)
    {
        if(i%2==0)
        c[j++]=a[i];
    }
    for(i=0;i<l;i++)
    {
        if(i%2==1)
        c[j++]=a[i];
    }
    c[j]='\0';
    printf("\nCipher text after applying rail fence :");
    printf("\n%s",c);
len=sizeof(sin);
  sendto(so,&c,20,0,(struct sockaddr*)&sin,sizeof(sin));
 close(so);
}


