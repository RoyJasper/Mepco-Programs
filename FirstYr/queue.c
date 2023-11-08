#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
int *a;
int c,s,f,r;
};
typedef struct queue *q1;
q1 * create(int n)
	{
		q1 q;
		q=(q1 *)malloc (sizeof (struct queue));
		q->a=(int *)malloc (sizeof (int)*n);
		q->s=0;
		q->c=n;
		q->f=0;
		q->r=-1;
		return q;
	}
q1 *enqueue(q1 q,int e)
 {
	if(q->s<=q->c)
   {
    q->r=q->r++;
    q->a[q->r]=e;
    q->s++;
   }
  return q;
 }
main()
{
	int e,n,i;
	printf("\nEnter the size\n");
	scanf("%d",&n);
	q1 q=create(n);
	for(i=0;i<n;i++)
		{
			printf("\nEnter the elements\n ");
			scanf("%d",&e);
			q=enqueue(q,e);
		}
	printf("\nThe queue is\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",q->a[i]);
		}
		printf("\nstack is \n");
			for (i=n-1;i>=0;i--)
			{
				printf("%d\t",q->a[i]);
			}
}	
