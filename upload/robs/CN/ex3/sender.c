#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int po(int a,int b)
{
	int c=1,i;
	if(b==0)
	{
		return 1;
	}
	else
	{
		for(i=1;i<=b;i++)
		{
			c=c*a;
		}
		return c;
	}
}
main()
{
	FILE *fp;
	int count,d[50],c[50][50],j,r,n,i,cc,bb,k;
	char a[50],b[50],e[50],f[50];
	fp=fopen("medium.txt","w");
	printf("ENTER THE STRING");
	scanf("%s",a);
	n=strlen(a);
	i=0;
	while(1)
	{
		bb=po(2,i);
		cc=n+1+i;
		if(bb>=cc)
			break;
		i++;
	}
	r=i;
	n=n+r;
	k=1;
	i=po(2,0);
	j=i;
	for(;k<=r;)
	{
		b[j]='$';
		j=po(2,i);
//		printf("%d\t",j);
		i++;
		k++;
	}
	printf("%s%d\n",a,n);
	k=strlen(a)-1;
	for(i=1;i<=n;i++)
	{
		if(b[i]=='$')
			continue;
		else
		{
			b[i]=a[k];
			k--;
		}
	}
//	for(i=1;i<=n;i++)
//		printf("%c\t",b[i]);
//	printf("\n%d\n",n);
	for(i=1;i<=r;i++)
	{
		k=0;
		j=po(2,i);
		count=0;
		for(;j<=n;j++)
		{
			c[i][k]=j;
			k++;
			count++;
			if(count==po(2,i))
			{
				count=0;
				j=j+po(2,i);
			}
		}
		d[i]=k;
	}
	k=0;
	for(i=1;i<=n;i=i+2)
	{
		c[0][k]=i;
		k++;
	}
	d[0]=k;
//	for(i=0;i<r;i++)
//		for(j=0;j<d[i];j++)
//			printf("%d\t",c[i][j]);
//	d[0]=k;
	for(i=0;i<r;i++)
	{
		count=0;
		for(j=0;j<d[i];j++)
		{
			e[j]=b[c[i][j]];
//			printf("%c\t",e[j]);
			if(e[j]=='1')
				count++;
		}
		if((count%2)!=0)
		{
			f[i]='1';
	//		printf("%c",f[i]);
		}
		else
			f[i]='0';
		printf("\n");
	}
	printf("%s",f);
	k=0;
	for(i=0;i<n;i++)
	{
		if(b[i]=='$')
		{
			b[i]=f[k];
			k++;
		}
	}
	for(i=1;i<=n;i++)
	{
		putc(b[i],fp);
	}
	printf("SENDED");
}
