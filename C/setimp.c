#include"sethead.h"
set makeset(set s)
{
int i,n;
s=(set)malloc(sizeof(struct node));
printf("ENTER THE CAPACITY");
scanf("%d",&n);
s->a=(int*)malloc(sizeof(int)*n);
s->capacity=n;
for(i=1;i<=n;i++)
s->a[i]=0;
return s;
}
set makesize(set s)
{
int i,n;
s=(set)malloc(sizeof(struct node));
printf("ENTER THE CAPACITY");
scanf("%d",&n);
s->a=(int*)malloc(sizeof(int)*n);
s->capacity=n;
for(i=1;i<=n;i++)
s->a[i]=-1;
return s;
}
set unionarbi(set s)
{
int r1,r2;
printf("ENTER THE VALUES");
scanf("%d%d",&r1,&r2);
if(s->a[r2]==0)
s->a[r2]=r1;
return s;
}
set unionhei(set s)
{
int r1,r2;
printf("ENTER THE VALUES");
scanf("%d%d",&r1,&r2);
if(s->a[r1]==s->a[r2])
{
if(s->a[r1]==0&&s->a[r2]==0)
{
s->a[r2]=r1;
s->a[r1]--;
}
else if(s->a[r1]<0&&s->a[r2]<0)
{
s->a[r1]=s->a[r2]+s->a[r1];
s->a[r1]=r1;
}
else if(s->a[r1]>0&& s->a[r2]>0)
{
printf("ALREADY IT IS A SUBSET");
}
}
else if(s->a[r1]<=0&&s->a[r2]<=0)
{
if(s->a[r1]>s->a[r2])
{
s->a[r2]=r1;
}
else
s->a[r1]=r2;
}
return s;
}
set unionsiz(set s)
{
int r1,r2;
printf("ENTER THE VALUES");
scanf("%d%d",&r1,&r2);
if(s->a[r1]>=0||s->a[r2]>=0)
{
printf("ALREADY IT IS A SUBSET");
}
else if(s->a[r1]<=s->a[r2])
{
s->a[r1]=s->a[r1]+s->a[r2];
s->a[r2]=r1;
}
else if(s->a[r1]>s->a[r2])
{
s->a[r2]=s->a[r1]+s->a[r2];
s->a[r1]=r2;
}
return s;
}
void findset(int x,set s)
{
if(s->a[x]<=0)
printf("%d IS THE SET",x);
else
findset(s->a[x],s);
}
void display(set s)
{
int i;
printf("THE ELEMENT ARE");
for(i=1;i<=s->capacity;i++)
{
printf("\n%d->%d",i,s->a[i]);
}
}

