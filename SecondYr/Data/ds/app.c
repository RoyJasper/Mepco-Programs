#include"headex5.h"
main()
{
	int ch,x;
	avl t;
	t=(avl)malloc(sizeof(struct node));
	t=NULL;
	while(1)
	{
		printf("\n1]Insert\n2]Height\n3]Display\n4]Search\n5]Exit\nEnter your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the data:");
			       scanf("%d",&x);
			       t=insert(x,t);
			       break;
			case 2:printf("Height of the tree is ",height(t));
			       break;
			case 3:display(t);
			       break;
			case 4:printf("Enter the data:");
			       scanf("%d",&x);
			       search(x,t);
			       break;
			case 5:exit(0);
			default:printf("Invalid Choice");
		}
	}
}
