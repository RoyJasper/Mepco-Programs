#include<iostream>
#include<string>
using namespace std;
class integer
{
 int up,low,val;
 public:
   integer()
   {
    up=0;
    low=0;
    val=0;
   }
   integer(int x,int y,int val1)
   {
    up=x;
    low=y;
    val=val1;
   }
   void validate()
   {
    if((val>=low) && (val<=up))
     cout<<"value is between";
    else
     cout<<"value is not between";
   }
};
int main()
{
 int a,b,c;
 cout<<"enter limits";
 cin >>a>>b;
 cout<<"enter the value";
 cin>>c;
 integer b1(a,b,c);
 
 b1.validate();
}
