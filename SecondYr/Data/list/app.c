#include"head.h"
int main()
{
 int n,p,a,b,c,choice,y,d,e;
 list head;
 char nam[20],f[20],g[20];
 head=(list)malloc(sizeof(struct student));
 while(1)
 {
  printf("\nEnter choice\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Isempty\n6.Locate\n7.Retrive\n8.Swap\n9.Exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:printf("\nEnter no ,position ,name");
         scanf("%d%d%s",&n,&p,nam);
         insert(n,p,nam,head);
         break;
  case 2:printf("\nEnter no and name");
         scanf("%d%s",&n,g);
         a=search(n,g,head);
         if(a==1)
           printf("\nPresent");
         else
           printf("\nnot present");
         break;
  case 3:display(head);
         break;

  case 4:printf("\nEnter no and name");
         scanf("%d%s",&n,f);
        delet(head,n,nam);
         break;
  case 5:b=isempty(head);
         if(b==1)
          printf("\nEmpty");
         else
           printf("\nNot Empty");
         break;
  case 6:printf("\nEnter the no");
         scanf("%d",&n);
         c=locate(n,head);
         if(c!=0)
          printf("\nThe position is %d",c);
         else
          printf("\nnot present");
         break;
  case 7:printf("\nEnter position");
         scanf("%d",&p);
         y=retrieve(p,head);
         printf("\nnumber is %d",y);
         break;
 case 8://printf("\nREVERSAL IN PROCESS");
        printf("Enter 2 position");
        scanf("%d%d",&d,&e);
        swap(d,e,head);
        printf("\nSwaped");
        break;
 case 9:exit(0);
}
}
}
