#include"queuehead.h"
main()
{
int choice,a,b,d,c;
queue front,rear,k;
char h[10];
front=(queue)malloc(sizeof(struct node));
front->next=NULL;
rear=front;
while(1)
{
printf("1.ENQUEUE\n2.DEQUEUE\n3.ISEMPTY\n4.MAKE EMPTY\n5.SEARCH\n6.DISPLAY\n7.PALINDROME\n8.EXIT\nENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("ENTER THE ELEMENTS");
scanf("%d",&a);
rear=enqueue(a,rear);
break;
case 2:
rear=dequeue(front,rear);
//printf("%d IS DELETED",b);
break;
case 3:
c=isempty(front,rear);
if(c==1)
printf("QUEUE IS EMPTY");
else
printf("QUEUE IS NOT EMPTY");
break;
case 4:
makeempty(front,rear);
break;
case 6:
display(front,rear);
break;
case 5:
printf("ENTER THE SEARCH ELEMENT");
scanf("%d",&d);
search(front,rear,d);
break;
case 7:
printf("ENTER THE STRING");
scanf("%s",&h);
palindrome(h);
break;
case 8:
exit(0);
}
}
}

