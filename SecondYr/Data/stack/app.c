#include<head.h>
int main()
{
    int gt,h,f,i;
    char g,j[10],h[10],in[10];
    list top;
    top=(stack)malloc(sizeof(strucct node));
    top.next='NULL';
    do
    {
        printf("\nEnter choice\n1.Push\n2.Pop\n3.Is empty\n4.Make empty\n5.Search\n6.Postfix\n7.Balancing\n8.Infix to postfix\n");
        scanf("%d",&f);
        switch(f)
        {
        case 1:
            printf("\nEnter characters");
            scanf("%c,&g");
            push(g,top);
            break;
        case 2:
            h=pop(top);
            printf("\n%c is deleted",h);
            break;
        case 3:
            i=isempty(top);
            if(i==1)
                printf("\nEmpty");
            else
                printf("\nnot empty");
                break;
        case 4:
            makeempty(top);
            break;
        case 5:
            display(top);
            break;
        case 6:
            printf("\nEnter postfix data");
            scanf("%s",j);
            gt=postfix(j,top);
            printf("\nAns is %d",gt);
            break;
        case 7:
            printf("\nEnter expression");
            scanf("%s",&k);
            balancing(k,top);
            break;
        case 8:
            printf("\nEnter infix expression");
            scanf("%s",in);
            postfix(in,top);
            break;
        default:
            printf("\nEnter valid Expression");
            break;
        }
    }
}
