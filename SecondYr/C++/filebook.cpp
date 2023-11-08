#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class book
{
  public:
     string name,aut;
     int isbn;
  public:
    book(string tname=" ",int tisbn=0,string taut=" ")
      {
       aut=taut;
       name=tname;
       isbn=tisbn;
      }
void print()
{
 cout<<"\n Book author is "<<aut;
 cout<<"\n Book name is "<<name;
 cout<<"\n Book isbn is "<<isbn<<"\n";
// cout<<"\n Book author is "<<aut<<"\n";
}
};
int main()
{
 int is,j,n,i;
 string nam,bk;
 book b[10],d,e,f[10];
 fstream file("roy.dat",ios::in|ios::out|ios::binary|ios::trunc);
 cout<<"\nEnter no of books ";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cout<<"\n Enter "<<i+1<<" book information \n";
  cout<<"\n Enter the book name  ";
  cin>>bk;
  cout<<"\n Enter the isbn no  ";
  cin>>is;
  cout<<"\n Enter the author name  ";
  cin>>nam;
  b[i]=book(bk,is,nam);
 // file.seekp(i*sizeof(book),ios::beg);
  file.write((char*) &b[i],sizeof(book));
 }
// file.seekg(0,sizeof(book));
 for(i=0;i<n;i++)
 {
  file.seekg(i*sizeof(book),ios::beg);
  file.read((char*) &d,sizeof(book));
  for(j=i+1;j<n;j++)
   {	
     file.seekg(j*sizeof(book),ios::beg);
     file.read((char*) &e,sizeof(book));
     if(d.aut>e.aut)
      {
        file.seekg(i*sizeof(book),ios::beg);
        file.write((char*) &e,sizeof(book));
        file.seekg(j*sizeof(book),ios::beg);
        file.write((char*) &d,sizeof(book));
      }
    if(d.aut==e.aut)
    {
     if(d.isbn>e.isbn)
      {
        file.seekg(i*sizeof(book),ios::beg);
        file.write((char*) &e,sizeof(book));
        file.seekg(j*sizeof(book),ios::beg);
        file.write((char*) &d,sizeof(book));
      }
    }
  } 
 }
cout<<"\n Sorted order of books are \n";
 for(i=0;i<n;i++)
 {
    cout<<"\n "<<i+1<<" Book is\n ";
    file.seekg(i*sizeof(book),ios::beg);
    file.read((char*) &f[i],sizeof(book));
    f[i].print();
 }
return 0;
}

