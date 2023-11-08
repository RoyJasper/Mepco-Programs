#include<stdio.h>
struct student
{
int age;
char name[100];
int m1;
int m2;
}s[5];
main()
{
int i,t[45];
for(i=0;i<5;i++)
{printf("enter the age,name,m1,m2:");
scanf("%d %s %d %d",&s[i].age,s[i].name,&s[i].m1,&s[i].m2);
t[i]=s[i].m1+s[i].m2;
}
for(i=0;i<5;i++){
printf("age=%d \nname=%s \nm1=%d \nm2=%d \ntotal=%d\n",s[i].age,s[i].name,s[i].m1,s[i].m2,t[i]);
}
}

