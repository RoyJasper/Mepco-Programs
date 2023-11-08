#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	FILE *fp;
	int i=0,d=0,l=0,m=0,k=0,kl=0,j=0,c=0,n=0,nm=0;
	char a[15][30]={"main","include","stdio","stdlib","string","int","float","char","printf","scanf","if","else"};
	char b[100],t[50][50],sp[50][50],id[50][50],mn;
	fp=fopen("program.c","r");
	mn=fgetc(fp);
	while(mn!=EOF)
	{
		nm++;
		mn=fgetc(fp);
	}
printf("%d",nm);
	fclose(fp);
	fp=fopen("program.c","r");
  b[0]=fgetc(fp);
	while(n!=nm-1)
	{
		n++;
		c=0;
		i=0;
		d=(int)b[0];
		while(b[i]!=' '&& !((d>32 && d<48)||(d >58&&d <64)||(d==123)||(d==125)))
		{
			n++;
			i++;
			mn=fgetc(fp);
			d=(int)mn;
			if(!((d>32 && d<48)||(d >58&&d <64)||(d==123)||(d==125)))
			{
				b[i]=mn;
			}
			else
			{
				n--;
				fseek(fp,n,SEEK_SET);
				break;
			}
		}
		for(j=0;j<12;j++)
		{
			if(strcmp(b,a[j])==0)
			{
				c=1;
				strcpy(t[k],b);
				k++;
				break;
			}
		}
		d=(int)b[0];
		if(d>32 && d<48||(d>58&&d<64)||(d==123)||(d==125))
		{
			c=1;
			strcpy(sp[l],b);
			l++;
		}
		if(c!=1&& !strcmp(b," ")==0)
		{
			strcpy(id[m],b);
			m++;
		}
		i=0;
		while(i!=100)
		{
			b[i]=NULL;
			i++;
		}
		b[0]=fgetc(fp);
	}
	printf("THE KEYWORDS\n");
	for(i=0;i<k;i++)
	{
		printf("%s",t[i]);
	}
	printf("\nIDENTIFIERS\t");
	for(i=0;i<m;i++)
	{
		printf("%s",id[i]);
	}
	printf("\nSPECIAL CHARACTERS\t");
	for(i=0;i<l;i++)
  {
    printf("%s\n",sp[i]);
  }
}
