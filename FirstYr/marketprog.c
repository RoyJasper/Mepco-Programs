#include<stdio.h>
struct market
 {
  int a[10],b,c,n;
  char s[10][10];
 }m;
main()
 {
  int i,b,c,no;
  printf("\nEnter no of stocks\n");
  scanf("%d",&m.n);
  for(i=0;i<m.n;i++)
   {
    printf("\nEnter stock %d name and no of items\n",i+1);
    scanf("%s%d",m.s[i],&m.a[i]);
   }
   while(1)
    {
     printf("\n1.Add item 2.Remove item 3.Avaialable items 4.Exit\n");
     scanf("%d",&no);
     switch(no)
      {
       case 1:
          for(i=0;i<m.n;i++)
            {
             printf("\nEnter the %s and no of items to be added\n",m.s[i]);
             scanf("%d",&b);
             m.a[i]+=b;
             printf("\nThe %s has %d\n",m.s[i],m.a[i]);
            }
            break;
       case 2:
           for(i=0;i<m.n;i++)
           {
             printf("\nEnter the %s and no of items to be removed\n",m.s[i]);
             scanf("%d",&c); 
             m.a[i]-=c;  
             printf("\nThe %s has %d\n",m.s[i],m.a[i]);
           }
             break;
       case 3:
            for(i=0;i<m.n;i++)
             {
              if(m.a[i]==0)
                    printf("\nNo stock\n");
              else 
               printf("\nThe avaialable stocks %s is %d\n",m.s[i],m.a[i]);
             }
             break; 
       case 4: 
            exit(0);
     } 
   }
 }
            
   
