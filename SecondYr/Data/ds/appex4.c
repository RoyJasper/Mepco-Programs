#include"headex4.h"
main()
{
	int c,a;
	bst t;
	t=(bst)malloc(sizeof(struct node));
	t->right='\0';
	t->left='\0';
	while(1)
	{
		printf("\n1]Insert\n2]Remove\n3]Search\n4]Inorder\n5]Postorder\n6]Preorder\n7]Exit\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the number:");
			       scanf("%d",&a);
			       t=insert(a,t);
			       break;
			case 2:printf("Enter the number:");
			       scanf("%d",&a);
			      t=removeit(a,t);
			       break;
			case 3:printf("Enter the number:");
			       scanf("%d",&a);
			       searchit(a,t);
			       break;
			case 4:inorder(t);
			       break;
			case 5:postorder(t);
			       break;
			case 6:preorder(t);
			       break;
			case 7:exit(0);
		}
	}
}
