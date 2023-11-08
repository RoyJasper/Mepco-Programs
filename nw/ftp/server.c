#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int validornot(char[],char[]);
int main()
{
    int wsoc,port,soc,cou=0;
    char ch,str[20],u[20],p[20],fil[20];
    FILE *fp,*fpt;
    struct sockaddr_in saddr;
    struct sockaddr_storage serv;
    socklen_t alen;
    printf("\n Enter port : ");
    scanf("%d",&port);

    wsoc = socket(PF_INET, SOCK_STREAM, 0);


    saddr.sin_family = AF_INET;

    saddr.sin_port = htons(port);

    // saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(saddr.sin_zero, '\0', sizeof saddr.sin_zero);


    bind(wsoc, (struct sockaddr *) &saddr, sizeof(saddr));


    if(listen(wsoc,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");


    alen = sizeof serv;
    soc = accept(wsoc, (struct sockaddr *) &serv, &alen);

//loop:
    recv(soc,u,100,0);
    recv(soc,p,100,0);
    recv(soc,fil,100,0);
    printf(" %s %s %s ",u,p,fil);
    char x;
    if(validornot(u,p)==0)
    {
        fp=fopen(fil,"w");
        if(!fp)
        printf("FILE FAIl");
        x=fgetc(fp);
        while(x!=EOF)
        {
           // if(x==' ')
            {
                //fseek(fp,-1,SEEK_CUR);
              //  fprintf(fp,",");
            }
            printf(" %c",x);
            x=fgetc(fp);
        }
        printf("<<<\n in f loop\n\n\n");
    }
    if(validornot(u,p)==1)
    {
        cou++;
        if(cou==3)
        {
            send(soc,"Retry",100,0);
           // goto loop;
        }
        else
            send(soc,"Failure",100,0);
    }

}
int validornot(char u[20], char p[10])
{
    FILE *fp;
    char tp[10],tu[10];
    fp=fopen("undpass.txt","r+");
    fscanf(fp,"%s",tu);
    fscanf(fp,"%s",tp);
    printf(" in file : %s %s ",tu,tp);
    if((strcmp(tu,u)==0)&&(strcmp(tp,p)==0))
    {
        return 0;
    }
    else
        return 1;
}
