  #include<iostream>
  #include<string>
  #include<exception>
  using namespace std;
  class stack
  {
  public:
  int top;
  int sarr[10];
  public:
  stack()
  {
  top=0;
  }
  int set()
  {
  cout<<"\nOverflow... \n";
  exit(0);
  }
  int set1()
  {
  cout<<"\nUnderflow....\n";
  exit(0);
  }
  };
  int  main()
  {
  int x,f,n;
  int data;
  stack s;
  
cout<<"\n Enter no of elements .. ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
  cout<<"\n"<<"\n Enter elements .. ";
  cin>>data;
  if(s.top==5)
  throw (s.set());
  else
  {
  s.sarr[s.top]=data;
  cout<<"\nPushed Element is ..  "<<s.sarr[s.top];
  s.top++;
  }}
  cout<<"\n"<<" Enter no of elements to be poped ..  ";
  cin>>n;
  for(int j=0;j<n;j++)
  {
  if(s.top==0)
  throw (s.set1());
  else
  {
  s.top--;
  cout<<"\nPoped element is ... "<<s.sarr[s.top];
  }
  }
  }

