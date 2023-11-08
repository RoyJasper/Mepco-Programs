#include"hashhead.h"
main()
{
hash head,t1;
int size,h,choice,t[10],i;
printf("ENTER THE SIZE OF TABLE");
scanf("%d",&size);
head=create(size);
while(1)
{
printf("1.INSERT 2.DELETE 3.DISPLAY 4.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
printf("starting add is %p",head);
head=insert(h,head);
break;
case 2:	printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
head=delet(h,head);
break;
case 3:
//hash t1;
/*for(i=0;i<size;i++)
{
t[i]=head->l[i];
}*/
t1=head;
printf("starting addressis %p",head->l[5]);
display(t1);
printf("starting address is %p",t1->l[5]);
/*for(i=0;i<size;i++)
{
head->l[i]=t[i];
}*/
break;
case 4: exit(0);
break;
}
}
}

