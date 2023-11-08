#include<stdio.h>
int reverse(char[]);
int compare(char[],char[]); 
main()
 {
  int g,h;
  char a[10],b[10],c[10];
  printf("Enter a string to reverse\n");
  scanf("%s",a);
  g=reverse(a);
  if(g==1)
    printf("This is the reversed string\n");
  printf("Enter 2 strings to compare\n");
  scanf("%s%s",b,c); 
  h=compare(b,c);
  if(h==1)
    printf("the strings are equal\n");
  else
   printf("They are not equal\n");
 }
int reverse (char a[10])
 {
  int i,j=0,n=0;
  char b[10];
  for(i=0;a[i]!='\0';i++)
   {
    n=n+1;
   }
  for(i=n-1;i>=0;i--) 
   {
    b[j]=a[i];
    j++;
   }
  printf("%s\n",b);
  return 1;
 }
int compare (char a[10],char b[10])
 {
  int m=0,n=0,i,ch=0;
  for(i=0;a[i]!='\0';i++)
   {
    m=m+1;
   }
  for(i=0;b[i]!='\0';i++)
   {
    n=n+1;
   }
  if(m!=n)
   return 0;
  else
   {
    for(i=0;i<n;i++)
     {
      if(a[i]==b[i])
        ch=1;
      else 
        break;
     }
    return ch;
  }
}

