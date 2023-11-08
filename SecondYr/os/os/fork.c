#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int a[2],b[2],c[2],p1,p2,p3,d,e,n,s=0,l,m=1;
p1=pipe(a);
p2=pipe(b);
p3=pipe(c);
d=fork();
e=fork();
if((d<0)&&(e<0))
{
printf("Processor creation is unsucessfully");
exit(0);
}
else
{
if((m>0)&&(d>0))
{
printf("ENTER THE NUMBER");
scanf("%d",&n);
close(a[0]);
write(a[1],&n,sizeof (n));
}
if((d==0)&&(m>0))
{
close(a[1]);
read(a[0],&n,sizeof(n));
if(n%2==0)
{
printf("\nEVEN");
while(n!=0)
{
l=n%10;
n=n/10;
s=s+l;
}
printf("THE SUM OF DIGITS IS %d",s);
close(b[0]);
write(b[1],&n,sizeof (n));
}
else
{
printf("\nODD");
close(c[0]);
while(n!=0)
{
l=n%10;
n=n/10;
m=m*l;
}
printf("THE MULTIPLY OF DIGITS IS %d",m);
write(c[1],&n,sizeof (n));
}
}
if((m==0)&&(d>0))
{
close(b[1]);
read(b[0],&n,sizeof (n));
while(n!=0)
{
l=n%10;
n=n/10;
m=m*l;
}
printf("THE MULTIPLY OF DIGITS IS %d",m);
}
if((m==0)&&(d==0))
{
close(c[1]);
read(c[0],&n,sizeof (n));
while(n!=0)
{
l=n%10;
n=n/10;
s=s+l;
}
printf("THE SUM OF DIGITS IS %d",s);
}
}
return 0;
}


