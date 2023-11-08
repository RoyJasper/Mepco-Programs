#include<stdio.h>
#include<stdlib.h>
int **transpose(int **,int,int);
main()
{
int **mat , **transmat;
int i,j,row,col;
printf("\nEnter the row and column size of matrix");
scanf("%d%d",&row,&col);
printf("\nEnter the elements of the matrix");
mat=(int **)malloc(row * sizeof(int *));
for(i=0;i<row;i++)
{
mat[i]=(int *)malloc(col * sizeof(int));
for(j=0;j<col;j++)
{
scanf("%d",&mat[i][j]);
}
}
transmat=transpose(mat,row,col);
printf("\nResultant Matrix\n");
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
printf("%d\t",transmat[i][j]);
}
printf("\n");
}
}
int **transpose(int **matrix,int row ,int col)
{
int **trans;
int i,j;
trans=(int **)malloc(col * sizeof(int *));
for(i=0;i<col;i++)
{
trans[i]=(int *)malloc(row * sizeof(int));
for(j=0;j<row;j++)
{
trans[i][j]=matrix[j][i];
}
}
return trans;
}
