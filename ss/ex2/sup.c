#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void removeSpaces(char *str)
{
		printf("\n\n\n\n%c",str[0]);
    int count = 0,i;
    for (i = 0; str[i]; i++)
        if (str[i] != NULL)
				{
            str[count++] = str[i];
						 printf("%c%d\n",str[count],count);

				}	
   // str[count] = '\0';
}
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
		removeSpaces(b);
		for(i=0;i<strlen(b);i++)
		{
			printf("%c%d\n",b[i],i+1);
		}
		printf("%d%d",n,ftell(fp));
	//	printf("%s%d\n",b,strlen(b));
		removeSpaces(b);
		for(j=0;j<12;j++)
		{
			printf("%s%d",b,strlen(a[j]));
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
//	{
		printf("%s",t[i]);
//	}
	printf("IDENTIFIERS");
//	for(i=0;i<m;i++)
//	{
		printf("%s%s",id[1],id[3]);
//	}
	for(i=0;i<l;i++)
 // {
    printf("%s\n",sp[i]);
 // }
}

