#include<iostream>
#include<string>
using namespace std;
class book
{
 public:
     string name;
     int isbn;
void getdetails()
{
cout<<"enter the book name";
cin>>name;
cout<<"enter the isbn no";
cin>>isbn;
}
bool operator < (book e)
{
 if(isbn<e.isbn)
 return true;
 else
 return false;
}
bool operator == (book e)
{
 if(isbn==e.isbn)
  return true;
 else
    return false;
}
};
template<typename type>
void bubble(type b[],int n)
{
 book t;
 int i,j;
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
   {
       if(b[i]<b[j])
       {
        t=b[i];
        b[i]=b[j];
        b[j]=t;
       }
    }
 }
 for(i=0;i<n;i++)
 {
 cout<<b[i].name;
 cout<<b[i].isbn<<"\n";
 }
}
template<typename type>
void  searched(type b[],int n,type a)
 {
 int mid,low=0,up=n-1;
 while(up>=low)
 {
  mid=low+up/2;
  if((b[mid].name==a.name)&&(b[mid].isbn==a.isbn))
  {cout<<"The search book is present";
  break;
  }
  else if((b[mid].name<a.name)&&(b[mid].isbn<a.isbn))
  low=mid+1;
  else
  up=mid-1;
 }
  if(low>up)
    cout<<"not present";
}
 int main()
 {
  int n,i;
  book b[20],a;
  cout<<"enter the no of elements";
  cin>>n;
  for(i=0;i<n;i++)
  b[i].getdetails();
  bubble<book>(b,n);
  cout<<"enter the search details\n";
  a.getdetails();

  searched<book>(b,n,a);
}
