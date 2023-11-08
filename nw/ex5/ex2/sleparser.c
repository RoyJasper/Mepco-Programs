#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char stack[50];
	int size;
};
typedef struct node stacks;
stacks initialize(stacks s)
{
	int i;
	for(i=0;i<50;i++)
		s.stack[i]='\0';
	s.size=0;
	return s;
}
stacks push(stacks s,char a)
{
	s.stack[s.size]=a;
	s.size++;
	return s;
}
stacks pop(stacks s)
{
	s.size--;
	s.stack[s.size]='\0';
	return s;
}
void display(stacks s)
{
	int i;
	for(i=0;i<s.size;i++)
	{
		if(s.stack[i]=='#')
			printf("10");
		else
			printf("%c",s.stack[i]);	
	}
}
int main()
{
	stacks s;
	int jj,nn,n,m,i,j,k,b,c,d,e,fg,fg1;
	char ti[50][50],tt[50][50][50],ss[50][50],strings[50],ccc[50];
	s=initialize(s);
	printf("ENTER THE NO OF I's:");
	scanf("%d",&n);
	printf("ENTER THE NO OF TERMINAL & NON TERMINAL:");
	scanf("%d",&m);
	printf("ENTER THE TERMINAL AND NON TERMINAL:");
	for(i=0;i<m;i++)
		scanf("%s",ti[i]);
	printf("ENTER THE NO OF GRAMMER:");
	scanf("%d",&nn);
	printf("ENTER THE GRAMMER:");
	for(i=0;i<nn;i++)
		scanf("%s",ss[i]);
	printf("ENTER THE VALUES IN TABLE");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%s",tt[i][j]);
		}
	}
	for(i=0;i<n;i++)
  	{
    		for(j=0;j<m;j++)
    		{
      			printf("%s",tt[i][j]);
			printf("\t");
    		}
		printf("\n");
 	}
	s=push(s,'$');
	s=push(s,'0');
	printf("ENTER THE STRING");
	scanf("%s",strings);
	printf("\n");
	display(s);
//	printf("\t%c",strings[0]);
//	printf("\t%c",ti[2][0]);
//	printf("\t%c",ti[3][0]);
//	printf("\t%c",ti[4][0]);
	i=0;
	if(i==0)
	{
	while(strings[0]!='\0')
	{
		for(j=0;j<m;j++)
		{
			if(strings[0]==ti[j][0])
			{
				break;
			}
		}
		b=j;
//		display(s);
		if(s.stack[s.size-1]=='#')
		{
			fg=10;
		}
		else
		{
			fg=s.stack[s.size-1]-48;
		}
	//	printf("%d",fg);
//		if(i!=0)
//		{
		if(tt[fg][b][0] !='S')
		{
		//	printf("HAI");
			if(!(strcmp(tt[fg][b],"ACCEPT")==0))
			{
				c=tt[fg][b][1]-48;
				strcpy(ccc,tt[fg][b]);
	//			printf("%d",c);
				c--;
				d=strlen(ss[c]);
				d=d-2;
	//			printf("\n%d\n",d);
				for(k=0;k<(d*2);k++)
				{
					s=pop(s);
				//	printf("\t%d\t",s.size);
				//	display(s);
				}
				e=ss[c][0];
				for(j=0;j<m;j++)
				{
					if(e==ti[j][0])
					{
						break;
					}
				}
				b=j;
				jj=c;
				c=s.stack[s.size-1]-48;
				s=push(s,e);
		//		printf("\t%d\t",b);
				if(strlen(tt[c][b])==2)
				{
					s=push(s,'#');
					printf("\t\t%s\t%s\t10\t%s\n",strings,ccc,ss[jj]);
					display(s);
				}
				else
				{
					e=tt[c][b][0];
					s=push(s,e);
					printf("\t\t%s\t%s\t%c\t%s\n",strings,ccc,e,ss[jj]);
					display(s);
				}
			}
			else
			{
				printf("\t\t%s\tACCEPT\n",strings);
				exit(-1);
			}
		}
		else
		{
			fg=s.stack[s.size-1]-48;
			strcpy(ccc,tt[fg][b]);
			s=push(s,strings[0]);
			s=push(s,tt[fg][b][1]);
			for(k=1;k<strlen(strings);k++)
				strings[k-1]=strings[k];
			if(strlen(strings)==1)
			{
				strings[0]='\0';
			}
			strings[k-1]='\0';
		//	printf("\n%s\n",strings);
			printf("\t\t%s\t%s\n",strings,ccc);
			display(s);
		}
//		}
//		exit(-1);
	}
	}
	return 0;
}
