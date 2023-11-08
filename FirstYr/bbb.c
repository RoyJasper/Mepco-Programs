#includt
<stdio.h>
int reverse(char[]);
int compare(char[],char[]);
main()
{
 int e,f;
 char a[20],b[20],c[20],d[20];
 printf("enter the string to reverse");
 scanf("%s",a);
 printf("enter two stings to compare");
 scanf("%s%s",c,d);
 e=reverse(a);
 if(e==1)
 printf("is the reversed string");
 f=compare(c,d);
 if(f==0)
 printf("\nthe strings are different");
 else
 printf("\nthe strings are equal");
}
int reverse(char a[20])
{
 char b[20];
 int i,j=0,h=0;
 for(i=0;a[i]!='\0';i++)
 h=h+1;
 for(i=h-1;i>=0;i--)
 {
  b[j]=a[i];
  j++;
 }
 printf("%s ",b);
 return 1;
}
int compare(char c[20],char d[20])
{
 int i,y=0,v=0,x=0;
 for(i=0;c[i]!='\0';i++)
 {
  y=y+1;
 }
 for(i=0;d[i]!='\0';i++)
 {
  v=v+1;
 }
 if(v!=y)
 return 0;
 else
 {
  for(i=0;i<y;i++)
  {
   if(d[i]==c[i])
   {
    x=x+1;
   }  
   else
   {
    break;
   }
  }
  if(x==v)
  return 1;
  else
  return 0;
 } 
}
                                                                                                                                                          
 
