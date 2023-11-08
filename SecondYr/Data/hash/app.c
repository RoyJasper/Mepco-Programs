#include"hashimp.c"
#include<string.h>
main()
{
  int ch;
  char a[100];
  HashTable h=create(10);
  do
  {
    printf("\n1.Insert\n2.Delete\n3.Find\n4.Display\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter a string:");
        scanf("%s",a);
        insert(a,h);
        break;
      case 2:
        printf("Enter a string:");
        scanf("%s",a);
        Delete(a,h);
        break;
      case 3:
        printf("Enter a string:");
        scanf("%s",a);
        if(find(a,h)!=NULL)
          printf("\nString Found.");
        else
          printf("\nString not Found.");
        break;
      case 4:
        display(h);
        break;
    }
}while(ch<5);
}

