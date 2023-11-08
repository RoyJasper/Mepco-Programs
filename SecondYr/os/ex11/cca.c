#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int f[50],i,st,j,len,ch,k;
    char c[50];
    for(i=0;i<50;i++)
    f[i]=0;
    X:
    printf("\nENTER THE FILE NAME:");
    scanf(" %s",c);
    printf("\nENTER THE STARTING BLOCK AND LENGTH OF FILE:");
    scanf("%d%d",&st,&len);
    for(j=st;j<(st+len);j++)
   {
      if(f[j]==0)
      {
        f[j]=1;
        printf("\n%s FILE OCCUPIES BLOCK %d",c,j);
      }
      else
      {
       printf("\nBLOCK %d IS ALLOCATED,FILE %s CAN'T BE ACCOMODATED",j,c);
        break;
      }
    }
    if(j==(st+len))
    printf("\n FILE IS COMPLETELY ALLOCATED TO DISK");
    printf("\n IF YOU WANT TO ALLOCATE FILES PRESS 1");
    scanf("%d",&ch);
    if(ch==1)
    goto X;
    else
    exit(0);
    getch();
}
