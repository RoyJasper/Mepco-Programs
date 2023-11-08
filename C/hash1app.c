#include"hash1head.h"
main()
{
hash h1,h2;
int n,h,choice,t[10],i=0,j=0;
printf("ENTER THE SIZE OF TABLE");
scanf("%d",&n);
h1=(hash)malloc(sizeof(struct node));
h1->size=n;
while(i!=h1->size)
{
h1->a[i]-1;
i++;
}
h2=(hash)malloc(sizeof(struct node));
h2->size=n;
while(i!=h2->size)
{
h2->a[j]-1;
j++;
}
while(1)
{
star:
printf("1.LINEAR 2.QUADRATIC 3.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:
while(1)
{
printf("1.INSERT 2.DELETE 3.DISPLAY 4.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
h1=insert(h1,h);
break;
case 2: printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
h1=delet(h1,h);
break;
case 3:
display(h1);
break;
case 4: goto star;
break;
}
}
break;
case 2:
while(1)
{
printf("1.INSERT 2.DELETE 3.DISPLAY 4.EXIT ENTER THE CHOICE");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
h2=insert(h2,h);
break;
case 2: printf("ENTER THE ELEMENT TO BE INSERT");
scanf("%d",&h);
h2=delet(h2,h);
break;
case 3:
display(h2);
break;
case 4: goto star;
break;
}
}
break;
case 3: exit(0);
break;
}
}
}



