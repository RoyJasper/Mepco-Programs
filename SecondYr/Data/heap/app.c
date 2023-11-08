int main()
{
    int ch,p,x,i;
    heap h;
    printf("\nEnter the capacity of heap");
    scanf("%d",&x);
    h=create(x);
    if(h==NULL)
        return 0;
    do
    {
        printf("\nEnter choice \n1.Insert\n2.Delete\n3.Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter elements");
            scanf("%d",&x);
            insertit(x,h);
            break;
        case 2:
            printf("%d",deletemax(h));
            break;
        case 3:
            displayit();
            break;
        }
    }while(1);
    return 0;
