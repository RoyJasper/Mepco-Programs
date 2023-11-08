#include<stdio.h>
main()
{
char acceptance[60];
int i,count,n;
printf("Enter the no. of students:\n");
scanf("%d",&n);
printf("Enter acceptance of each student as Y/N:\n");
for(i=0,count=0;i<n;i++)
 {
 scanf(" %c",&acceptance[i]);
 if(acceptance[i]=='y'||acceptance[i]=='Y')
  count++;
 else
  count=count+0;
 }
printf("No. of students accepted is %d\n",count);
}

