#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
struct node
{
    int adj;
    int cost;
    struct node * next;
};
typedef struct node * List;
struct graphentry
{
    int vert;
    List *array;
};
typedef struct graphentry *Graph;
struct tableentry
{
    int known;
    int dist;
    int path;
};
typedef struct tableentry * Table;
Graph gInit(int n);
Table tInit(int n,int s);
void readGraph(Graph g);
int findMinVertex(Table t,int n);
void dijkstra(Graph g,Table t);




Graph gInit(int n)
{
    int i;
    Graph g=(Graph)malloc(sizeof(struct graphentry));
    g->vert=n;
    g->array=(List *)malloc(sizeof(List)*(n+1));
    for(i=0; i<n+1; i++)
    {
        g->array[i]=(List)malloc(sizeof(struct node));
        g->array[i]->next=NULL;
    }
    return g;
}
void readGraph(Graph g)
{
    List t,temp;
    int a,c,i,ch;
    for(i=1; i<=g->vert; i++)
    {
        printf("\n Enter Data about vertex no %d  \n",i);
        do
        {
            printf(" Enter 1 to add ",i);
            scanf("%d",&ch);
            if(ch==1)
            {
                printf("Enter adjacent vertex and its cost: ");
                scanf("%d%d",&a,&c);
                t=g->array[i];
                temp=(List)malloc(sizeof(struct node));
                temp->adj=a;
                temp->cost=c;
                temp->next=t->next;
                t->next=temp;
            }
        }
        while(ch==1);
    }
}
Table tInit(int n,int s)
{
    int i;
    Table t;
    t=(Table)malloc(sizeof(struct tableentry)*(n+1));
    for(i=1; i<=n; i++)
    {
        t[i].known=0;
        t[i].dist=9999;
        t[i].path=0;
    }
    t[s].dist=0;
    return t;
}
int findMinVertex(Table t,int n)
{
    int minv=0;
    int min=9999;
    int i;
    for(i=1; i<=n; i++)
    {
        if(t[i].known==0)
        {
            if(min>t[i].dist)
            {
                min=t[i].dist;
                minv=i;
            }
        }
    }
    return minv;
}
void dijkstra(Graph g,Table t)
{
    int v,w,i;
    for(i=1; i<=g->vert; i++)
    {
        v=findMinVertex(t,g->vert);
        if(v<1)
            break;
        t[v].known=1;
        List temp=g->array[v]->next;
        while(temp!=NULL)
        {
            w=temp->adj;
            if(t[w].known==0)
            {
                if(t[v].dist+temp->cost<t[w].dist)
                {
                    t[w].dist=t[v].dist+temp->cost;
                    t[w].path=v;
                }
            }

            temp=temp->next;
        }
        //display(t,n);
    }
}
void display(Table t,int n)
{
    int i;
    printf("\nvertex\tKnown\tDist\tPath\n");
    //printf("\nvertex\tKnown\tDist\tPath\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t%d\t%d\t%d\n",i,t[i].known,t[i].dist,t[i].path);
        // printf("%d\t%d\t%d\t%d\n",i,t[i].known,t[i].dist,t[i].path);
    }
}


main()
{
    int n,s,i,soc;
    int k[20],d[20],p[20];
    struct sockaddr_in serv, cli;
    struct sockaddr_storage store;
    socklen_t len, clen;

    soc = socket(PF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(soc, (struct sockaddr *) &serv, sizeof(serv));

    len = sizeof store;

    printf("Enter no of vertex");
    scanf("%d",&n);
    Graph g=gInit(n);
    readGraph(g);
    recvfrom(soc,s,100,0,(struct sockaddr *)&store, &len);
    Table t=tInit(n,s);
    dijkstra(g,t);
    for(i=1;i<=n;i++)
    {
        k[i]=t[i].known;
        d[i]=t[i].dist;
        p[i]=t[i].path;
    }
    sendto(soc,k,100,0,(struct sockaddr *)&serv,len);
    sendto(soc,d,100,0,(struct sockaddr *)&serv,len);
    sendto(soc,p,100,0,(struct sockaddr *)&serv,len);

}
