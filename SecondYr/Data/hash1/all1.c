#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void insert(int[],int,int);
void display(int[],int);
int search(int[],int,int);
void delete(int[],int,int);

//#include"hash.h"
main()
{
int b[50];
int r=0,s,z,m,i=0,h,n=10,j,k;
printf("\nEnter no of elements ");
scanf("%d",&r);
while(i!=r)
{
b[i]=-1;
i++;
}
while(1)
{
printf("\n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \nEnter your choice:  ");
scanf("%d",&z);
switch(z)
{
case 1:
//roy:
//printf("Enter the no of elements to be inserted (maximum no of elements is 10) ");
//scanf("%d",&k);
//if(k<=10)
//{
for(i=0;i<r;i++)
{
printf("Enter %d element  ",i+1);
scanf("%d",&j);
insert(b,j,r);
}
printf("\nInsertion is done");
//}
//else
//printf("\nEnter no of elements below 10 \n");
//goto roy;
break;
case 2:
display(b,r);
break;
case 3:
printf("Enter search element : ");
scanf("%d",&m);
s=search(b,m,r);
if(s==1)
    printf("\nSearch element is present");
else
    printf("\nSearch element is not  present");
break;
case 4:
printf("\nEnter element to be deleted : ");
scanf("%d",&h);
delete(b,h,r);
break;
case 5:
exit(0);
}
}
}

//#include"hash.h"
void insert(int b[20],int j,int r)
{
int s=0,m=1;
s=j%10;
if(b[s]==-1)
b[s]=j;
else
loop:
s=j%r+m;
if(s>=r)
{
s=s%r;
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
void display(int b[20],int r)
{
int i;
for(i=0;i<r;i++)
{
printf(" %d block contains.....\t",i);
if(b[i]!=-1)
{
printf("%d",b[i]);
}
printf("\n");
}
}
int search(int b[20],int m,int r)
{
int t;
for(t=0;t<r;t++)
{
if(b[t]==m)
{
return 1;
}
}
return 0;
}
void delete(int b[20],int h,int r)
{
int i;
for(i=0;i<r;i++)
{
    if(b[i]==h)
     {
    b[i]=-1;
    printf("Element is deleted\n");
     }
}
display(b,r);
}

