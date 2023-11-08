#include"header.h"
void create(int n)
{
e=(struct employee *)malloc(n*sizeof(struct employee *));
}
void getdetail(int n)
{
int i;
for(i=0;i<n;i++)
{
printf("ENTER THE EMPLOYEE NUMBER,EMPLOYEE NAME,BASICPAY");
scanf("%d%s%d",&e[i].empno,e[i].empnm,&e[i].bp);
}
}
void printindi(int n,int a)
{int i;
for(i=0;i<n;i++)
{
if(a==e[i].empno)
{
printf("\nNAME\t%s\nEMPLOYEE NUMBER\t%d\nBASICPAY\t%d",e[i].empnm,e[i].empno,e[i].bp);
}
}
}
void printall(int n)
{
int i;
for(i=0;i<n;i++)
{
printf("\nNAME\t%s\nEMPLOYEE NUMBER\t%d\nBASICPAY\t%d",e[i].empnm,e[i].empno,e[i].bp);
}
}
void printsal(int n)
{
int i,b;
for(i=0;i<n;i++)
{
e[i].hra=e[i].bp*0.2;
e[i].da=e[i].bp*0.1;
e[i].pf=e[i].bp*0.05;
e[i].sal=e[i].bp+e[i].hra+e[i].da-e[i].pf;
}
printf("\nENTER THE EMPLOYEE NUMBER TO BE DISPLAYED");
scanf("%d",&b);
for(i=0;i<n;i++)
{
if(b==e[i].empno)
{
printf("\nTHE SALARY IS %f",e[i].sal);
}
}
}
void topper(int n)
{
 int i;
 float m;
 m=e[0].sal;
 for(i=0;i<n;i++)
{
 if(e[i].sal>m)
 m=e[i].sal;
 }
 for(i=0;i<n;i++)
{
 if(m==e[i].sal)
printf("\nTHE HIGHEST SALARY PERSON IS %s",e[i].empnm);
}
}

