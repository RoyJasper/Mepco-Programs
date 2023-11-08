#include<stdio.h>
#include<string.h>  
#include<sys/socket.h>
#include<arpa/inet.h>  
#include<unistd.h>  
#include<time.h>
int main()
{
   time_t t;
   char w[200];
   int socket_desc , client_sock , c , read_size;
   struct sockaddr_in server , client;
   char client_message[2000];
   
   int count=0,i;
   socket_desc = socket(AF_INET , SOCK_STREAM , 0);
   if (socket_desc == -1)
   {
       printf("Could not create socket");
   }
   puts("Socket created");

   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons( 3333 );


   if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
   {
       
       printf("bind failed. Error");
       return 1;
   }
   puts("bind done");

  
   listen(socket_desc , 3);

   
   puts("Waiting for incoming connections...");
   c = sizeof(struct sockaddr_in);

   
   client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
   if (client_sock < 0)
   {
       printf("accept failed");
       return 1;
   }
   puts("Connection accepted"); 
   while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
   {
       //Send the message back to client
       *(client_message + read_size) = '\0';
      
     
     if(strcmp(client_message,"time")==0)
    {
     time(&t);
    snprintf(w,sizeof(w),"%s",ctime(&t));
    write(client_sock,w,strlen(w));
   }
}
   if(read_size == 0)
   {
       puts("Client disconnected");
       fflush(stdout);
   }
   else if(read_size == -1)
   {
       printf("recv failed");
   }
   return 0;
}


