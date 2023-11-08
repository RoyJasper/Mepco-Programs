#include<stdio.h> 
#include<stdlib.h> 
main(int argc,int *argv[]) 
{ 
FILE *fp,*fp1,*fp2; 
if(argc==0) 
{ 
printf("No Input Files"); 
exit(0); 
} 
if(argc>1) 
{ 
fp=fopen(argv[1],"r"); 
fp2=fopen(argv[2],"r"); 
fp1=fopen(argv[3],"a"); 
char a,b,c; 
a=fgetc(fp); 
while(a!=EOF) 
{ 
putc(a,fp1); 
a=fgetc(fp); 
} 
b=fgetc(fp2); 
while(b!=EOF) 
{ 
putc(b,fp1); 
b=fgetc(fp2); 
} 
fclose(fp1); 
fp1=fopen(argv[3],"r"); 
c=fgetc(fp1); 
while(c!=EOF) 
{ 
putchar(c); 
c=fgetc(fp1);
} 
fclose(fp); 
fclose(fp1); 
fclose(fp2); 
} 
}








#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
main() 
{ 
FILE *fp; 
int a,i,n; 
char d,b[50],c[50]; 
while(1) 
{ 
printf("\nENTER THE COMMAND\n1.read\n2.write\n3.append\n4.exit"); 
scanf("%d",&a); 
switch(a) 
{ 
case 1: 
fp=fopen("ex.c","r"); 
d=fgetc(fp); 
while(d!=EOF) 
{ 
putchar(d); 
d=fgetc(fp); 
} 
fclose(fp); 
break; 
case 2: 
fp=fopen("ex.c","w"); 
printf("ENTER THE WORD TO BE WRITTEN"); 
scanf(" %s",b); 
n=strlen(b); 
for(i=0;i<n;i++) 
putc(b[i],fp); 
fclose(fp); 
break; 
case 3: 
fp=fopen("ex.c","a");
printf("ENTER THE WORD TO BE appended"); 
scanf(" %s",c); 
n=strlen(c); 
for(i=0;i<n;i++) 
putc(c[i],fp); 
fclose(fp); 
break; 
case 4:exit(1); 
} 
} 
}











#include<stdio.h> 
main() 
{ 
FILE *fp; 
char a[100],b; 
int n,i=0,j; 
fp=fopen("exe.c","r+"); 
fseek(fp,20,SEEK_SET); 
while(a[i]!=EOF) 
{ 
a[i]=fgetc(fp); 
i=i+1; 
} 
for(j=0;j<i;j++) 
{ 
printf("%c",a[j]); 
} 
}


#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
FILE *fp1,*fp2,*fp;
int i,s,st;
char c;
if(argc==0)
{
printf("\nNot possible to compute");
exit(0);
}
if(argc>1)
{
printf("\nEnter the start character number");
scanf("%d",&s);
printf("\nEnter the stop character number");
scanf("%d",&st);
fp1=fopen(argv[1],"a");
fp2=fopen(argv[2],"r");
fseek(fp2,s,SEEK_SET);
c=fgetc(fp2);
while(st-s>0)
{
fputc(c,fp1);
c=fgetc(fp2);
s++;
}
fclose(fp1);
}
fp=fopen(argv[1],"r");
c=fgetc(fp);
while(c!=EOF)
{
putchar(c);
c=fgetc(fp);
}
fclose(fp);
fclose(fp2);
}
