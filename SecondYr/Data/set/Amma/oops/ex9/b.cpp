#include<iostream>
#include<string>
using namespace std;
class student
{
 public:
 int r;
 string name;
 string dept;
 int mark[6];
 int total;
 void getdetails()
 {
  cout<<"\nenter name:\t";
  cin>>name;
  cout<<"enter department:\t";
  cin>>dept;
  cout<<"enter rollno:\t";
  cin>>r;
  cout<<"enter marks\n";
  for(int i=0;i<3;i++)
  {
   cout<<"enter "<<i+1<<" mark\t";
   cin>>mark[i];
   }
  }
 void calculate()
 {
  total=0;
  for(int i=0;i<3;i++)
  {
   total=total+mark[i];
   }
  }
 void printdetails()
 {
  cout<<"\nname:\t"<<name;
  cout<<"\nrollno:\t"<<r;
  cout<<"\ndepart:\t"<<dept;
  cout<<"\nmarks\n";
  for(int i=0;i<3;i++)
  {
   cout<<"\nmark "<<i+1<<" "<<mark[i];
   }
  cout<<"\ntotal:\t"<<total;

  }
 };
template <typename type>
void bubblesort(type s[],int k,int n)
{
 type c;
 int up,low,mid;
 for(int i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
   if(&s[i]>&s[j])
   {
    c=s[i];
    s[i]=s[j];
    s[j]=c;
    }
   }
  }
low=0;
up=n-1;
while(low<=up)
{
 mid=(low+up)/2;
 if(s[mid].r==k)
 {
  cout<<"\nsearch found at"<<mid+1;
  exit(0);
  }
 else
  if(k<s[mid].r)
  low=mid-1;
  else
  low=mid+1;
  }
  cout<<"\nnot found\n";
 }
 main()
{
 student s[10];
 int n,k,u;
 cout<<"enter no of students\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  s[i].getdetails();
  s[i].calculate();
  s[i].printdetails();
  }
  cout<<"\nenter rollno to search \n";
  cin>>k;
  for(int j=0;j<n;j++)
  { s[j].r==k;
  break;}
  bubblesort <student> (s, k, n);
 }

