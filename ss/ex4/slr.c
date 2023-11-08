 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkterminal(char );
main()
{
char pf;
int pd,pp,dd;
int a,top,r,nt[100],end,b,f,ips,m,j,k,i,ip,ss,is,st,c,check;
char t[100],y[100],equ[100][100],stack[100],input[100],table[100][100][100];
printf("enter the no of states\n");
scanf("%d",&c);
printf("enter the no of actions and goto\n");
scanf("%d",&r);
printf("\n enter the choise \n  1: default   ");//n2: new values\n\n ");
scanf("%d",&f);
if(f==1)
{
strcpy(t,"+*()i$etf");
strcpy(equ[1],"ee+t");
strcpy(equ[2],"et");
strcpy(equ[3],"tt*f");
strcpy(equ[4],"tf");
strcpy(equ[5],"f(e)");
strcpy(equ[6],"fi");
strcpy(table[0][2],"s4");
strcpy(table[0][4],"s5");
strcpy(table[0][6],"1");
strcpy(table[0][7],"2");
strcpy(table[0][8],"3");
strcpy(table[1][0],"s6");
strcpy(table[1][5],"accept");
strcpy(table[2][0],"r2");
strcpy(table[2][1],"s7");
strcpy(table[2][3],"r2");
strcpy(table[2][5],"r2");
strcpy(table[3][0],"r4");
strcpy(table[3][1],"r4");
strcpy(table[3][3],"r4");
strcpy(table[3][5],"r4");
strcpy(table[4][2],"s4");
strcpy(table[4][4],"s5");
strcpy(table[5][0],"r6");
strcpy(table[5][1],"r6");
strcpy(table[5][3],"r6");
strcpy(table[5][5],"r6");
strcpy(table[6][2],"s4");
strcpy(table[6][4],"s5");
strcpy(table[6][7],"9");
strcpy(table[6][8],"3");
strcpy(table[7][2],"s4");
strcpy(table[7][4],"s5");
strcpy(table[7][8],"10");
strcpy(table[8][0],"s6");
strcpy(table[8][3],"s11");
strcpy(table[9][0],"r1");
strcpy(table[9][1],"s7");
strcpy(table[9][3],"r1");
strcpy(table[9][5],"r1");
strcpy(table[10][0],"r3");
strcpy(table[10][1],"r3");
strcpy(table[10][3],"r3");
strcpy(table[10][5],"r3");
strcpy(table[11][0],"r5");
strcpy(table[11][1],"r5");
strcpy(table[11][3],"r5");
strcpy(table[11][5],"r5");
strcpy(input,"i*i+i$");
strcpy(stack,"$0");
}
else
{
printf("enter the terminals\n");
scanf("%s",t);
printf("enter the non terminals\n");
scanf("%s",nt);
printf("enter the table values\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("i=%d j==%d  \n",i,j);
scanf("%s",table[i][j]);
}
}
 printf("enter the input");
scanf("%s",input);
 printf("enter the stack");
scanf("%s",stack);
}
int checkterminal(char x)
{
int i;
for(i=0;i<c;i++)
{
if(t[i]==x)
return i;
}
}

is=strlen(input);
ss=strlen(stack);
top=ss-1;
end=0;
void display()
{

printf("    ");
   for(i=0;i<=top;i++)
        printf("%c",stack[i]);
    printf("\t\t");
    for(i=end;i<=is;i++)
        printf("%c",input[i]);
}
printf("\n\n\n*****************************************************************************\n  STACK                  INPUT           ACTION TAKEN       GOTO FUNCTION\n****************************************************************************\n\n");
printf("    %s                  %s",stack,input);
int flag=1;
i=2;
while(flag==1)
{
    pp=(int)stack[top];
    pp=pp-48;
    pf=input[end];
    pd=checkterminal(pf);
    strcpy(y,table[pp][pd]);
    printf("     [%d,%c]=%s",pp,pf,y);
    if(strcmp(y,"accept")==0)
     {
     flag=0;
      exit(0);
     }
        if(y[0]=='s')
        {
            printf("\n");
           top++;
           stack[top]=input[end];
            top++;
          stack[top]=y[1];
            end++;
          display();

        }
    else
      {

        int g,p,e;
        char z,x[100];
        e=(int)y[1];
        e=e-48;
        z= equ[e][0];
        strcpy(x,equ[e]);
        g=strlen(x);
        g=g-1;
        g=g*2;
        top=top-g;
        p=(int)stack[top];
        p=p-48;
        strcpy(y,table[p][checkterminal(z)]);
        printf("           [%c,%c]=%s\n",stack[top],z,y);
        int w=strlen(y);
         top++;
        stack[top]=z;
        top++;
        if(w==2)
        {
            char hh=y[1]+10;
            stack[top]=hh;
        }
        else
        {
           stack[top]=y[0];
        }


        display();
        }
}
printf("\n*************************************************************\n");
}
