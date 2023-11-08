#include"graph2head.h"
main()
{
graph g;
table t;
set v;
int s,n;
printf("ENTER THE NO OF VERTEX");
scanf("%d",&n);
g=ginit(n);
g=readgraph(g);
t=tinit(s,g);
t=insert(t,g);
t=sort(t);
display(t,n);
v=makeset(n,v);
v=unionarbi(t,v);
display1(v);
}

