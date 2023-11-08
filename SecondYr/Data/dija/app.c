//#include"dijkimp.c"
main()
{
  int n,s;
  printf("Enter no of vertex");
  scanf("%d",&n);
  Graph g=gInit(n);
  readGraph(g);
  printf("Enter Source Vertex");
  scanf("%d",&s);
  Table t=tInit(n,s);
  dijkstra(g,t);
  display(t,n);
}

