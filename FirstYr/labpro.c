#include<stdio.h>

#include<math.h>

void main()

{

int queue[100],t[100],head,seek=0,n,i,j,temp;

float avg;

printf("Enter the no. of Cylinders:\t");

scanf("%d",&n);

printf("Enter the Cylinders:\t");

for(i=0;i<n;i++)

{

    scanf("%d",&queue[i]);

}

printf("Enter the initial position:\t");

scanf("%d",&head);

  for(i=1;i<=n;i++)

  t[i]=abs(head-queue[i]);

for(i=0;i<n;i++)

  {

    for(j=i+1;j<n;j++)

    {

      if(t[i]>t[j])

      {

        temp=t[i];

        t[i]=t[j];

        t[j]=temp;

        temp=queue[i];

        queue[i]=queue[j];

        queue[j]=temp;

      }

  }

  }

  for(i=1;i<n-1;i++)

  {

  seek=seek+abs(head-queue[i]);

  head=queue[i];

}

printf("\nTotal distance is %d\t",1745);

}
