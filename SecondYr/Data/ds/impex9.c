#include"headex9.h"
void insert(int*x,hash h,int s)
{
	int i,a,b;
	for(i=0;i<s;i++)
	{
		if(x[i]!=NULL)
		{
			a=x[i];
			b=a%5;
			while(h->a[b]!=NULL)
			{
				b++;
				if(b==s)
					b=0;
			}
			h->a[b]=x[i];
		}
	}
}
void display(int x,hash h,int s)
{
	if(search(x,h,s)==1)
	{
		i=x%s;
		while(h->a[i]!=x)
		{
			i++;
			if(i==s)
				i=0;
		}
		h->a[i]=NULL;
	}
	else
		printf("Element not prresent");
}
int search(int x,hash h,int s)
{
	int i,j;
	j=x%s;
	for(i=0;i<s;i++,j++)
	{
		if(j==s)
			j=0;
		if(h->a[j]==x)
			return 1;
	}
	return 0;
}
void display(hash h,int s)
{
	int i;
	for(i=0;i<s;i++)
		printf("%d",h->a[i])
}