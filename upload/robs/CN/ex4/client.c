#include<stdio.h>
#include<stdlib.h>
#include<socket.h>
main()
{
	int n,sid;
	struct sock_addr maddr;
	sid=socket(AF_INET,sock_STREAM,0);
	maddr.sin_family=AF_INET;
}

