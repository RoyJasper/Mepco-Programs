#include"hash.h"
#include<malloc.h>
#include<stdlib.h>
int main()
{
list a[10],head;
head=(list)malloc(sizeof(struct node));
head->next=NULL;
int l;
int i,s,r,t,n,y,f;
for(i=0;i<=10;i++)
{
a[i]=(list)malloc(sizeof(struct node));
a[i]->next=NULL;
}
printf("\n\n\n\t\tWELCOME TO HASHING\n");
while(1)
{
printf("\nenter your choice");
printf("\n1.insert \n2.search \n3.display \n4.delete \n5.exit");
scanf("%d",&y);
switch(y)
{
case 1:
printf("\nenter the number of numbers");
scanf("%d",&l);
for(i=0;i<l;i++)
{
printf("\nenter no");
scanf("%d",&n);
s=n%10;
insert(a[s],n);
printf("\ninserted");
}
break;
case 2:
printf("enter no");
scanf("%d",&f);
s=f%10;
r=search(a[s],f);
if(r==0)
printf("not present");
else
printf("present");
break;
case 3:
display(a);
break;
case 4:
printf("enter no");
scanf("%d",&r);
s=r%10;
deletion(a[s],r);
break;
case 5:
exit(0);
}
}
}

