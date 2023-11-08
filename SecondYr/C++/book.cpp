#include<iostream>
#include<string>
using namespace std;
class book
{
private:
int no;
string aut;
string tit;
public:
void getdetails();
void printdetails();
friend void sort(book [],int);
};
void book::getdetails()
{
cout<<"\nEnter the no of that book";
cin>>no;
cout<<"\nEnter the author name";
cin>>aut;
cout<<"\nEnter the title of that book";
cin>>tit;
}
void book::printdetails()
{
cout<<no<<"\t";
cout<<aut<<"\t";
cout<<tit<<"\n";
}
void sort(book b[],int n)
{
book t;
int i,j;
book k;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(b[i].aut>b[j].aut)
{
t=b[i];
b[i]=b[j];
b[j]=t;
}
}
}
}
int main()
{
book a[50];
int n;
cout<<"\nEnter the no of the book";
cin>>n;
for(int i=0;i<n;i++)
{
a[i].getdetails();
}
sort(a,n);
cout<<"\nNo"<<"\t";
cout<<"AUTHOR"<<"\t";
cout<<"TITLE"<<"\n"<<"\n";
for(int i=0;i<n;i++)
{
a[i].printdetails();
}
}


