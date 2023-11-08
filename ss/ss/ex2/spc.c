#include<stdio.h>
int main(int argc, char *argv[])
{
 int ch2,i;
 char ch1,ch;
 FILE *fp;
 int s=0,n=0,c=0;
 char sp[100],cha[100];
 int nos[100];
 fp=fopen("program.c","r");
  while((ch=fgetc(fp))!=EOF)
  {
    ch=(int)ch;
   if(((ch>=33)&&(ch<=47))||((ch>=91)&&(ch<=96))||((ch>=123)&&(ch<=126))||((ch>=58)&&(ch<=64)))
    {
     //printf("\n Special char\n ");
    // printf(" %c \t",ch );
    ch1=(char)ch;
    sp[s]=ch1;
    s++;
   //ch=fgetc(fp);
    }
   else if(((ch>=65)&&(ch<=90))||((ch>=97)&&(ch<=122)))
        {
    // printf("\n char\n ");
    // printf(" %c \t",ch );
   ch1=(int)ch;
   cha[c]=ch1;
   c++;
   //ch=fgetc(fp);

    }
    //else
     // ch=fgetc(fp);

  ch=fgetc(fp);

  }
  fclose(fp);
  printf("\n Special \n");
  for(i=0;i<=s;i++)
  {
   printf("%c  ",sp[i]); 
  }
  printf("\n");
  printf("\n Identifers \n");
  for(i=0;i<=c;i++)
  {
   printf("%c  ",cha[i]);
  }
  printf("\n");







}

