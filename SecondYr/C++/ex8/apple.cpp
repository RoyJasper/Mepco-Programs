#include<iostream>
#include<string>
using namespace std;
class str
{
 string name;
 public:
  str()
  {
   name="";
  }
  str(string l)
  {
   name=l;
  }
  bool operator==(str name2)
  {
   if(name==name2.name)
    return true;
   else
    return false;
  }
  bool operator<(str n)
  {
   if(n<n.name)
    return true;
   else
    return false;
  }
};
int main() 
{
 cout<<"suma";
 string s1,s2;
 s1="siva";
 s2="siva";
 str s;
 str my(s1);
 str you(s2);
 if(my==you)
  cout<<"same";
 else 
  cout<<"not same";
 if(my<you)
  cout<<"small";
 else
  cout<<"large";
 return 0;
}
  
