#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int pp,kl,n,m,i,j,k;
	char c[50][50][50],b[50],a[50],d[50],e[50],stack[50];
	printf("ENTER THE NO OF NON TERMINALS");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&a[i]);
	}
	printf("ENTER THE NO OF TERMINALS");
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
	stack[0]='$';
	stack[1]=a[0];
	pp=1;
	printf("STACK\tINPUT\tACTION\n");
	while(d[0]!='\0')
	{
		if(stack[pp]!=d[0])
		{
			for(i=0;i<n;i++)
			{
				if(stack[pp]==a[i])
				{
					kl=i;
					for(i=0;i<m;i++)
					{
						if(b[i]==d[0])
						{
							 printf("%s\t%s\t%s\n",stack,d,e);
							if(c[kl][i][0]!='^')
							{
								for(k=strlen(c[kl][i])-1;k>=0;k--)
								{
				//				printf("HJ");
									stack[pp]=c[kl][i][k];
							//	printf("%s\t%s\n",stack,d);
									pp++;
								}
								strcpy(e,c[kl][i]);
								// printf("%s\t%s\n",stack,d);
			//				printf("%d",pp);
								pp--;
								break;
							}
							else
							{
								for(k=0;k<50;k++)
									e[k]='\0';
								e[0]='^';
								stack[pp]='\0';
							//	 printf("%s\t%s\n",stack,d);
								pp--;
								break;
							}
						}
					}
					break;
				}
			}
		}
		else
		{
			printf("%s\t%s\t%s\n",stack,d,e);
			for(k=1;k<=strlen(d);k++)
			{
				d[k-1]=d[k];
		//		printf("%c",d[k-1]);
			}
			for(k=0;k<50;k++)
         e[k]='\0';
			stack[pp]='\0';
			pp--;	
	//		printf("%s\t%s\t%s\n",stack,d,e);
		}
	}
	printf("%s",stack);
	return(0);
}
