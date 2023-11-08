//#include"set.h"
void makeset(set s)
{
int i,n;
printf("\nEnter the capacity");
scanf("%d",&n);
n=n+1;
s->a=(int*)malloc(sizeof(int)*n);
for(i=1;i<n+1;i++)
{
s->a[i]=0;
}
}
void unionset(set s)
{
int r1,r2;
printf("\nEnter the first value");
scanf("%d",&r1);
printf("\nEnter the second value");
scanf("%d",&r2);
if(s->a[r2]<s->a[r1])
{
s->a[r1]=r2;
}
/*else if(s->a[r2]>s->a[r1])
{
s->a[r2]=r1;
}*/
else if(s->a[r1]==s->a[r2])
{
s->a[r1]--;
s->a[r2]=r1;
}
}
int findset(int x,set s)
{
if(s->a[x]<=0)
return s->a[x];
else
return findset(s->a[x],s);
}
void dis(set s,int n)
{
int i;
printf("\nEnter no of elements");
scanf("%d",&n);
printf("\nThe elements are");
for(i=1;i<n+1;i++)
printf("\n%d==%d",i,s->a[i]);
}

