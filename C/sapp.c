#include"slist.h"
int main()
{
int n,p,choice,b,c,e,g;
list head,q;
char na[20];
head=(list)malloc(sizeof(struct student));
while(1)
{
printf("\n1.insertion\n2.search\n3.display\n4.delete\n5.isempty\n6.locate\n7.retrive\n 8.reverse\n 9.exit enter the choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("ENTER HTE ID,POSITION,NAME OF THE STUDENT");
scanf("%d%d%s",&n,&p,na);
g=insert(n,p,na,head);
break;
case 2:
printf("ENTER EHT STUDENT ID TO BE SEARCHED");
scanf("%d",&n);
b=search(n,head);
if(b==1)
printf("IT IS PRESENT");
else
printf("IT IS NOT PRESENT");
break;
case 3:
display(head);
break;
case 4:
printf("ENTER THE STUDENT ID");
scanf("%d",&n);
delet(n,head);
break;
case 5:
c=isempty(head);
if(c==1)
printf("IT IS NOT EMPTY");
else
printf("IT IS EMPTY");
break;
case 6:
printf("ENTER THE STUDENT ID");
scanf("%d",&n);
e=locate(n,head);
if(e!=0)
printf("THE POSITION IS %d",e);
else
printf("IT IS NOT PRESENT");
break;
case 7:
printf("ENTER THE POSITION");
scanf("%d",&p);
if(p<=g)
{
q=retrive(p,head);
printf("THE NAME IS %s ID %d",q->name,q->stid);
}
else
printf("IT IS OUT OF POSITION");
break;
case 8:
reverse(head);
break;
case 9:
exit(0);
}
}
}

