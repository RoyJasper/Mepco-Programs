#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int d,a[2],n,p,b[20],i,sum=0;
int avg;
p=pipe(a);
d=fork();
if(d==-1)
{
printf("ERROR IN PROCESSOR CREATION");
exit(0);
}
else if(d==0)
{
close(a[0]);
printf("\nENTER THE SIZEOF THE ARRAY");
scanf("%d",&n);
write(a[1],&n,sizeof(n));
for(i=0;i<n;i++)
{         
printf("\nENTER THE ELEMENT");
scanf("%d",&b[i]);
}
for(i=0;i<n;i++)
write(a[1],&b[i],sizeof(b[i]));
}       
else      
{            
close(a[1]);
read(a[0],&n,sizeof(n));
printf("\n%d",n);
for(i=0;i<n;i++)
{   
read(a[0],&b[i],sizeof(b[i]));
printf("\n%d",b[i]);
sum=sum+b[i];
} 
avg=(sum/n);
printf("THE SUM IS %d",sum); 
printf("THE AVERAGE IS %d",avg);
}
return 0;
}

