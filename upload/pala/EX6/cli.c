#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct mymsgbuf
{
    long mtype;
    char mtext[25];
};
FILE *fp;
int main()
{
    struct mymsgbuf buf;
    int msgid;
    int i=0,s;
    int count=0,frmsz;
    int a[100];
    char d;
    if((msgid=msgget(89,IPC_CREAT|0666))==-1)
    {
        printf("\n ERROR IN MSGGET");
        exit(0);
    }
    printf("\n Enter the frame size:");
    scanf("%d",&frmsz);
    printf("_______");
    if((fp=fopen("check","r"))==NULL)
        printf("\n FILE NOT OPENED");
    else
        printf("\n FILE OPENED");
    while(!feof(fp))
    {
        d=getc(fp);
        a[i]=d;
        i++;
    }
    s=i;
    for(i=0; i<frmsz; i++) //print from the check file
        printf("\t %c",a[i]);
    for(i=0; i<frmsz; i++)
    {
        if((msgrcv(msgid,&buf,sizeof(buf),0,1))==-1)
        {
            printf("\n ERROR IN MSGRCV");
            exit(0);
        }
        printf("\n RECEIVED FRAMES ARE:%c",buf.mtext[i]);
    }
    for(i=0; i<frmsz; i++)
    {
        if(a[i]==buf.mtext[i])
            count++;
    }
    if(count==0)
    {
        printf("\n FRAMES WERE NOT RECEIVED IN CORRECT SEQ");
        exit(0);
    }
    if(count==frmsz)
    {
        printf("\n FRAMES WERE RECEIVED IN CORRECT SEQ");
    }
    else
    {
        printf("\n FRAMES WERE NOT RECEIVED IN CORRECT SEQ");
    }
}

