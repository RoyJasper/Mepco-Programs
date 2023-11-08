#include<stdio.h>
#include<string.h>
int main()
{
 char key[10][10]={"printf","int","char","main","float","if","else","scanf","include"};
 char fil[10],tes[10][10],ch,sp[50],d[10],keyf[10][10],ident[20];
 FILE *fp;
 int chk,iden=0,cou=0,ch1,s=0,k=0,stc=0,c=0,kw=0,i;
// printf("\n  Enter file name ");
// scanf("%s",fil);
 fp=fopen("program.c","r");
 ch=fgetc(fp);
 while(ch!=EOF)
 {
  ch1=(int)ch;
  if(((ch>=33)&&(ch<=47))||((ch>=91)&&(ch<=96))||((ch>=123)&&(ch<=126))||((ch>=58)&&(ch<=64)))
  {
   ch=(char)ch1;
   sp[s]=ch;
   s++;
  }
  else
  {
   if((ch1>=97)&&(ch1<=122))
   {
    d[k]=ch1;
    k++;
    ch1=fgetc(fp);
    ch=(int)ch1;
    while(!(((ch>32)&&(ch<57))||((ch>91)&&(ch<96))||((ch>123)&&(ch<126))))
    {
     d[k]=ch;
     k++;
     stc++;
    }
    memcpy(tes[c],d,stc);
    tes[c][stc]='\0';
    c++;
    for(i=0;i<10;i++)
    {
     if(strcmp(tes[c],key[i])==0)
     {
      strcpy(keyf[cou],key[i]);
      chk=1;
      kw++;
     }
    }
    if(chk!=1)
    {
     strcpy(ident[iden],tes[c]);
     iden++;
    }
   }
  }
 ch=fgetc(fp);
 }
 printf("\n Identifers \n");
 for(i=0;i<iden;i++)
 {
  printf(" %c ",ident[i]);
 }
 printf("\n Keywords \n");
 for(i=0;i<kw;i++)
 {
  printf(" %s ",keyf[i]);
 }
 printf("\n Special Char \n");
 for(i=0;i<s;i++)
 {
  printf(" %c ",sp[i]);
 }
 fclose(fp);
 return 0;
}
