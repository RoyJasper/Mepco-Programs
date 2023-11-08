#include<string>
#include<iostream>
using namespace std;
class employe
{
 int no;
 string name;
 public:
  employe(int tno=0,string tname=0)
   {
    name=tname;
    no=tno;
   }
  void print()
   {
    cout<<"\n Employee no is "<<no;
    cout<<"\n Name is "<<name;
   }
};
template <>
{
 class queue<employe
}
