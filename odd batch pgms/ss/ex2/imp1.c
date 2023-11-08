#include"head1.h"
int byteseparate(char *operand)
{
  int i,j=0,count=0;
  if(operand[0]=='C')
  {
    i=2;
    while(operand[i]!='\0'&&operand[i]!='\'')
    {
     j++;
     i++;
    }
    count=j;
    return count;
  }
  else
    return -1;
}
struct Oneline separateTokens(char *line)
{
  int i=0,k=0;
  struct Oneline a;
  strcpy(a.label," ");
  strcpy(a.opcode," ");
  strcpy(a.operand1," ");
  strcpy(a.operand2," ");
  if(isalpha(line[i]))
  {
    while(line[i] != ' ')
    {
      a.label[k] = line[i];
      k++;
      i++;
    }
    a.label[k] = '\0';
    k=-1;
  }
  else
  {
    while(line[i] == ' ')
      i++;
  }
  if(k == -1)
  {
    while(line[i] == ' ')
      i++;
    k=0;
  }
  while((line[i] != ' ')&&(line[i] != '\0'))
  {
    a.opcode[k] = line[i];
    k++;
    i++;
  }
  a.opcode[k] = '\0';
  k=0;
  while(line[i] == ' ')
    i++;
  while((line[i] != '\0')&&(line[i] != ',')&&(line[i] != ' '))
  {
    a.operand1[k] = line[i];
    k++;
    i++;
  }
  a.operand1[k] = '\0';
  k=0;
  if(line[i] == ',')
  {
    i++;
    while(line[i] == ' ')
      i++;
    while((line[i] != '\0')&&(line[i] != ' '))
    {
      a.operand2[k] = line[i];
      k++;
      i++;
    }
    a.operand2[k] = '\0';
  }
  return a;
}
int intermediateFileGenerator()
{
  int instLen=0;
  FILE *ip,*op,*table;
  char line[100],ch;
  int n;
  ip = fopen("input.txt","r");
  op = fopen("output.bin","wb");
  table = fopen("hashTable.txt","w");
  if((ip == NULL)||(op == NULL)||(table == NULL))
    return 0;
  int lc=0;
  hptr hp=createSymboltbl();
  char segName[20],label[20];
  int oper;
  strcpy(segName," ");
  fscanf(ip,"%[^\n]%c",line,&ch);
  n = strlen(line);
  line[n] = '\0';
  struct Oneline a = separateTokens(line);
  //printf("AAAA\n");
  if(strcmp(a.opcode,"ORG"))
  {
    n = strlen(a.operand1);
    if(a.operand1[n-1] == 'H')
    {
      a.operand1[n-1] = '\0';
      sscanf(a.operand1,"%XH",&oper);
    }
    else
      sscanf(a.operand1,"%d",&oper);
    lc = oper;
    a.lc=lc;
    write(a,op);
    fscanf(ip,"%[^\n]%c",line,&ch);
    n = strlen(line);
    line[n] = '\0';
    //write(a,op);
    a = separateTokens(line);
  }
  while(strcmp(a.opcode,"END") != 0)
  {
    int ans=searchOPTAB(a.opcode);
    int assume=0;
    if(strcmp(a.opcode,"ORG") == 0)
    {
      n = strlen(a.operand1);
      if(a.operand1[n-1] == 'H')
      {
        //a.operand1[n-1] = '\0';
        sscanf(a.operand1,"%XH",&oper);
      }
      else
        sscanf(a.operand1,"%d",&oper);
      lc = oper;
      a.lc=lc;
      write(a,op);
      fscanf(ip,"%[^\n]%c",line,&ch);
      n = strlen(line);
      line[n] = '\0';
      a = separateTokens(line);
      continue;
    }
    //int assume=0;
    else if(strcmp(a.opcode,"ASSUME") == 0 )//|| ans == -1)
    {
      //printf("%s\n",line);
      lc = oper;
      a.lc = lc;
      write(a,op);
      //lc = lc + instLen;
      fscanf(ip,"%[^\n]%c",line,&ch);
      n = strlen(line);
      line[n] = '\0';
      a = separateTokens(line);
      assume = -1;
      continue;
    }
    else if((strcmp(a.label," ") != 0)&&(strcmp(a.opcode,"SEGMENT") == 0))
    {
      strcpy(label,a.label);
      strcpy(segName,a.label);
      node *nd;
      nd=(node *)malloc(sizeof(node));
      strcpy(nd->symname,a.label);
      strcpy(nd->segname,a.label);
      nd->symtype='S';
      nd->length=0;
      nd->address=lc;
      insert(&hp,nd);
      //printf("AAAA\n");
    }
    else if((strcmp(a.label," ") != 0)&&(strcmp(a.opcode,"ENDS") == 0))
    {
      strcpy(label," ");
      strcpy(segName," ");
    }
    else //if(ans != -1)// && assume != -1)
    {
      assume =0;
      //printf("else if 3'\n");
      if(strcmp(segName," ") != 0)
      {
        node *nd;
        int cnt=0;
        if(strcmp(a.label," ")!=0)
        {
          cnt++;
          nd = search(a.label,segName,&hp);
        }
        if(nd != NULL && cnt == 1)
          printf("%s : Duplication not possible\n",line);
        else
        {
          //int instLen=0;
          if((strcmp(a.opcode,"DB") == 0)||(strcmp(a.opcode,"DW") == 0))
          {
            if(strcmp(a.opcode,"DB") == 0)
            {
              //int instLen=0;
              int inst=byteseparate(a.operand1);
              node *nd;
              nd=(node *)malloc(sizeof(node));
              strcpy(nd->symname,a.label);
              strcpy(nd->segname,segName);
              nd->symtype='B';
              nd->length=inst;
              nd->address=lc;
              //display(&hp);
              //printf("%s\t%s\t",nd->symname,nd->segname);
              //printf("%c\t%u\t%d\n",nd->symtype,nd->length,nd->address);
              insert(&hp,nd);
              //insert(a.label,segName,'B',1,lc,hp);
              //int inst=byteseparate(a.operand1);
              if(inst!=-1)
                instLen=inst;
              else
                instLen=1;
            }
            else if(strcmp(a.opcode,"DW") == 0)
            {
              node *nd;
              nd=(node*)malloc(sizeof(node));
              strcpy(nd->symname,a.label);
              strcpy(nd->segname,segName);
              nd->symtype='w';
              nd->length=2;
              nd->address=lc;
              insert(&hp,nd);
              //int instLen=0;
              //insert(a.label,segName,'W',2,lc,hp);
              instLen=2;
            }
          }
          else //if(ans != 0XFFFFFFFF)
          {
            //int instLen = 0;
            if(strcmp(a.label," ")!=0)
            {
              node *nd;
              nd=(node*)malloc(sizeof(node));
              strcpy(nd->symname,a.label);
              strcpy(nd->segname,segName);
              nd->symtype='N';
              nd->length=2;
              nd->address=lc;
              insert(&hp,nd);
              //insert(a.label,segName,'N',2,lc,hp);
            }
            int count=0;
            int reg1=isRegister(a.operand1);
            int reg2=isRegister(a.operand2);
             //nd1 = search(a.operand2,segName,&hp);
            node *nd1;
             //nd1 = search(a.operand2,segName,&hp);
            //nd = search(a.operand1,segName,&hp);
            nd = NULL;
            nd1 = NULL;
            if(isRegister(a.operand1) == -1)
            {
              //count++;
              nd = search(a.operand1,segName,&hp);
             // printf("\noperand1:%s\nnd   :\n\n",a.operand1); 
              instLen=4;
            }
            //node *nd1;
            if(strcmp(a.operand2," ")!=0 && isRegister(a.operand2) == -1)
            {
              //count++;
              nd1 = search(a.operand2,segName,&hp);
              //printf("\nOperand2:%s\nnd1   :\n\n",a.operand2);
              instLen=4;  
            }
            if(((nd != NULL)||(nd1 != NULL)))//&&(count == 2))
            {
//printf("instLen %d\n",instLen);
              instLen = 4;
              //printf("\n\nnd  and nd1 :\n\n"); 
            }
            //int reg1=isRegister(a.operand1);
            //int reg2=isRegister(a.operand2);
            else if(((reg1!=-1))&&((reg2!=-1)))
            {
//printf("instLen %d\n",instLen);
              instLen = 2;
              //printf("\n\nreg   :\n\n"); 
            }
            //lc = lc + instLen;
          }
          //lc=lc + instLen;
        }
        //lc=lc+instLen;
      }
       //else
         //`printf("%s : Definition outside segment\n",line);
    }
	//printf("opcode(assume) : %X\n",searchOPTAB(a.opcode));
    //printf("###########################\n");
    a.lc = lc;
    //printf("LC:%x\n",lc);
    write(a,op);
    if(strcmp(a.opcode,"ENDS")!=0)
      lc=lc + instLen;
    else
      lc=lc;
    //printf("%X\t%s\t%s\t%s\t%s\n",lc,a.label,a.opcode,a.operand1,a.operand2);
    fscanf(ip,"%[^\n]%c",line,&ch);
    n = strlen(line);
    line[n] = '\0';
    a = separateTokens(line);
  }
  if(strcmp(a.opcode,"END")==0)
  {
    a.lc=lc;
    //printf("\nLC:%x\n",lc);
    write(a,op);
  }
  writeSymTable(hp,table);
  fcloseall();
}
int writeSymTable(hptr hp,FILE *t)
{
  int ans = isEmpty(&hp);
  if(ans == 1)
    return -1;
  int i=0;
  node *nd;
  for(i=0;i<26;i++)
  {
    nd = hp->lists[i];
    while(nd != NULL)
    {
      //fwrite(nd,sizeof(node),1,t);
      //printf("%s\t%s\t",nd->symname,nd->segname);
      //printf("%c\t%u\t%X\n",nd->symtype,nd->length,nd->address);
      fprintf(t,"%s    %s    ",nd->symname,nd->segname);
      fprintf(t,"%c    %u    %X\n",nd->symtype,nd->length,nd->address);
      nd = nd->next;
    }
  }
  return 1;
}
void writeIntoFile(struct Oneline a,FILE *op)
{
  fwrite(&a,sizeof(Oneline),1,op);
}
void write(struct Oneline a,FILE *op)
{
  //if(strcmp(operand2," ")==0)
    fwrite(&a,sizeof(Oneline),1,op);
  //else
  //struct Oneline *k = &a;
    //fwrite(&a, sizeof(struct Oneline), 1, op);
}
int isRegister(char *reg)
{
  char *regi[16]= {"AL","CL","DL","BL","AH","CH","DH","BH","AX","CX","DX","BX","SP","BP","SI","DI"};
  int j,i=0;
  //for(j=0;j<=1;j++)
  //{
  while(i < 16)
  {
    if(strcmp(reg,regi[i]) == 0)
    {
      //printf("\n\n%s Register found\n\n",reg);
      //if(i >= 8)
        //return i-8;
      //else
        return i;
    }
    //printf("HAI\n\n");
    i++;
  }
  //}
  //printf("\n%s not found\n",reg);
  return -1;
}
/*int isRegister(char *reg)
{
  char *regi[16]= {"AL","CL","DL","BL","AH","CH","DH","BH","AX","CX","DX","BX","SP","BP","SI","DI"};
  int j,i=0;
  //for(j=0;j<=1;j++)
  //{
  while(i < 16)
  {
    if(strcmp(reg,regi[i]) == 0)
    {
      //printf("\n\n%s Register found\n\n",reg);
      if(i >= 8)
        return i-8;
      else
        return i;
    }
    //printf("HAI\n\n");
    i++;
  }
  //}
  //printf("\n%s not found\n",reg);
  return -1;
}*/
int searchOPTAB(char *opcode)
{
  //printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  //printf("Search optab\n");
  //printf("opcode = %s\n",opcode);
  FILE *op;
  op = fopen("optab.txt","r");
  if(op == NULL)
    return 0;
  char name[10],ch,dummy;
  int code = 0X0;
  while(!feof(op))
  {
    fscanf(op,"%s%c",name,&ch);
    //printf("name = %s",name);
    if(strcmp(opcode,name) == 0)
    {
      fscanf(op,"%X",&code);
      return code;
    }
    else
    {
      fscanf(op,"%c",&dummy);
      while(dummy != '\n')
        fscanf(op,"%c",&dummy);
    }
  }
  //printf("search complete elt not found\n");
  //printf("%X\n",code);
  //printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  return -1;
}
