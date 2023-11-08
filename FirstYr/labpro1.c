#include<stdio.h>
main()
{
  int max[10],caloc[10],i,n,safe[10],j,avail,t=0,k=0,s[10],ne[10];
  printf("enter no of process");
  scanf("%d",&n);
  printf("\nenter the maximum need and current allocated for each process");
          for(i=0;i<n;i++)
            {
              printf("\nenter for process-%d",i);
              scanf("%d%d",&max[i],&caloc[i]);
            }
        printf("\nenter the total availabilty");
        scanf("%d",&avail);
        for(i=0;i<n;i++)
        {     s[i]=0;
                t+=caloc[i];

              ne[i] = max[i]-caloc[i];


        }
        avail-=t;


          for(i=0;i<n;i++)
{
          for(j=0;j<n;j++)
          {
              if(avail >=ne[j]&&s[j]==0 )
                {
                  s[j]=1;
                  safe[k]=j;
                  k++;
                  avail +=max[j];
                  printf("%d",j);
                }
            }

          }
      if(k==n){
 printf("safe sequence\n<");
      for(j=0;j<n;j++)
      {
        printf("%d\t",safe[j]);
      }
      printf(">");
}
  else
      printf("\ndeadlock occur");
}
        
