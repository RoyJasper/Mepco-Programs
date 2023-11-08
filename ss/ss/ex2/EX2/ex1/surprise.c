#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int fd=1,i=0,j=1,h=1,gaga,m=1,x,k,n,f;
char a[15][10]={"main","void","return","int","float","char","case","scanf","printf","struct","typedef","for","while","if","else"};
FILE *fp;
									//	printf("entre les ");
									//	scanf("%d",&gaga);
fp=fopen("sample.txt","r");
char s[10],var[10][10],ch,temp[10],key[10][10];
ch=fgetc(fp);
//rintf("%c",ch);
while(ch!=EOF)
{
	x=(int)ch;
	h++;
  if(x>=32&&x<=48)
		{
			s[i]=x;
			i++;
			ch=fgetc(fp);
		}
	else
		{
			temp[j]=ch;
			j++;
			for(k=0;k<15;k++)
					{
							if(strcmp(a[i],temp)==0)
							{
									strcpy(key[m],temp);
									m++;
							}
							else
							{
									strcpy(var[n],temp);
									n++;
							}
					}
			ch=fgetc(fp);
		}
	//ch=fgetc(fp);
}
printf("SPECIAL CHARACTERS ARE");
for(f=0;f<i;f++)
{
printf("%c",s[f]);
}
printf("SPECIAL KEYWORDS ARE");
for(f=0;f<m;f++)
{
printf("%s",key[m]);
}
printf("VARIABLES ARE");
for(f=0;f<n;f++)
{
printf("%s",var[n]);
}
}
