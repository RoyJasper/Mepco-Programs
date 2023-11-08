#include<stdio.h>
#include<string.h>
main()
{
 int n,i,j;
 char a[20][20],c[20];
 printf("enter number of cities you want to enter");
 scanf("%d",&n);
 printf("enter cities");
 for(i=0;i<n;i++)
{
 scanf("%s",a[i]);
}
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(strcmp(a[i],a[j])>0)
   {
    strcpy(c,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],c);
   }
  }
 }
  printf("The city names are sorted as follows\n");
   for(i=0;i<n;i++)
   {
    printf("%s\n",a[i]);
   }
  }

