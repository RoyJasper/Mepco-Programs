#include<stdio.h>
main()
{
	int alloc[10][5],k,max[10][5],need[10][5],avail[5],flag[10],sq[10],i,j,n,r,count,count1=0;
	printf("\n Enter no of Process..   ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		flag[i]=0;
	printf("\n Enter no of resource..  ");
  scanf("%d",&r);
	printf("\n Enter Allocation \n");
	for(i=0;i<n;i++)
	{
		printf("FOR P%d ",i);
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\n Enter maximum \n");
  for(i=0;i<n;i++)
  {
    printf("FOR P%d ",i);
    for(j=0;j<r;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
	printf("\n Enter available\n ");
  for(i=0;i<r;i++)
  {
		scanf("%d",&avail[i]);
	}
	for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
	printf("\n Need: \n");
  for(i=0;i<n;i++)
  {
    printf("For P%d ",i);
    for(j=0;j<r;j++)
    {
      printf("%d \t",need[i][j]);
    }
		printf("\n");
  }
	do
	{
		for(i=0;i<n;i++)
		{
			if(flag[i]==0)
			{
				count=0;
				for(j=0;j<r;j++)
				{
					if(avail[j]>=need[i][j])
					{
						count++;
					}
				}
				if(count==r)
				{
					count1++;
					flag[i]=1;
					sq[count1-1]=i;
					for(j=0;j<r;j++)
						avail[j]=avail[j]+alloc[i][j];
				}
			}
		}
		/*if(count1!=n)
		{
			printf("UNSAFE");
			break;
		}*/
	}while(count1!=n);
	if(count1==n)
	{
		printf("Its a safe sequence\n ");
		for(i=0;i<n;i++)
		{
			printf(" p%d\t",sq[i]);
		}
	//	printf(">");
	}
}

