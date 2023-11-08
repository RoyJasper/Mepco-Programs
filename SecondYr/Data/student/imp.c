#include"head.h"
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
        scanf("%d",&s[i].rno);
        printf("Enter 3 marks\n");
        scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
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
/*void top(int n)
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
    printf("Topper is %s\n",s[i].name);
}
void rank(int n)
{
    char a[10];
    int i,j,k,r=1,c=0;
    int *tot;
    tot=(int *)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        tot[i]=s[i].tot;
    }
    for(i=0;i<n;i++)
    {
        if(tot[i]<tot[i+1])
        {
            c=tot[i];
            tot[i]=tot[i+1];
            tot[i+1]=c;
        }
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
         if(s[j].tot==s[k].tot)
         {
             s[k].rank=r;
             r++;
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
}*/
void rank(int n)
{
 int i,j,c;
 printf("enter the roll no");
 scanf("%d",&c);
 struct student t;
 for(i=0;i<n;i++)
 {
  for(j=1;j<n;j++)
  {
   if(s[i].tot<s[j].tot)
   {
    t=s[j];
    s[j]=s[i];
    s[i]=t;
   }
  }
 }
 for(i=0;i<n;i++)
 {
  if(c==s[i].rno)
  printf("the rank of roll no %c is:%d",c,i+1);
  s[i].rank=i+1;
 }
}
void top(int n)
{
 rankcalc(n);
 int i;
 for(i=0;i<n;i++)
 {
  if(s[i].rank==1)
  {
   printf("\n*****our class topper is*****\n");
   printf("name:%s\n",s[i].name);
   printf("roll no:%d\n",s[i].rno);
   printf("total is:%d\n",s[i].tot);
  }
 }
}
void rankcalc(int n)
{
 int i,j,c,k=1;
 struct student t;
 for(i=0;i<n;i++)
 {
  for(j=1;j<n;j++)
  {
   if(s[i].tot<s[j].tot)
   {
    t=s[j];
    s[j]=s[i];
    s[i]=t;
    for(i=0;i<n;i++)
    {
     s[i].rank=k;
     k++;
    }
   }
  }
 }
}

