#include<stdio.h>
#include<math.h>
main()
{
float num[50],sd;
int n,i;
float avg,sum=0;
printf("Enter the number of numbers:\n");
scanf("%d",&n);
printf("Enter set of numbers:\n");
for(i=0;i<n;i++)
  {
  scanf("%f",&num[i]);
  sum=sum+num[i];
  }
avg=sum/n;
for(i=0,sum=0;i<n;i++)
  sum=sum+pow(num[i]-avg,2);
sd=pow(sum/n,0.5);
printf("Standard Deviation is %f \n",sd);
}

