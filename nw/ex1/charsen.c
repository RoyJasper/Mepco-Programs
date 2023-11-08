#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[20][20];
int get();
FILE *fp;
void make(int);
int count(int);
main()
{
 int n=get();
 make(n);
}
int get()
{
 int ans,i=1;
 do
 {
  printf("Enter word\n");
  scanf("%s",a[i]);
  printf("Continue?? 1.Yes 2.No");
  scanf("%d",&ans);
  //if(a[i]==' ')
    i++;
 }while(ans!=2);
 return i;
}
void make(int n)
{
 int i=0;
 fp=fopen("ex.txt","w");
 for(i=0;i<n;i++)
 {
  fprintf(fp," %s %d",a[i],(strlen(a[i])));
 }
 fclose(fp);
}

