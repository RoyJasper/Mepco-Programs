#include<stdio.h>
main()
{
 int n,i,j;
 float gpa[60],temp;
 printf("Enter no. of students in class:");
 scanf("%d",&n);
 printf("Enter gpa of students:");
 for(i=0;i<n;i++)
  scanf("%f",&gpa[i]);
  for(i=0;i<n-1;i++)
   for(j=0;j<n-1;j++)
    if(gpa[j]<gpa[j+1])
    {
     temp=gpa[j];
     gpa[j]=gpa[j+1];
     gpa[j+1]=temp;
    }
    printf("Top 5 gpa's are:"); 
  for(i=0;i<5;i++)
  printf(" % 0.1f,",gpa[i]);
 printf("\b");
}
                            
