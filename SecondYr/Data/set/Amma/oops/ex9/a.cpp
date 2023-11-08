#include<iostream>
#include<string>
using namespace std;
class employee
{
 public:
 int eid;
 string name;
 string dept;
 float bp,da,hra,ded;
 float sal;
 void getdetails()
 {
  cout<<"\nenter name:  ";
  cin>>name;
  cout<<"enter depart:  ";
  cin>>dept;
  cout<<"enter employee id:  ";
  cin>>eid;
  cout<<"enter basic pay:  ";
  cin>>bp;
  }
 void calculate()
 {
  da=bp*0.7;
  hra=bp*0.5;
  ded=bp*0.02;
  sal=(bp+da+hra-ded);
  }
 void printdetails()
 {
  
  cout<<"\nname  :  "<<name;
  cout<<"\nemp id: "<<eid;
  cout<<"\ndepart:  "<<dept;
  cout<<"\nsalary:  "<<sal;
  
  }
 };
template <typename type>
void search(type e[],int k,int n,string ename,string edept)
{
 type c;
 int j;
 for(int i=0;i<n;i++)
 {
  if((e[i].eid==k)||(e[i].name==ename)||(e[i].dept==edept))
  {
  cout<<"\nsearch found at"<<i+1;
  }
  else j++;
  if(j==n)
  cout<<"not found\n";
   }
  }
 main()
{
 employee e[10];
 static int n,u,a;
 cout<<"enter no of employees\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cout<<"enter "<<i+1<<" details\n";
  e[i].getdetails();
  e[i].calculate();
  }
  do
  {
  int k;
  string ename,edept;
  cout<<"\nenter choice to search\n1.employee id\n2.name\n3.dept\n4.display\n5.exit\n";
  cin>>a;
  switch(a)
  {
  case 1:
  cout<<"\nenter employee id no to search\n";
  cin>>k;
  search <employee> (e, k, n, "", "");
  break;
  case 2:
  cout<<"\nenter name to search\n";
  cin>>ename;
  search <employee> (e, 555, n, ename, "");
  break;
  case 3:
  cout<<"\nenter department to search\n";
  cin>>edept;
  search <employee> (e, 555, n, "", edept);
  break;
  case 4:
  for(int i=0;i<n;i++)
  {
  cout<<i+1<<" employee details";
  e[i].printdetails();
   }
  break;
  case 5:
  exit(0);
    }
   }
   while(1);
 }
