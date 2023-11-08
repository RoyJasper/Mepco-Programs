#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void allocatememory(int);
void scandetails(int);
void particularstudent(int,int);
void printall();
void top(int);
void rank(int);
void print(int);
struct student
{
 int m1,m2,m3,tot,rank,rno;
 float cgpa,avg;
 char name[15];
}*s;
main()
{
int n,ch,crno;
printf("Enter no of students");
scanf("%d",&n);
allocatememory(n);
scandetails(n);
 while(ch!=5)
  {
   printf("Enter your choice\n1.Data of particular student\n2.Data of all students\n3.get rank\n4.topper of class\n5.exit");
   scanf("%d",&ch);
   switch(ch)
    {
     case 1:
       printf("Enter roll no");
       scanf("%d",&crno);
       particularstudent(crno,n);
       break;
     case 2:
       printall();
       break;
     case 3:
  //     rank(n);
       break;
     case 4:
       top(n);
     case 5:
       break;
     default:
       printf("Invalid input");
       break;
     }
  }
}
void allocatememory(int n)
 {
	s=(struct student*)malloc(n*sizeof(struct student));
 }
void scandetails(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter name of %d student\n ",i+1);
        scanf("%s",s[i].name);
        printf("Enter roll no\n ");
        scanf("%d",s[i].rno);
        printf("Enter 3 marks\n");
        scanf("%d%d%d",&s[i].m1,&s[i].m2,s[i].m3);
        s[i].tot=s[i].m1+s[i].m2+s[i].m3;
        s[i].avg=s[i].tot/3;
        s[i].cgpa=s[i].tot/30;
    }
}
void particularstudent(int c,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(c==s[i].rno)
        {
            print(i);
          ///  printf("Name is %s\n",s[i].name);
           //// printf("Marks are %d %d %d \n",s[i].m1,s[i].m2,s[i].m3);
           /// printf("total and average is %d %f\n",s[i].tot,s[i].avg);
           /// printf("cgpa is %f",s[i].cgpa);

        }
    }
}
void print(int i)
{
            printf("Name is %s\n",s[i].name);
            printf("Marks are %d %d %d \n",s[i].m1,s[i].m2,s[i].m3);
            printf("total and average is %d %f\n",s[i].tot,s[i].avg);
            printf("cgpa is %f",s[i].cgpa);
}
void printall(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        print(i);
        printf("Rank is %d\n",s[i].cgpa);
    }
}
void top(int n)
{
    int max,i,maxi;
    max=s[0].cgpa;
    maxi=0;
    for(i=0;i<n;i++)
    {
        if(max>s[i].cgpa)
        {
            max=s[i].cgpa;
            maxi=i;
        }
    }
    printf("Topper is %d\n",s[maxi].name);
}
/*void rank(int n)
{
    char a[10];
    int i,j,k,r=1,c=0;
    float *tot;
    tot=(float *)malloc(n*sizeof(float tot));
    for(i-0;i<n;i++)
    {
        tot[i]=s[i].tot;
    }
    for(i=0;i<n;i++)
    {
        if(tot[i]<tot[i+1])
        {
            c-tot[i];
            tot[i]-tot[i+1];
            tot[i+1]=c;
        }
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
   //      if(   ==s[k].tot)
         {
             s[k].rank=r;
             ++r;
         }
        }
    }
    printf("Enter the name of student");
    scanf("%s",a);
    for(i=0;i<n;i++)
    {
        if(strcmp(a,s[i].name)==0)
            {
                printf("%d",s[i].rank);
            }
    }
}

*/
