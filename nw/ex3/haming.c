#include<stdio.h>
#include<math.h>
int main()
{
    int arr1[30],array[20],nr1[10],nr2[10],nr3[10],nr4[10],xch[10],arr[30];
    int a,i=0,p,m,r,plc,j=0,c=0,x=0;
    FILE *fp;
    printf("Enter data\n");
    scanf("%d",&a);
    p=a;
    while(p!=0)
    {
        p=a%10;
        a=a/10;
        arr1[i]=p;
        i++;
        m=i;
    }
    for(i=m; i>0; i++)
    {
        arr[j]=arr1[i];
        j++;
    }
    for(i=0; i<20; i++)
    {
        if((pow(2,i))>=(m+i+1))
        {
            r=i;
            break;
        }
    }
    for(i=0; i<(m+r); i++)
    {
        plc=(pow(2,i));
        if(plc<(m+r))
            array[plc]='$';
    }
    for(i=0; i<(m+r); i++)
    {
        if(array[i]!='$')
        {
            array[i]=arr[j];
            j++;
        }
    }
    int r1[8]={1,3,5,7,9,11,13,15},r2[8]={2,3,6,7,10,11,14,15},r3[8]={4,5,6,7,12,13,14,15},r4[8]={8,9,10,11,12,13,14,15};
    for(i=0; i<8; i++)
    {
        nr1[i]=array[r1[i]];
        nr2[i]=array[r2[i]];
        nr3[i]=array[r3[i]];
        nr4[i]=array[r4[i]];
    }
    //--------------
    for(j=0;j<8;j++)
    {
        if(nr1[j]==1)
            c++;
    }
    for(j=0;j<8;j++)
    {
        if(nr1[j]=='$')
        {
            if(c%2==1)
            {
                nr1[j]=1;
                xch[x]=1;
                x++;
                break;
            }
            if(c%2==0)
            {
                nr1[j]=0;
                xch[x]=0;
                x++;
                break;
            }
        }
    }
    c=0;
    //--------------
    for(j=0;j<8;j++)
    {
        if(nr2[j]==1)
            c++;
    }
    for(j=0;j<8;j++)
    {
        if(nr2[j]=='$')
        {
            if(c%2==1)
            {
                nr2[j]=1;
                xch[x]=1;
                x++;
                break;
            }
            if(c%2==0)
            {
                nr2[j]=0;
                xch[x]=0;
                x++;
                break;
            }
        }
    }
    c=0;
    //--------------
    for(j=0;j<8;j++)
    {
        if(nr3[j]==1)
            c++;
    }
    for(j=0;j<8;j++)
    {
        if(nr3[j]=='$')
        {
            if(c%2==1)
            {
                nr3[j]=1;
                xch[x]=1;
                x++;
                break;
            }
            if(c%2==0)
            {
                nr3[j]=0;
                xch[x]=0;
                x++;
                break;
            }
        }
    }
    c=0;
    //--------------
    for(j=0;j<8;j++)
    {
        if(nr4[j]==1)
            c++;
    }
    for(j=0;j<8;j++)
    {
        if(nr4[j]=='$')
        {
            if(c%2==1)
            {
                nr4[j]=1;
                xch[x]=1;
                x++;
                break;
            }
            if(c%2==0)
            {
                nr4[j]=0;
                xch[x]=0;
                x++;
                break;
            }
        }
    }
    c=0;
    j=0;
    for(i=0; i<(m+r); i++)
    {
        plc=(pow(2,i));
        if(plc<(m+r))
        {
            array[plc]=xch[j];
            j++;
        }
    }

    fp=fopen("ham.txt","w");

    for(i=0; i<(m+r); i++)
    {for(i=0; i<(m+r); i++)
    {
        printf("%d",array[i]);
    }
        putc(array[i],fp);
        //fprintf("%d",array[i]);
    }
    fclose(fp);
    return 0;
}
