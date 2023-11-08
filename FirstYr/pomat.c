#include<stdio.h>
#include<stdlib.h>
main()
{
int *a,*b,*c,r,c1,i,j;
printf("\nEnter number of rows and columns\n");
scanf("%d%d",&r,&c1);
a=(int *)malloc(r*c1*sizeof(int));
b=(int *)malloc(r*c1*sizeof(int));
c=(int *)malloc(r*c1*sizeof(int));
if((a==NULL)||(c==NULL)||(b==NULL))
 {
  printf("No memory");
  exit(1);
 }
else
 {
  printf("\nEnter matrix A\n");
  for(i=0;i<r;i++)
    { 
    for(j=0;j<c1;j++)
      {
       scanf("%d",((a+(i*c1))+j));
       
      }
    
    }
  printf("Enter matrix B\n");
  for(i=0;i<r;i++)
    {
    for(j=0;j<c1;j++)
     {
       scanf("%d",((b+(i*c1))+j));
      
     }
      
    }
  for(i=0;i<r;i++)
    {
    for(j=0;j<c1;j++)
      *((c+(i*c1))+j)=*((a+(i*c1))+j)+*((b+(i*c1))+j);
    }
  printf("Sum is\n");
  for(i=0;i<r;i++)
    {
    for(j=0;j<c1;j++)
      {
       printf("%d\t",*((c+(i*c1))+j));
      }
     printf("\n");
    }
  exit(0);
 }
}
