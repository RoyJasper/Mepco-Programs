#include<stdio.h>
#include<stdlib.h>
main()
{
int n,l,c,m,u,i,j,s;
int *p;
printf("\nEner no of elements\n");
scanf("%d",&n);
p=(int *)malloc(n*sizeof(int));
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
  scanf("%d",(p+i));
for(i=0;i<n;i++)
  {
   for(j=i+1;j<n;j++)
    {
     if((*(p+i))>(*(p+j)))
      {
       c=(*(p+i));
       (*(p+i))=(*(p+j));
       (*(p+j))=c;
      }
    }
	}
printf("Enter search character\n");
scanf("%d",&s);
c=0;
l=0;
u=n-1;
m=(l+u)/2;
while(l<=u)
 {
  m=((l+u)/2);
  if((*(p+m))==s)
   {
    printf("The numbber %d is present",s);
    c=1;
    break;
   }
  else if((*(p+m))>s)
     l=m+1;
  else
     u=m-1;
  }
if(c==0)
 printf("Element is present");		   
 
}




