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
    int si,ei,sz;
    int msgid;
    int i=0,s;
    int a[100];
    char d;
    if((fp=fopen("send","r"))==NULL)
        printf("\n FILE NOT OPENED");
    else
        printf("\n FILE OPENED");
    printf("\n Enter starting and ending index of frame array:");
    scanf("%d%d",&si,&ei);
    sz=ei-si;
    if((msgid=msgget(89,IPC_CREAT|0666))==-1)
    {
        printf("\n ERROR IN MSGGET");
        exit(0);
    }
    while(!feof(fp))
    {
        d=getc(fp);
        a[i]=d;
        i++;
    } s
        =i;
    buf.mtype=1;
    for(i=si; i<=ei; i++)
    {
        buf.mtext[i]=a[i];
    }
    for(i=si; i<=ei; i++) //the frames to be sent
        printf("\t %c",buf.mtext[i]);
    for(i=0; i<=sz; i++)
    {
        if((msgsnd(msgid,&buf,sizeof(buf),0))==-1)
        {
            printf("\n ERROR IN MSGSND");
            exit(0);
        }
    }
    printf("\n FRAMES SENT");
    return 0;
}

