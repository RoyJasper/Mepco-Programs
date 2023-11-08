#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
int i,j,n,l,u,m,count=0;
char word[25],*w[30],s[20],t[20];
printf("\nEnter number of names\n");
scanf("%d",&n);
printf("Enter %d names in asscending order \n",n);
for(i=0;i<n;i++)
  {
   scanf("%s",word);
   w[i]=(char *)malloc(strlen(word)*sizeof(char));
   strcpy(w[i],word);
  }

printf("\nEnter search string\n");
scanf("%s",s);
l=0;
u=n-1;
while(l<u)
 {
  m=(l+u)/2;
  if(strcmp(s,w[m])==0)
   {
    printf("\n %s is found at %d \n",s,m+1);
    break;
   }
  else if(strcmp(s,w[m])<0)
   u=m-1;
  else
   l=m-1;
 }
}

