#include<stdio.h>
int fact (int);
main()
 {
  int n,r;
  float c;
  printf("Enter n and r\n");
  scanf("%d%d",&n,&r);
  c=(fact(n)/(fact(r)*fact(n-r)));
  printf("Combination is %f\n",c);
 }
int fact(int n)
{
  if(n==0||n==1)
  return 1;
 else
  return (n*fact(n-1));

} 
