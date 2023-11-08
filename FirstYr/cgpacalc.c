#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
 float cgpa[50];
 char name[50][50];
 int r[50];
 }*s;
main()
{
 int f,i=0,j=0,t=0,w=0,y,z=0,m,n,k,l=0,d=0;
 char x[20];
 s=(struct student*)malloc(1*sizeof(struct student));
 printf("Enter total no of student in sec  1\n");
 scanf("%d",&m);
 printf("Enter total no of students in sec 2\n");
 scanf("%d",&n);
 f=m+n;
 for(j=0;j<f;j++)
 {
  if(i<m)
  {
  printf("Enter Details For %d student in 1 sec\n",(i+1));
  i++;
  }
  else if(t<n)
  {
  printf("Enter details for %d student in 2 sec\n",(t+1));
  t++;
  }
  printf("Name:\n");
  scanf("%s",s[0].name[j]);
  printf("CGPA\n");
  scanf("%f",&s[0].cgpa[j]);
  printf("Roll no:\n");
  scanf("%d",&s[0].r[j]);
  }
for(k=0;k<f;k++)
{
 for(d=k+1;d<f;d++)
{
  if(s[l].cgpa[k]>s[l].cgpa[d])
  {
   w=s[l].cgpa[k];
   s[l].cgpa[k]=s[l].cgpa[d];
   s[l].cgpa[d]=w;
   strcpy(x,s[l].name[k]);
   strcpy(s[l].name[k],s[l].name[d]);
   strcpy(s[l].name[d],x);
   y=s[l].r[k];
   s[l].r[k]=s[l].r[d];
   s[l].r[d]=y;
   }
  }
}
 printf("Sorted list is :\n");
 for(z=f-1;z>=0;z--)
 {
  printf("CGPA:%f\tNAME:%s\tROLL NO:%d\n",s[0].cgpa[z],s[0].name[z],s[0].r[z]);
  }
 }
     
