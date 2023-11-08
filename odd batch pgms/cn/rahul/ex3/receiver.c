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
	int flag=0,count,d[50],c[50][50],j,r,n,i,cc,bb,k,l;
  char a[50],b[50],e[50],f[50],dd,ccc[50];
	fp=fopen("medium.txt","r");
	dd=fgetc(fp);
	i=1;
	while(dd!=EOF)
	{
		a[i]=dd;
		i++;
		dd=fgetc(fp);
	}
	n=i-2;
//	for(i=1;i<=n;i++)
	//	printf("%c",a[i]);
	i=1;
	while(1)
	{
		bb=po(2,i);
		if(bb>=n)
			break;
		i++;
	}
	r=i;
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
//	{
//		for(j=0;j<d[i];j++)
//		{
//			printf("%d",c[i][j]);
//		}
//		printf("\n");
//	}
	l=0;
	flag=0;
//	printf("%d",r);
	for(i=0;i<r;i++)
	{
		count=0;
		for(j=0;j<d[i];j++)
		{
			if(a[c[i][j]]=='1')
			{
	//			printf("%c",a[c[i][j]]);
				count++;
			}
		}
		if((count%2)==0)
		{
			ccc[l]='0';
			l++;
			flag=flag+1;
	//		printf("%d",flag);
		}
		else
		{
			ccc[l]='1';
			l++;
		}
//		printf("\n");
	}
//	printf("%d",flag);
	if(flag!=r)
		printf("ERROR IS:%s",ccc);
	else
	{
		k=1;
  	i=po(2,0);
  	j=i;
  	for(;k<=r;)
  	{
    	a[j]='$';
    	j=po(2,i);
    	i++;
    	k++;
  	}
		for(i=n;i>=1;i--)
		{
			if(a[i]!='$')
				printf("%c",a[i]);
		}
	}
}

