#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc , char *argv[])
{
 if(argc==2)
 {
 int cha=0,vov=0,lin=0,wor=0,fp;
 char ch;
 int d,a[2];
 int p=pipe(a);
 d=fork();
 if(d==-1)
  {
   printf("Fork error");
   return 0;
  }
 else if(d==0)
  {
   printf("\nIn child");
   fp=open(argv[1],O_RDONLY);
   if(fp==-1)
    {
     printf("\nFile open fail");
     return 0;
    }
   else
    {
     while(read(fp,&ch,1)>0)
     {
      if(ch==' ')
       wor++;
      else if(ch=='\n')
       lin++;
      else if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
       vov++;
      cha++;
     }
    }
   close(a[0]);
   write(a[1],&cha,sizeof(cha));
   write(a[1],&vov,sizeof(vov));
   write(a[1],&lin,sizeof(lin));
   write(a[1],&wor,sizeof(wor));
  }
 else if(d>0)
  {
   printf("\n In Parent");
   close(a[1]);
   read(a[0],&cha,sizeof(cha));
   read(a[0],&vov,sizeof(vov));
   read(a[0],&lin,sizeof(lin));
   read(a[0],&wor,sizeof(wor));
   printf("\n No of character are %d ",cha);
   printf("\n No of wovels are %d ",vov);
   printf("\n No of lines are %d ",lin);
   printf("\n No of words are %d ",wor);
  }
  }
  else
   printf("\n Enter correct arguments");
 return 0;
}

