#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<time.h>
int main()
{
    int sid,accpt,b=1,r,len;
    char *data,buf[200];
    struct sockaddr_in sin;
    time_t ti;
    struct tm *t;
    data=(char *)malloc(200*sizeof(char));
    //strcpy(data,"hi");
    sid=socket(AF_INET,SOCK_STREAM,0);
    if(sid==-1)
        printf("\n\nSocket failure\n\n");
    else
    {
        sin.sin_family = AF_INET;
        sin.sin_port = htons(1478);
        sin.sin_addr.s_addr = htonl(INADDR_ANY);
        while(b!=0)
            b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
        if(b==0)
        {
            printf("\n\nBinded\n\n");
            len=sizeof(struct sockaddr_in);
            listen(sid,10);
            accpt = accept(sid,(struct sockaddr *)&sin,&len);
           // if(accept==-1)                                                                                                                                                                                          pt==-1)
              //  printf("Connection not Accepted");
            //else
               // printf("\nConnection Accepted\n");
            while(strcmp(data,"exit")!=0)
            {
                r=recv(accpt,data,50,0);
                time(&ti);
                t=localtime(&ti);
                if(r==-1)
                    printf("\n\nData Received Failed\n\n");
                else
                {
                    if(strcmp(data,"send date")==0)
                    {
                        sprintf(buf,"%d %d %d",t->tm_mday,t->tm_mon,t->tm_year+1900);
                        send(accpt,buf,strlen(buf),0);
                    }
                    else if(strcmp(data,"send time")==0)
                    {
                        sprintf(buf,"%d : %d : %d",t->tm_hour,t->tm_min,t->tm_sec);
                        send(accpt,buf,strlen(buf),0);
                    }
                    }
                 //   else
                    {
                   //     exit(0);
                    }
                }
                //printf("tell");
            }
            close(sid);
        }
        //else
          //  printf("\n\nBinding Failed\n\n");
    }


