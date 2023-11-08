#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"hash.h"
int main()
{
	HashTable HT;
	int ch,ch1;
	char opt[2];
	char SymbolName[11],SegmentName[11],Type[5];
	int Length,Adrs;
	HT = initialize();
	list temp;
	printf("\n 1.Insert\n 2.delete\n 3. Search and modify \n 4.search only \n 5.display ");
  do
	{
	printf("\n Enter the choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n Enter the Symbol Details\n");

			printf("\n Symbol Name : ");
			scanf("%s",SymbolName);
			printf("\n Segment Name : ");
			scanf("%s",SegmentName);
			printf("\n Type : ");
			scanf("%s",Type);
			printf("\n Length : ");
			scanf("%d",&Length);
			printf("\n Address : ");
			scanf("%d",&Adrs);

			if(Search(HT,SymbolName,SegmentName)==NULL)
      {
           Insert(HT,SymbolName,SegmentName,Type,Length,Adrs);
      }
      else
            printf("element already present");
   		break;

		case 2:
      printf("\n enter \n");
			printf("\n Symbol Name  : ");
			scanf("%s",SymbolName);
			printf("\n Segment Name : ");
			scanf("%s",SegmentName);

			if(Search(HT,SymbolName,SegmentName)!=NULL)
      {
          Delete(HT,SymbolName,SegmentName);
          printf("\n Deleted successfully");
      }
      else
         printf("\n Given symbol is not present in Symbol Table");
			break;

     case 3:
        strcpy(Type,"NULL");
        Length = -1;
        Adrs = -1;
        printf("\n Modify the symbol detail");
        printf("\n Symbol Name  : ");
	 		  scanf("%s",SymbolName);
			  printf("\n Segment Name : ");
			  scanf("%s",SegmentName);
        if(Search(HT,SymbolName,SegmentName)!=NULL)
        {
           do
           {
              printf("\n which are the item you want to modify : ");
              printf("\n 1.Type\n 2.Length\n 3.Address ");
              scanf("%d",&ch1);
              if(ch1==1)
              {
                  printf("\n Enter Type : ");
                  scanf("%s",Type);
              }
              else if(ch1==2)
              {
                   printf("\n Enter Length : ");
                   scanf("%d",&Length);
              }
              else if(ch1==3)
              {
                  printf("\n Enter Address : ");
                  scanf("%d",&Adrs);
              }

              printf("\n Are you modify another item (y/n) : ");
              scanf("%s",opt);
           }while(strcmp(opt,"y")==0);
           Modify(HT,SymbolName,SegmentName,Type,Length,Adrs);
        }
        else
            printf("\n The symbol is not presented");
        break;

        case 4:
            printf("\n Search a symbol ");
            printf("\n Symbol Name  : ");
			      scanf("%s",SymbolName);
 			      printf("\n Segment Name : ");
			      scanf("%s",SegmentName);
			      temp = Search(HT,SymbolName,SegmentName);
            if(temp!=NULL)
            {
                printf("\n \tDetail : ");
                printf("\n   Symbol Name   :  %s",temp->SymbolName);
                printf("\n   Segment Name  :  %s",temp->SegmentName);
                printf("\n   Type          :  %s",temp->Type);
                printf("\n   Length        :  %d",temp->Length);
                printf("\n   Address       :  %d",temp->Adrs);
            }
            else
                  printf("\n The symbol is not presented");
            break;

      case 5:
			    Display(HT);
			    break;

		  default:
            printf("\n INVALID CHOICE");
  }

  }while(ch<6);
DeAllocated(HT);
  return 0;
}

