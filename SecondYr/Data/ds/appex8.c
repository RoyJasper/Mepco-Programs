#include"headex8.h"
main()
{
	int i,ch,x;
	hash *h;
	h=(hash)malloc(10*sizeof(struct node));
	for(i=0;i<10;i++)
		h[i]->next=NULL;
	while(1)
	{
		printf("\n1]Insert\n2]Delete\n3]Search\n4]Dislay\n5]Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the Element:");
			       scanf("%d",&x);
			       insert(x,h);
			       break;
			case 2:printf("Enter the Element:");
			       scanf("%d",&x);
			       del(x,h);
			       break;
			case 3:printf("Enter the Element:");
			       scanf("%d",&x);
			       if(search(x,h))
			       	printf("Present");
			       else
			       	printf("Not Found");
			       break;
			case 4:display(h);
			       break;
			case 5:exit(0);
		}
	}
}