#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int l,m;
l=fork();
m=fork();
if((l<0)&&(m<0))
{
printf("\nThe Processor ID creation is unsucessfully");
exit(0);
}
else
{
if(l>0)
{
printf("\nThe Processor B is being Working");
exit(0);
}
else if(l==0)
{
printf("\nThe Processor C is being Working");
exit(0);
}
else if((l>0)&&(m==0))
{
printf("\nThe Processor D is being Working");
exit(0);
}
else if((l==0)&&(m==0))
{
printf("\nThe Processor A is being Working");
exit(0);
}
else
return 0;
}
}
