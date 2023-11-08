#include<stdio.h>
#include<stdlib.h>
main()
{
  int ***ind,i,a,b,c,j,k,s;
  printf("\nEnter the no of states");
  scanf("%d",&a);
  for(i=0;i<a;i++)
{
 ind=(int ***)malloc(a*sizeof(int **));
 printf("\nEnter the no of district");
 scanf("%d",&b);
 for(j=0;j<b;j++)
{
 ind[j]=(int **)malloc(b*sizeof(int *));
 printf("\nEnter the no of cities");
 scanf("%d",&c);
 for(k=0;k<c;k++)
{
 ind[j][k]=(int *)malloc(c*sizeof(int));
 printf("\nEnter the population");
 scanf("%d",&ind[i][j][k]);
 }
}s=0;
 for(j=0;j<b;j++)
{
 for(k=0;k<c;k++)
{
  s=s+ind[i][j][k];
}
}
printf("\nThe %d states contains %d population",i+1,s);
}
}

