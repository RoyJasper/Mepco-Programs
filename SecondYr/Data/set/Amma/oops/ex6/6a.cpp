#include<iostream>
#include<string>
using namespace std;
class product
{
  string pname;
  int pcode;
public:
  product()
  {
  pname="";
  pcode=0;
  }
product(string tname,int tpcode)
{
pname=tname;
pcode=tpcode;
}
  void printdetails()
  {
  cout<<"\n \t\tproduct name      "<<pname;
  cout<<"\n \t\tproduct code       "<<pcode;
  }
};
class supplier
{
  int id;
  string name;
  int tot;
  product *list;
public:
  supplier()
  {
  name="";

