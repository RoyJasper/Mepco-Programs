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
  };
  int  main()
  {
  int x,f,n;
  int data;
  stack s;
 // cout<<"\t\t\tWELCOME TO STACK OPERATION\n";
  try
  {
  cout<<"\n Enter no of elements to be pushed ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
  cout<<"\n"<<"Enter elements ";
  cin>>data;
  if(s.top==5)
  throw 25;
  else
  {
  s.sarr[s.top]=data;
  cout<<"\n pushed element is  "<<s.sarr[s.top];
  s.top++;
  }}
  cout<<"\n"<<"Enter no of elements to be  poped  ";
  cin>>n;
  for(int j=0;j<n;j++)
  {
  if(s.top==0)
  throw 'a';
  else
  {
  s.top--; 
  cout<<"\npoped element is "<<s.sarr[s.top];
  }
  }}
  catch(int )
  {
  cout<<"\nOver flow ... \n";
  exit(0);
  }
  catch(char )
  {
  cout<<"\nUnderflow.....\n";
  exit(0);
  }
  return 0;
  }



