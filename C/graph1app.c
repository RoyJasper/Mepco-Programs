#include"graph1head.h"
main()
{
graph g;
table t;
int s,n;
printf("ENTER THE NO OF VERTEX");
scanf("%d",&n);
g=ginit(n);
readgraph(g);
printf("ENTER THE SOURCE VERTEX");
scanf("%d",&s);
t=tinit(s,g);
dijkstra(g,t);
display(t,n);
}

