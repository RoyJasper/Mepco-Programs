#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search (char *[],int,char[]);
main()
{
 int n,i;
 char word[25],b[25];
 char *w[20];
 printf("enter number of strings");
 scanf("%d",&n);
 printf("enter the strings");
 for(i=0;i<n;i++)
 {
  scanf("%s",word);
  w[i]=(char*)calloc(strlen(word),sizeof(char));
  strcpy(w[i],word);
 }
 printf("enter the elements to be searched");
 scanf("%s",b);
 search(w,n,b); 
}
void search (char *a[20],int n,char b[20])
{
 int i;
 for(i=0;i<n;i++)
 {
  if((strcmp(a[i],b))==0)
	{
  printf("the string is present");
  break;
 }
 }
}
