#include<stdio.h>
int absolute(int a,int b)
{
	int c=a-b;
	if(c<0)
		return -c;
	return c;
}
main()
{
	int ch,m,n,x,start,i,j,pos,min,a[15],count;
	count=0;
	printf("\nEnter no of cylinders");
	scanf("%d",&m);
	printf("\nEnter no of requests");
	scanf("%d",&n);
	printf("\nEnter pointer head start position");
	scanf("%d",&start);
	printf("\nEnter the series of request ques");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=m)
		{
			printf("\nINVALID INPUT.. ENTER NEW INPUT");
			scanf("%d",&a[i]);
		}
	}
	do
	{
		printf("\n1.FCFS\t2.SSTF\t3.Exit\n");
		scanf("%d",&ch);
		count=0;
		x=start;
		switch(ch)
		{
			case 1:
						printf("\nDisk head movement order is :%d",start);
						for(i=0;i<n;i++)
						{
							x-=a[i];
							if(x<0)
								x=-x;
							count+=x;
							x=a[i];
							printf("\t%d",x);
						}
						printf("\nTotal :%d",count);
						break;
			case 2:
						count=0;
						x=start;
						printf("\nDisk head movement order is S:%d",start);
						for(i=0;i<n;i++)
						{
							min=absolute(a[i],x);
							pos=i;
							for(j=i+1;j<n;j++)
							{
								if(min>absolute(x,a[j]))
								{
									pos=j;
									min=absolute(x,a[j]);
								}
							}
							count+=absolute(x,a[pos]);
							x=a[pos];
							a[pos]=a[i];
							a[i]=x;
							printf("\t%d",x);
						}
						printf("\nTotal :%d",count);
						break;
		}
	}while(ch!=3);
}

