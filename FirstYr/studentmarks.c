#include<stdio.h>
#include<stdlib.h>
struct student
{
 int no,m1,m2,m3,t;
 float avg;
 char a[10];
}s[10];
main()
{
 int n,i,ch=0;
 printf("Enter no of students");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  {
   printf("Enter\tName of student %d\n",i+1);
   scanf("%s",s[i].a);
   printf("Enter roll no\n");
   scanf("%d",&s[i].no);

   printf("Enter the marks of %d subjects \n");
   scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
   s[i].t=(s[i].m1+s[i].m1+s[i].m1);
   s[i].avg=(s[i].t/3);
  }
 for(i=0;i<n;i++)
  {
   printf("\nMarks before re-evaluation\nName:%s\nMark1=%d\tMark2=%d\tMark3=%d\tTotal=%d\tAverage=%f\t\n",s[i].a,s[i].m1,s[i].m2,s[i].m3,s[i].t,s[i].avg);
  }
 for(i=0;i<n;i++)
 {
  if(s[i].m1<50)
    {
    printf("Enter re-evaluated mark for student %d in sublect 1",i+1);
    scanf("%d",&s[i].m1);
    s[i].t=(s[i].m1+s[i].m1+s[i].m1);
    s[i].avg=(s[i].t/3);
    }
   if(s[i].m2<50)
    {
    printf("Enter re-evaluated mark for student %d in sublect 2",i+1);
    scanf("%d",&s[i].m2);
    s[i].t=(s[i].m1+s[i].m1+s[i].m1);
    s[i].avg=(s[i].t/3);
    } 
   if(s[i].m3<50)
    {
    printf("Enter re-evaluated mark for student %d in sublect 3",i+1);
    scanf("%d",&s[i].m3);
    s[i].t=(s[i].m1+s[i].m1+s[i].m1);
    s[i].avg=(s[i].t/3);
    }
 }
  for(i=0;i<n;i++)
  {
   printf("\nMarks after re-evaluation\nName:%s\nMark1=%d\tMark2=%d\tMark3=%d\tTotal=%d\tAverage=%f\t\n",s[i].a,s[i].m1,s[i].m2,s[i].m3,s[i].t,s[i].avg);
  }
}

