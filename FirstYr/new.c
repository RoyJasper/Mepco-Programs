#include<stdlib.h>
#include<stdio.h>
int** transm(int**,int,int);
int main()
{
int **m,r,c,**t,i,j;
printf("Enter the row and column of the matrix:\n");
scanf("%d %d",&r,&c);
m=(int**)malloc(r*sizeof(int*));
printf("Enter the elements of the matrix:\n");
for(i=0;i<r;i++)
 {
 m[i]=(int*)malloc(c*sizeof(int));
 for(j=0;j<c;j++)
  scanf("%d",&m[i][j]);
 }
t=transm(m,r,c);
printf("\n transpose of the given matrix\n");
for(i=0;i<c;i++)
 {
 for(j=0;j<r;j++)
  printf("%d\t",t[i][j]);
 printf("\n");
 }
}
int**transm(int **m,int r,int c)
{
int i,j;
int **a;
a=(int**)malloc(c*sizeof(int*));
for(i=0;i<c;i++)
 {
 a[i]=(int*)malloc(r*sizeof(int));
 for(j=0;j<r;j++)
  a[i][j]=m[j][i];
 }
return a;
}

