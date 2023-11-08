#include"set.h"
main()
{
set s;
int ch,e,f,n;
s=(set)malloc(sizeof(struct node));
printf("\n\n\tWELCOME TO SET OPERATION\n\n\n");
printf("\nENTER THE SIZE OF THE SET : ");
scanf("%d",&n);
do
{
printf("\nEnter your choice\n1.Makeset\n2.Unionset\n3.Findset\n4.Display");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
makeset(s,n);
break;
}
case 2:
{
unionset(s);
break;
}
case 3:
{
printf("\nEnter the element to search");
scanf("%d",&e);
//f=findset(e,s);
if(e>n)
printf("Not found");
else
printf("Element found");
break;
}
case 4:
{
//printf("\nElements are");
dis(s,n);
break;
}
}
}while(ch!=5);
}

