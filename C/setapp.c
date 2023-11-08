#include"sethead.h"
main()
{
set s1,s2,s3;
int choice,e;
s1=(set)malloc(sizeof(struct node));
while(1)
{
star:
printf("1.ARBITARY 2.HEIGHT 3.SIZE 4.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
while(1)
{
printf("1.MAKESET 2.UNION 3.FINDSET 4.DISPLAY 5.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1: s1=makeset(s1);
break;
case 2:	s1=unionarbi(s1);
break;
case 3:	printf("ENTER THE SEARCH NUMBER");
scanf("%d",&e);
if(e>s1->capacity)
{
printf("NOT POSSIBLE");
}
else
findset(e,s1);
break;
case 4: display(s1);
break;
case 5:	goto star;
break;
}
}
break;
case 2:
while(1)
{
printf("1.MAKESET 2.UNION 3.FINDSET 4.DISPLAY 5.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1: s2=makeset(s2);
break;
case 2: s2=unionarbi(s2);
break;
case 3: printf("ENTER THE SEARCH NUMBER");
scanf("%d",&e);
if(e>s2->capacity)
{
printf("NOT POSSIBLE");
}
else
findset(e,s2);
break;
case 4: display(s2);
break;
case 5: goto star;
break;
}
}
break;
case 3:
while(1)
{
printf("1.MAKESET 2.UNION 3.FINDSET 4.DISPLAY 5.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1: s3=makesize(s3);
break;
case 2: s3=unionsiz(s3);
break;
case 3: printf("ENTER THE SEARCH NUMBER");
scanf("%d",&e);
if(e>s3->capacity)
{
printf("NOT POSSIBLE");
}
else
findset(e,s3);
break;
case 4: display(s3);
break;
case 5: goto star;
break;
}
}
break;
case 4: exit(0);
break;
}
}
}
