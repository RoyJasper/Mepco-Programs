//#include"setimp.c"
main()
{
set s;
int ch,e,f,n;
s=(set)malloc(sizeof(struct node));
do
{
printf("\nEnter your choice\n1.Makeset\n2.Unionset\n3.Findset\n4.Display");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
makeset(s);
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
f=findset(e,s);
if(f==0)
printf("Not found");
else
printf("Element found");
break;
}
case 4:
{
printf("\nElements are");
dis(s,n);
break;
}
}
}while(ch!=5);
}

