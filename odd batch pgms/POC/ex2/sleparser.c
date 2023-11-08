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
		printf("%s\n",s.stack);
}
main()
{
	stacks s;
	int nn,n,m,i,j,k,b,c,d,e;
	char ti[50][50],tt[50][50][50],ss[50][50],strings[50];
	s=initialize(s);
	printf("ENTER THE NO OF I's");
	scanf("%d",&n);
	printf("ENTER THE NO OF TERMINAL & NON TERMINAL");
	scanf("%d",&m);
	printf("ENTER THE TERMINAL & NON TREMINAL");
	for(i=0;i<m;i++)
		scanf("%s",ti[i]);
	printf("ENTER THE NO OF STRINGS");
	scanf("%d",&nn);
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
	s=push(s,'0');
	printf("ENTER THE STRING");
	scanf("%s",strings);
	for(i=0;i<strlen(strings);i++)
	{
		for(j=0;j<m;j++)
		{
			if(strings[0]==ti[j][0])
			{
				break;
			}
		}
		b=j;
		if(tt[s.stack[s.size-1]][b][0] !='S')
		{
			if(!(strcmp(tt[s.stack[s.size-1]][b],"ACCEPT")==0))
			{
				c=tt[s.stack[s.size-1]][b][1];
				d=strlen(ss[c]);
				d=d-2;
				for(k=0;k<(d*2);k++)
				{
					s=pop(s);
				}
				e=ss[c][0];
				for(j=0;j<m;j++)
				{
					if(e==ti[i][0])
					{
						break;
					}
				}
				b=j;
				c=tt[s.stack[s.size-1]][b][0];
				s=push(s,e);
				s=push(s,c);
			}
			else
				exit(-1);
		}
		else
		{
			s=push(s,strings[0]);
			s=push(s,tt[s.stack[s.size-1]][b][1]);
			for(k=1;k<strlen(strings);k++)
				strings[k-1]=strings[k];
		}
	}
}
