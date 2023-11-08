#include<stdio.h>
#include<string.h>
struct super
{
 char item[10];
 int q;
}p[20];
main()
{
 int i,j=0,x,y,n,choice,c=0;
 char d[20];
 printf("enter the number of stock items\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("enter the name of the %d item\n",i+1);
  scanf("%s",p[i].item);
  printf("enter the quantity of %s\n",p[i].item);
  scanf("%d",&p[i].q);
 } 
 sam:

 printf("enter the item to change its quantity");
 scanf("%s",d); 
for(i=0;i<n;i++)
 {  
  if((strcmp(p[i].item,d))==0)
  {c=i;break;}
  
 }
 while(1)
 {
 printf("\nenter your choice to change %s\n1.add item\n2.remove item\n3.availability\n4.exit\n",p[c].item);
 scanf("%d",&choice);
 switch(choice)
  {
     case 1:
           printf("enter the item to add in %s\n",p[c].item);
           scanf("%d",&x);
           p[c].q=p[c].q+x;
           printf("total is %d",p[c].q);
           break;
     case 2:
           printf("enter the item to remove in %s\n",p[c].item);
           scanf("%d",&y);
           p[c].q=p[c].q-y;
           printf("total is %d\n",p[c].q);
           break;
     case 3:
           printf("enter availability\n");
           if(p[c].q>0)
           printf("the available amount is %d",p[c].q);
           else
           printf("unavailable\n");
           break;
     case 4:
           j++;
           goto sam;  
           break;
     default:
           printf("invalid choice\n");
           break;
   }
  }
 }
      
