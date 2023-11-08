#include<stdio.h>
#include<stdlib.h>
main()
{
int n,*a,i,s=0;
printf("enter the no. of elements of array \n");
scanf("%d",&n);
a=(int *)malloc(n*sizeof(int));
if(a==NULL)
{
printf("memory allocation unsuccesful \n");
exit(0);
}
printf("enter the array elements one by one \n");
for(i=0;i<n;i++)
{
scanf("%d",(a+i));
}
printf("array elements in reverse order : \n");
for(i=n-1;i>=0;i--)
{
printf("%d \t",*(a+i));
}}
