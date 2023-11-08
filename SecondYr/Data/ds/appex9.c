main()
{
	int *x,y,,ch,i,s;
	printf("Enter the size:");
	scanf("%d",&s);
	x=(int*)malloc(s*sizeof(int));
	hash h;
	h=(hash)malloc(sizeof(struct node));
	h->a=(int*)malloc(s*sizeof(int));
	printf("Enter the elements:");
	for(i=0;i<s;i++)
		scanf("%d",&x[i]);
	insert(x,h,s);
	while(1)
	{
		printf("1]Insert\n2]Delete\n3]Display\n4]Search\n5]Exit\nEnter your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted:");
			       scanf("%d",&y);
			       insert(y,h,s);
			       break;
			case 2:printf("Enter the element:");
			       scanf("%d",&y);
			       delete(y,h,s);
			       break;
			case 3:display(h,s);
			       break;
			case 4:printf("Enter the element:");
			       scanf("%d",&y);
			       if(search(y,h,s)==1)
			       	printf("Present");
			       else
			       	printf("Not Found");
			       break;
			case 5:exit(0);
		}
	}
}