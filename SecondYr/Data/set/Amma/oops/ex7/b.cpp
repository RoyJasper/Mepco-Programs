#include<iostream>
using namespace std;
class employee
{
int eno;
string ename;
string dept;
int salary;
public:
friend ostream& operator << (ostream&,employee&);
friend istream& operator >> (istream&,employee&);
};
ostream& operator << (ostream &tout,employee &te)
{
tout<<"\n employee  name is      "<<te.eno;
tout<<"\n employee name   is     "<<te.ename;
tout<<"\n employee department is    "<<te.dept;
tout<<"\n employee salary is        "<<te.salary;
return tout;
}
istream& operator >> (istream &tin,employee &te)
{
cout<<"\n enter the name      :";
tin>>te.ename;
cout<<"\n enter the number    :";
tin>>te.eno;
cout<<"\n enter the depaertment   :";
tin>>te.dept;
cout<<"\n enter the salary        :";
tin>>te.salary;
return tin;
}
int  main()
{
employee e;
cin>>e;
cout<<"\n******************************************************";
cout<<"\n employee details\n";
cout<<"\n******************************************************";
cout<<e;
cout<<"\n******************************************************";
return 0;
}
