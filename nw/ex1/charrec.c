#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 FILE *fp;
 int y,z;
 char x[10];
 fp=fopen("ex.txt","r");
 while(fscanf(fp,"%s%d",x,&y)!=EOF)
 {
  z=strlen(x);
  //printf("%d",z);
  if(y==z)
  {
   printf("%s\n",x);
  }
  else
  {
   printf("Error");
   return 1;
  }
 }
 fclose(fp);
}
