#include<stdio.h>
void main()
{
    int cas,x1,x2,y1,y2,i;
    scanf("%d",&cas);
    for(i=1; i<=cas; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x2==y2)
        {
            printf("sad");
        }
        if(x1==x2)
        {
            if(y2>y1)
            {
                printf("up");
            }
            if(y2<y1)
            {
                printf("down");
            }
        }
        if(x2>x1)
        {
            if(y1==y2)
            {
                printf("right");
            }
        }
    }
}
