#include<stdio.h>
void uni(int[20],int[20],int,int);
void inter(int[20],int[20],int,int);
void diff(int[20],int[20],int,int);
main()
{
int a[20],b[20],n,i,c,m;
printf("enter number of elements of a and b");
scanf("%d%d",&n,&m);
printf("enter set A:");
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
printf("enter set B:");
for(i=0;i<m;i++)
 scanf("%d",&b[i]); 
uni(a,b,n,m);
inter(a,b,n,m);
diff(a,b,n,m);
}
void uni(int a[20],int b[20],int n,int m)
{
int i,j,flag=0;
printf("A U B is\n");
for(i=0;i<n;i++)
    {
      printf("%d\t",a[i]);
    }
   for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
      {
       if(b[i]!=a[j])
        flag=1;
       else
        {
        flag=0;
         break;
        }
      }
       if(flag==1)
      { 
       printf("%d\t",b[i]);  
      } 
    }

} 
void inter(int a[20],int b[20],int n,int m)
{
int i,j;
printf("\nA intersection B is\n");
for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
      {
       if(a[i]==b[j])
       printf("%d\t",a[i]);  
      } 
    }
}
void diff(int a[20],int b[20],int n,int m)
{
int j,i;
printf("\nA difference B is\n");
for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   { 
    if(a[i]==b[j])
    a[i]=0;
   }
 }
for(i=0;i<n;i++)
 {
  if(a[i]!=0)
  printf("%d\n",a[i]);
 }
}




