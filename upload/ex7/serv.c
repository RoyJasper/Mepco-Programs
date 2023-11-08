#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
void main()
{
FILE * fp;
struct sockaddr_in server;
server.sin_family=PF_inet;

