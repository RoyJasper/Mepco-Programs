#include<iostream>
#include<string>
using namespace std;
class book
{
public:
int isbn;
string title;
string author;
friend ostream& operator<<(ostream&,book&);
friend istream& operator>>(istream&,book&);
};
ostream& operator<<(ostream& tout,book& b)
{
tout<<"\nThe ISBN is"<<b.isbn;
tout<<"\nThe Title is"<<b.title;
tout<<"\nThe Author is"<<b.author;
return tout;
}
istream& operator>>(istream& tin,book& b)
{
cout<<"\nEnter the ISBN";
tin>>b.isbn;
cout<<"\nEnter the author";
tin>>b.author;
cout<<"\nEnter the title";
tin>>b.title;
return tin;
}
int main()
{
book b;
cin>>b;
cout<<"\nThe Book Details are";
cout<<b;
}

