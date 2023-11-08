#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	FILE *fp,*fp1;
	int m,n,choice,i,j,k=0,count=0,l;
	char b[50][50],a[50],d,g,c[50];
	fp=fopen("medium1.txt","r");
	fp1=fopen("medium2.txt","r");
	for(i=0;i<50;i++)
  {
    for(j=0;j<50;j++)
    {
      b[i][j]='\0';
    }
  }
  for(i=0;i<50;i++)
	{
    a[i]='\0';
		c[i]='\0';
	}
	printf("1.VRC\n2.LRC\nENTER THE CHOICE:");
	scanf("%d",&choice);
	i=0;
	switch(choice)
	{
		case 1:
			d=fgetc(fp);
			while(d!=EOF)
			{
				a[i]=d;
				i++;
				d=fgetc(fp);
			}
		//	printf("%s",a);
			 n=strlen(a);
      for(i=0;i<n;i++)
      {
        for(j=0;j<9;j++)
        {
          b[i][j]=a[k];
            k++;
          if(k>=n)
            break;
        }
          if(k>=n)
            break;
      }
      m=i+1;
	//		for(i=0;i<m;i++)
	//		{
		//		printf("%s\n",b[i]);
	//		}
      for(i=0;i<m;i++)
      {
        count=0;
        for(j=0;j<(strlen(b[i])-1);j++)
        {
          if(b[i][j]=='1')
          {
            count=count+1;
          }
        }
        if(count%2!=0)
          g='1';
        else
          g='0';
		//		printf("\n%c\t%d\n",b[i][j],strlen(b[i]));
				if(g==b[i][j])
				{
					b[i][j]='\0';
				}
				else
				{
					printf("ERROR MESSAGE");
					break;
				}
      }
      for(i=0;i<m;i++)
      {
        printf("%s\n",b[i]);
      }
			close(fp);
			close(fp1);
			break;
		case 2:
			d=fgetc(fp1);
      while(d!=EOF)
      {
        a[i]=d;
        i++;
        d=fgetc(fp1);
      }
      n=strlen(a);
			n=n/8;
	//		printf("%d",n);
			 for(i=0;i<n;i++)
      {
        for(j=0;j<8;j++)
        {
          b[i][j]=a[k];
            k++;
        }
      }
      m=i;
    //  for(i=0;i<m;i++)
    //  {
    //    printf("%s\n",b[i]);
    //  }
			l=0;
			for(i=0;i<8;i++)
      {
        count=0;
        for(j=0;j<m;j++)
        {
					if(b[j][i]!='0')
          	count=count+1;
        }
	//			printf("%d\t",count);
        if(count%2==0)
        {
          l++;
        }
      }
			if(l==8)
			{
				printf("MESSAGE RECEIVED\n");
				for(i=0;i<m-1;i++)
					printf("%s\n",b[i]);
			}
			else
			{
	//			for(i=0;i<m-1;i++)
    //      printf("%s\n",b[i]);
				printf("ERROR MESSAGE");
			}
			close(fp);
			close(fp1);
			break;
	}
}	
