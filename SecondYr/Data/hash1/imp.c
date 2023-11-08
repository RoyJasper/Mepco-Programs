#include"hash.h"
void insert(int b[20],int j)
{
int s=0,m=1;
loop:
s=j%10+m;
if(s>=10)
{
s=s%10;
}
if(b[s]==-1)
{
b[s]=j;
//break;
}
else
{
m++;
goto loop;
}
}
void display(int b[20])
{
int i;
for(i=0;i<10;i++)
{
printf("%d------------------------>",i);
if(b[i]!=-1)
{
printf("%d",b[i]);
}
printf("\n");
}
}
int search(int b[20],int m)
{
int t;
for(t=0;t<10;t++)
{
if(b[t]==m)
{
return 1;
}}
return 0;
}
void delete(int b[20],int h)
{
int i;
for(i=0;i<10;i++)
{
    if(b[i]==h)
    {
        b[i]=-1;
    printf("ELEMENT IS DELETED SUCCESSFULLY\n");
}
}
display(b);
}

