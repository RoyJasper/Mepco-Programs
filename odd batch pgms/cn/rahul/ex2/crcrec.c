#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char xor(char a,char b)
{
  if((a=='0'&& b=='0')||(a=='1'&&b=='1'))
  {
    return '0';
  }
  else
  {
    return '1';
  }
}
int main()
{
  FILE *fp;
  char a[50],b[50],c[50],d[50],e;
  int n,m,i=0,j=0,count=0;
  fp=fopen("medium.txt","r");
  for(i=0;i<50;i++)
    a[i]='\0';
  for(i=0;i<50;i++)
    b[i]='\0';
  for(i=0;i<50;i++)
    c[i]='\0';
  for(i=0;i<50;i++)
    d[i]='\0';
  e=fgetc(fp);
	i=0;
	while(e!='$')
	{
		a[i]=e;
		i++;
		e=fgetc(fp);
	}
	//  printf("%s%d\n",a,strlen(a));
	e=fgetc(fp);
	while(e!=EOF)
  {
    b[j]=e;
    j++;
		e=fgetc(fp);
		if(e==EOF)
			break;
  }
	//  printf("%s%d\n",b,strlen(b));
	n=strlen(b)-1;
	m=strlen(a);
  for(i=0;i<n;i++)
  {
    d[i]='0';
  }
 // printf("%s%d\n",a,strlen(a));
  for(i=0;i<n;i++)
  {
    c[i]=a[i];
  }
 // printf("%s%d\n",c,strlen(c));
  for(i=n-1;i<strlen(a);i++)
  {
    j=0;
    if(c[j]!='0')
    {
      for(j=0;j<n;j++)
      {
        c[j-1]=xor(c[j],b[j]);
      //  printf("%c\t",c[j-1]);
      }
  //    printf("%d\t",j-1);
      for(j=n;j<50;j++)
        c[j-1]='\0';
    // printf("%s\n",c);
    }
    else
    {
      for(j=0;j<n;j++)
      {
        c[j-1]=xor(c[j],d[j]);
      }
      for(j=n;j<50;j++)
        c[j-1]='\0';
    //  printf("%s%d\n",c,j-1);
    }
    c[3]=a[i+1];
   // printf("%s%d\n",c,strlen(c));
  }
  for(i=0;i<strlen(c);i++)
	{
		if(c[i]!='0')
			break;
		count=count+1;
	}
	for(i=m-1;i>(m-n);i--)
			a[i]='\0';
	if(count==strlen(c))
		printf("THE MESSAGE IS :%s",a);
	else
		printf("ERROR MESSAGE");
return 1;
}

