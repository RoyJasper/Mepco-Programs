#include<iostream>
#include<string>
using namespace std;
class cstring
{
string str;
public:
cstring(string x="")
{
str=x;
}
bool operator < (cstring a)
{
  if( str < a.str )
    return true;
  else
    return false;
}
bool operator == (cstring b)
{
  if(str < b.str)
    return true;
  else
    return false;
}
};
int main()
{
string a,b;
cout<<"\n enter your name    ";
cin>>a;
cout<<"\n enter my name       ";
cin>>b;
if(b<a)
cout<<"\n my name is lesser than your name  \n";
else
cout<<"\n my name is greater than your name  \n";
if(b=="siva")
cout<<"\n my name is correct\n";
else
cout<<"\n  my name is incorrect\n";
if(b==a)
cout<<"\n my name is equal to your name \n";
else
cout<<"\n my name is not equal to your name\n";
}
