#include<stdio.h>
struct memory
{
int size;
int memory[50];
}m;
struct process
{
int size;
int process[50];
}p;
void firstfit(int[],int,int[],int);
void bestfit(int[],int,int[],int);
void worstfit(int[],int,int[],int);
main()
{
	int i,memory[50],mn,pn,process[50];
	printf("\nEnter amount of memory ");
	scanf("%d",&m.size);
  printf("\nEnter  memory ");
	 for(i=0;i<m.size;i++)
		scanf("%d",&m.memory[i]);
	printf("\nEnter no of process ");
  scanf("%d",&p.size);
  printf("\nEnter process..  ");
   for(i=0;i<p.size;i++)
    scanf("%d",&p.process[i]);
	firstfit(m.memory,m.size,p.process,p.size);
	bestfit(m.memory,m.size,p.process,p.size);
	worstfit(m.memory,m.size,p.process,p.size);
}
void firstfit(int memory[50],int mn,int process[50],int pn)
{
	int temp[50],flag[50],value[50],i,j;
	printf("\n-------FRST FIT-------\n");
	for(i=0;i<mn;i++)
    {
    temp[i]=memory[i];
    value[i]=0;
    }
	for(i=0;i<pn;i++)
		flag[i]=0;
	for(i=0;i<pn;i++)
	{
		for(j=0;j<mn;j++)
		{
			if(flag[i]==0&&temp[j]>=process[i])
			{
				flag[i]=1;
				printf("%d Inserted in %d\n",process[i],temp[j]);
				value[j]=temp[j]-process[i];
				temp[j]=0;
				break;
			}
			if(j+1==mn)
				printf("%d Impossible\n",process[i]);
		}
	}
	for(i=0;i<mn;i++)
	{
		value[i]=value[i]+temp[i];
		printf("\nThe Remaining values are p%d=%d",i,value[i]);
	}
}
void bestfit(int memory[50],int mn,int process[50],int pn)
{
  int temp[50],t,flag[50],value[50],name[50],i,j;
  printf("\n-------BEST FIT-------\n");
    for(i=0;i<mn;i++)
    {
        temp[i]=memory[i];
    value[i]=0;
    name[i]=i;
    }

  for(i=0;i<mn;i++)
  {
    for(j=i+1;j<mn;j++)
    {
      if(temp[i]>temp[j])
      {
        t=temp[i];
        temp[i]=temp[j];
       	temp[j]=t;
       	t=name[i];
       	name[i]=name[j];
       	name[j]=t;
      }
    }
  }
  for(i=0;i<pn;i++)
	{
    flag[i]=0;
	}
  for(i=0;i<pn;i++)
  {
    for(j=0;j<mn;j++)
    {
      if(flag[i]==0&&temp[j]>=process[i])
      {
        flag[i]=1;
        printf("%d Inserted in %d\n",process[i],temp[j]);
				value[j]=temp[j]-process[i];
				temp[j]=0;
        break;
      }
      if(j+1==mn)
			{
        printf("%d Impossible\n",process[i]);
			}
    }
  }
	for(i=0;i<mn;i++)
	{
		value[i]=value[i]+temp[i];
		printf("\nThe Remaining values are p%d=%d",name[i],value[i]);
	}
}
void worstfit(int memory[50],int mn,int process[50],int pn)
{
  int name[50],temp[50],t,flag[50],value[50],i,j;
  printf("\n-------WORST FIT-------\n");
   for(i=0;i<mn;i++)
    {
        temp[i]=memory[i];
    value[i]=0;
    name[i]=i;
    }
  for(i=0;i<mn;i++)
  {
    for(j=i+1;j<mn;j++)
    {
      if(temp[i]<temp[j])
      {
        t=temp[i];
        temp[i]=temp[j];
        temp[j]=t;
        t=name[i];
       	name[i]=name[j];
       	name[j]=t;
      }
    }
  }
  for(i=0;i<pn;i++)
    flag[i]=0;
  for(i=0;i<pn;i++)
  {
    for(j=0;j<mn;j++)
    {
      if(flag[i]==0&&temp[j]>=process[i])
      {
        flag[i]=1;
        printf("%d Inserted in %d\n",process[i],temp[j]);
				value[j]=temp[j]-process[i];
				temp[j]=0;
        break;
      }
      if(j+1==mn)
        printf("%d Impossible\n",process[i]);
    }
  }
  for(i=0;i<mn;i++)
	{
		value[i]=value[i]+temp[i];
		printf("\nTHE Remaining values are p%d=%d",name[i],value[i]);
	}
}

