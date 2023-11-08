#include<string>
#include<iostream>
using namespace std;
class employee
{
 private:
  int emno;
  string name,dept;
  float bp,da,hra,ded,gp,np;
 public:
  void read();
  void print();
  void calculate();
};
void employee::read()
{
 cout<<"Enter emp no \n";
 cin>>emno;
 cout<<"Enter name \n";
 cin>>name;
 cout<<"Enter dept \n";
 cin>>dept;
 cout<<"Enter basic pay \n";
 cin>>bp;
}
void employee::calculate()
{
da=0.7*bp;
hra=0.05*bp;
ded=0.1*bp;
gp=bp+da+hra;
np=gp-ded;
}
void employee::print()
{
 cout<<"\nName is "<<name;
 cout<<"\nNo is "<<emno;
 cout<<"\ndept is "<<dept;
 cout<<"\nBasic pay is "<<bp;
 cout<<"\nDA is "<<da;
 cout<<"\nHRA is "<<hra;
 cout<<"\nDeduction is"<<ded;
 cout<<"\nGrosspay is "<<gp;
 cout<<"\nNetpay is "<<np;
}
int main()
{
 int n,i;
 employee e[10];
 cout<<"\n\nEnter no of Employee";
 cin>>n;
 for(i=0;i<n;i++)
  {
   e[i].read();
   e[i].calculate();
   e[i].print();
  }
 return 0;
}
 




