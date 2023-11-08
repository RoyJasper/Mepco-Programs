#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
    struct table
{
char loc[10];
char label[10];
char mnemonic[10];
char operand[10];
char code[10];
};
main()
{
    int i,j,k;
     FILE *fp,*fp2;
     struct table t;
     char a[20],b[20],*c,*d,e[100],f[100];
    fp4=fopen("table2.bin","ab+");
    while (fread(&t,sizeof(struct table),1,fp))
   {


   }
}
