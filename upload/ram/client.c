#include<stdio.h>
#include<math.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
main()
{
 int so;
 char mes[20];
 struct sockaddr_in sin;
 sin.sin_family=AF_INET;
 sin.sin_port=htons(6000);
 sin.sin_addr.s_addr=htonl(INADDR_ANY);
 so=socket(AF_INET,SOCK_DGRAM,0);
 if(so<0)
 printf("error in connection");
 else
 printf("connected");
    int i,j,k,l;
    char a[20],c[20],d[20];
    printf("\nEnter the input string : ");
    scanf("%s",a);
    l=strlen(a);
     sendto(so,&a,sizeof(mes),0,(struct sockaddr*)&sin,sizeof(sin));
     
       recvfrom(so,&c,20,0,(struct sockaddr*)&sin,sizeof(sin));
     printf("the cipered text is:%s",c);
    if(l%2==0)
        k=l/2;
    else
        k=(l/2)+1;
    for(i=0,j=0;i<k;i++)
    {
        d[j]=c[i];
        j=j+2;
    }
    for(i=k,j=1;i<l;i++)
    {

     d[j]=c[i];
        j=j+2;
    }
    d[l]='\0';
    printf("\nText after decryption : ");
    printf("%s",d);
      close(so);
}


