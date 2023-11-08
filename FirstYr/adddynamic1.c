nclude<stdio.h>

#include<stdlib.h>

main()

{

 int *a,*b,*c,i,j,m,n;

 printf("enter the row and columns");

 scanf("%d%d",&m,&n);

 a=(int*)malloc(m*n*(sizeof(int)));

 b=(int*)malloc(m*n*(sizeof(int)));

 c=(int*)malloc(m*n*(sizeof(int)));

 printf("enter the values of first matrix");

 for(i=0;i<m;i++)

 {

  for(j=0;j<n;j++)

  {

   scanf("%d",((a+(i*n))+j));

  }

 }

 printf("enter the second matrix");

 for(i=0;i<m;i++)

 {

  for(j=0;j<n;j++)

  {

   scanf("%d",((b+(i*n))+j));

  }

 }

 for(i=0;i<m;i++)

 {

  for(j=0;j<n;j++)

  {

   *((c+(i*n))+j)=*((a+(i*n))+j)+*((b+(i*n))+j);

  }

 }

 printf("resultant matrix is\n");

 for(i=0;i<m;i++)

 {

  for(j=0;j<n;j++)

  {

   printf("%d ",*((c+(i*n))+j));

  }

  printf("\n");

 }

}
