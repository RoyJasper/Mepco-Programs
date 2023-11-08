#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int pp,kl,n,m,i,j,k;
	char c[50][50][50],b[50],a[50],d[50],stack[50];
	printf("ENTER THE NO OF TERMINALS");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&a[i]);
	}
	printf("ENTER THE NO OF NON TERMINALS");
  scanf("%d",&m);
  for(i=0;i<m;i++)
  {
    scanf(" %c",&b[i]);
  }
	printf("ENTER THE VALUES FOR THE TABLE");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%s",c[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<strlen(c[i][j]);k++)
			{
				printf("%c",c[i][j][k]);
			}
			printf("\t");
		}
		printf("\n");
	}
	printf("ENTER THE STRING");
	scanf("%s",d);
	stack[0]='E';
	pp=0;
	while(d[0]!='\0')
	{
		//printf("hai");
		if(stack[pp]!=d[0])
		{
			for(i=0;i<n;i++)
			{
				printf("HA");
				if(stack[pp]==a[i])
				{
					kl=i;
					for(i=0;i<m;i++)
					{
						printf("SD");
						if(b[i]==d[0])
						{
							for(k=strlen(c[kl][i])-1;k>=0;k--)
							{
								printf("HJ");
								stack[pp]=c[kl][i][k];
								pp++;
							}
							printf("%d",pp);
							pp--;
							break;
						}
					}
					break;
				}
			}
		}
		else
		{
			break;
			for(k=1;k<strlen(d);k++)
			{
				d[k-1]=d[k];
			}
			pp--;
		}
	}
	printf("%s",stack);
}
