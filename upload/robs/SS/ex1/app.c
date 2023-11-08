#include"head.h"
main()
{
  table tt;
  tt=initialize();
  int i,choice;
  list t;
  int length,address;
  char name[20],type[20];
  while(1)
  {
    printf("\n1.INSERT\n2.SEARCH\n3.MODIFY\n4.DELETE\n5.DISPLAY\n6.EXIT\nENTER THE CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("ENTER THE NAME,TYPE,ADDRESS,LENGTH:\n");
        scanf("%s%s%d%d",name,type,&address,&length);
        i=insert(name,type,address,length,tt);
        if(i==1)
          printf("\nINSERTED SUCCESSFULLY");
        else
          printf("\nNOT INSERTED SUCCESSFULLY");
        break;
      case 2:
        printf("ENTER THE NAME:");
        scanf("%s",name);
        t=search(name,tt);
        if(t!=NULL)
          printf("DATA IS FOUND");
        else
          printf("NOT FOUND");
        break;
      case 3:
        printf("ENTER THE NAME WHICH IS TO MODIFY");
        scanf("%s",name);
        printf("ENTER WHICH IS TO MODIFY TYPE OR ADDRESS");
        scanf("%s",type);
        if(strcmp(type,"type")==0)
        {
          printf("ENTER THE VALUE FOR TYPE:");
          scanf("%s",type);
          i=modify(name,type,tt);
          if(i==1)
            printf("MODIFIED");
          else
            printf("NOT MODIFIED");
        }
        else
        {
          printf("ENTER THE VALUE FOR ADDRESS:");
          scanf("%d",&address);
          i=modi(name,address,tt);
          if(i==1)
            printf("MODIFIED");
          else
            printf("NOT MODIFIED");
        }
        break;
      case 4:
        printf("ENTER THE NAME");
        scanf("%s",name);
        i=delete(name,tt);
        if(i==1)
          printf("DELETED");
        else
          printf("NOT DELETED");
        break;
      case 5:
        display(tt);
        break;
      case 6:
        exit(0);
    }
  }
}

