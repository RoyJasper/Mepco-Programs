#include<stdio.h>
#include<string.h>
main()
{
char a[20][20],t[20][20];
int i,j,n;
printf("Enter no of names\n");
scanf("%d",&n);
printf("Enter %d  names\n",n);
for(i=0;i<n;i++)
scanf("%s",&a[i]);
for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
   { 
     if(strcmp(a[i],a[j])>0)
       {
        strcpy(t[i],a[i]);
        strcpy(a[i],a[j]);
        strcpy(a[j],t[i]);
        }
    }
 }
printf("the city names in alphabetical order is\n ");
for(i=0;i<n;i++)
printf("\n%s",a[i]);
}
