#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int d,a[2],n,p;
p=pipe(a);
d=fork();
if(d==-1)
{
printf("ERROR IN PROCESSOR CREATION");
exit(0);
}
else if(d==0)
{
printf("ENTER TH NUMBER");
scanf("%d",&n);
close(a[0]);
write(a[1],&n,sizeof(n));
}
else
{
close(a[1]);
read(a[0],&n,sizeof(n));
if(n%2==0)
printf("%d IS EVEN",n);
else
printf("%d IS ODD",n);
return 0;
}}
