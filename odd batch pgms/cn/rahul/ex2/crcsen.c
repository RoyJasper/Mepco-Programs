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
  char a[50],b[50],c[50],d[50];
  int n,m,i,j;
  fp=fopen("medium.txt","w");
  for(i=0;i<50;i++)
    a[i]='\0';
  for(i=0;i<50;i++)
    b[i]='\0';
  for(i=0;i<50;i++)
    c[i]='\0';
  for(i=0;i<50;i++)
    d[i]='\0';
  printf("ENTER THE BIT SEQUENCE:");
  scanf("%s",a);
  printf("ENTER THE DIVIDEND:");
  scanf("%s",b);
  n=strlen(b);
  m=strlen(a);
  for(i=0;i<n;i++)
  {
    d[i]='0';
  }
  for(i=m;i<(m+(n-1));i++)
  {
    a[i]='0';
  }
  //printf("%s%d\n",a,strlen(a));
  for(i=0;i<n;i++)
  {
    c[i]=a[i];
  }
  //printf("%s%d\n",d,strlen(d));
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
    //  printf("%s\n",c);
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
  //  printf("%s%d\n",c,strlen(c));
  }
  j=0;
  for(i=m;i<strlen(a);i++)
  {
    a[i]=c[j];
    j++;
  }
  printf("%s",a);
  for(i=0;i<strlen(a);i++)
  {
    putc(a[i],fp);
  }
  putc('$',fp);
  for(i=0;i<strlen(b);i++)
  {
    putc(b[i],fp);
  }
return 1;
}

