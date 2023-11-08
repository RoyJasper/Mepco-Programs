#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	FILE *fp;
	char a[50],b[50][50];
	int m,choice,n,i,j,k=0,count=0;
	fp=fopen("medium1.txt","w");
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			b[i][j]='\0';
		}
	}
	for(i=0;i<50;i++)
		a[i]='\0';
	printf("1.VRC\n2.LRC\nENTER THE CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("ENTER THE BIT SEQUENCE");
			scanf("%s",a);
			n=strlen(a);
			for(i=0;i<n;i++)
			{
				for(j=0;j<8;j++)
				{
					b[i][j]=a[k];
						k++;
					if(k>n)
						b[i][j]='0';
				}
					if(k>n)
						break;
			}	
			m=i+1;
			for(i=0;i<m;i++)
			{
				printf("%s",b[i]);
			}
			for(i=0;i<m;i++)
			{
				count=0;
				for(j=0;j<8;j++)
				{
					if(b[i][j]=='1')
					{
						count=count+1;
					}
				}
			//	printf("%d",count);
				if(count%2!=0)
					b[i][8]='1';
				else
					b[i][8]='0';
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<strlen(b[i]);j++)
					putc(b[i][j],fp);
			}
			break;
	}
}

