#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
 int l,m;
 l=fork();
 m=fork();
 if(l>0)
  printf("\n process A is running ..\n");
 else if(l==0)
  printf("\n process B is running ..\n");
 else if((l==0)&&(m==0))
  printf("\n process D is running ..\n");
 else if((m==0)&&(l>0))
  printf("\n process C is running ..\n");
 else if((l<0)||(m<0))
  printf("\n Error .. in fork\n");
 else 
  return 0;
}
