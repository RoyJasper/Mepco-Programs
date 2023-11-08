#include<string.h>
#include<stdio.h>
struct student
{
 char name[20];
 int rollno,mark1,mark2,mark3,total,average;
}s[15];
main()
{
 int n,i;
 printf("enter the number of students"); 
 scanf("%d",&n);
 for(i=0;i<n;i++)
 { 
  printf("enter the name,roll no,mark1,mark2,mark3 of %d student",i+1);
  scanf("%s%d%d%d%d",s[i].name,&s[i].rollno,&s[i].mark1,&s[i].mark2,&s[i].mark3);
  if((s[i].mark1>=50)&&(s[i].mark2>=50)&&(s[i].mark3>=50))
  {
   s[i].total=s[i].mark1+s[i].mark2+s[i].mark3;
   s[i].average=s[i].total/3;
   printf("\nname:%s\nroll no:%d\ntotal:%d\naverage:%d",s[i].name,s[i].rollno,s[i].total,s[i].average);
  }
  else
  {
   if(s[i].mark1<50)
	 {
    printf("enter the revaluation mark for mark 1");
    scanf("%d",&s[i].mark1);
	 }
   if(s[i].mark2<50)
	 { 
    printf("enter the revaluation mark for mark 2");
    scanf("%d",&s[i].mark2);
	 }
   if(s[i].mark3<50)
	 {
    printf("enter the revaluation mark for mark 3");
    scanf("%d",&s[i].mark3);
	 }
   s[i].total=s[i].mark1+s[i].mark2+s[i].mark3;
   s[i].average=s[i].total/3;
   printf("the mark after re-evaluation\nname:%s\nroll no:%d\ntotal:%d\naverage:%d",s[i].name,s[i].rollno,s[i].total,s[i].average);
  }
 }
}
     
   
  
 
