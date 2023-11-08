#include"headex3.h"
main()
{
	int x,c,k,n;
	queue front,rear;
	front->next=NULL;
	rear=front;
	while(1)
	{
	printf("\n1]Enqueue\n2]Dequeue\n3]Isempty\n4]Makeempty\n5]Display\n6]Search\n7]Josephus Problem\n8]Exit\nEnter your Choice:");
	scanf("%d",c);
	switch(c)
	{
		case 1:printf("\nEnter the data:");
		       scanf("%d",&x);
		       enqueue(x,rear);
		       break;
		case 2:dequeue(front,rear);
		       break;
		case 3:if(isempty(front,rear));
			printf("Empty");
		       else
			printf("Not Empty");
		       break;
		case 4:makeempty(front,rear);
		       break;
		case 5:display(front);
		       break;
		case 6:printf("\nEnter the data to be searched:");
		       scanf("%d",x);
		       if(search(front,x))
			printf("Present");
		       else
			printf("Not Present");
		       break;
		case 7:printf("\nEnter the number of elements:");
		       scanf("%d",&n);
		       printf("\nEnter the Josephus number:");
		       scanf("%d",&k);
		       jp(k,n,front,rear);
		       break;
		case 8:exit(0);
	}
	}
}