#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void insert(int[],int);
void display(int[]);
int search(int[],int);
void delete(int[],int);

//#include"hash.h"
main()
{
int b[30];
int s,z,m,i=0,h,n=10,j,k;
while(i!=10)
{
b[i]=-1;
i++;
}
do
{
printf("\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \nEnter your choice:  ");
scanf("%d",&z);
switch(z)
{
case 1:
roy:
printf("Enter the no of elements to be inserted (maximum no of elements is 10) ");
scanf("%d",&k);
if(k<=10)
{
for(i=0;i<k;i++)
{
printf("Enter %d element  ",i+1);
scanf("%d",&j);
insert(b,j);
}
printf("\nInsertion is done");
}
else
{
printf("\nEnter no of elements below 10 \n");
goto roy;
}
break;
case 2:
display(b);
break;
case 3:
printf("Enter search element : ");
scanf("%d",&m);
s=search(b,m);
if(s==1)
    printf("\nSearch element is present");
else
    printf("\nSearch element is not  present");
break;
case 4:
printf("\nEnter element to be deleted : ");
scanf("%d",&h);
delete(b,h);
break;
case 5:
exit(0);
}
}while(1);
}

//#include"hash.h"
void insert(int b[20],int j)
{
int s=0,m=1;
s=j%10;
if(b[s]==-1)
b[s]=j;
else
{
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
}
void display(int b[20])
{
int i;
for(i=0;i<10;i++)
{
printf(" %d block contains.....\t",i);
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
}
}
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
    printf("Element is deleted\n");
     }
}
display(b);
}


