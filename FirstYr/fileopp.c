#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp1,*fp2;
int n;
char c,a[10],b[10];
printf("Enter name of file 1");
scanf("%s",a);
printf("Enter name of file 2");
scanf("%s",b);
while(n!=4)
{
printf("\nEnter your choice\n1.Read a file\n2.Write file\n3.Append a file\n4.exit");
scanf("%d",&n);
switch(n)
{
   case 1:
    fp1=fopen(a,"r");
    c=getc(fp1);
    while(c!=EOF)
     {
      c=getc(fp1);
     }
    fclose(fp1);
    printf("File is read successfully");
   break;
   case 2:
    fp1=fopen(a,"r");
    fp2=fopen(b,"w");
    c=getc(fp1);
    while(c!=EOF)
     {
     putc(c,fp2);
     c=getc(fp1);
     }
    fclose(fp1);
    fclose(fp2);
    printf("File successfully copied");     
   break;
   case 3:
    fp1=fopen(a,"r");
    fp2=fopen(b,"a");
    c=getc(fp1);
    while(c!=EOF)
     {
     putc(c,fp2);
     c=getc(fp1);
     }
    fseek(fp2,0,SEEK_SET);
     c=getc(fp2);
     while(c!=EOF)
     { 
      putchar(c);
      c=getc(fp1);
     }
    fclose(fp1);
    fclose(fp2);
    printf("File successfully copied");  
   break;
    case 4:
   printf("Thank you....");
    break;
   exit(0);
 }
}
}
