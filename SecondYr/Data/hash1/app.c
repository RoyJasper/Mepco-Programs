#include"hash.h"
main()
{
int b[30];
int s,z,m,i=0,h,n=10,j,k;
while(i!=10)
{
b[i]=-1;
i++;
}
printf("\n\n\t\tWELCOME TO LINEAR HASHING\t");
do
{
printf("\n1.INSERT \n2.DISPLAY \n3.SEARCH \n4.DELETE \n5.EXIT \nENTER YOUR CHOICE : ");
scanf("%d",&z);
switch(z)
{
case 1:
printf("ENTER THE NUMBER OF ELEMENT TO BE INSERTED");
scanf("%d",&k);
for(i=0;i<k;i++)
{
printf("ENTER THE ELEMENT TO BE INSERTED");
scanf("%d",&j);
insert(b,j);
}
printf("\nINSERTION IS DONE SUCCESSFULLY");
break;
case 2:
display(b);
break;
case 3:
printf("ENTER THE ELEMENT TO BE SEARCHED : ");
scanf("%d",&m);
s=search(b,m);
if(s==1)
    printf("\nTHE SEARCH ELEMENT IS PRESENT");
else
    printf("\nTHE SEARCH ELEMENT IS NOT PRESENT");
break;
case 4:
printf("\nENTER THE ELEMENT TO BE DELETED : ");
scanf("%d",&h);
delete(b,h);
break;
case 5:
exit(0);
}
}while(1);
}
