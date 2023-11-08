#include"head1.h"
main()
{
  char ch;
  char sgname[10],syname[20];
  unsigned len,add;
  Oneline t;
  node n;
  int n1=intermediateFileGenerator();
//printf("from main()\n");
  //printf("opcode(assume) %X\n",searchOPTAB("ASSUME"));
  printf("INTERMEDIATE FILE IS CREATED\n");
  FILE *fp=fopen("output.bin","rb");
  FILE *np=fopen("hashTable.txt","r");
  fread(&t,sizeof(Oneline),1,fp);
  while(!feof(fp))
  {
    printf("%X\t%s\t%s\t%s\t%s\n",t.lc,t.label,t.opcode,t.operand1,t.operand2);
    fread(&t,sizeof(Oneline),1,fp);
  }
  fscanf(np,"%s\t%s\t%c\t%u\t%X\n",syname,sgname,&ch,&len,&add);
  //printf("AAAA\n");
  printf("SYMBOL TABLE\n");
  printf("************\n");
  printf("SymbolName\tSegmentName\tSegmentType\tLength\tAddress\n");
  while(!feof(np))
  {
    printf("%s\t\t%s\t\t%c\t\t%d\t%X\n",syname,sgname,ch,len,add);
    //fread(&n,sizeof(node),1,np);
    fscanf(np,"%s\t%s\t%c\t%u\t%X\n",syname,sgname,&ch,&len,&add);
  }
  printf("%s\t\t%s\t\t%c\t\t%d\t%X\n",syname,sgname,ch,len,add);
  //display(&hp);
  fcloseall();
  //printf("%X\t%s\t%s\t%s\t%s\n",t.lc,t.label,t.opcode,t.operand1,t.operand2);
}
