#include<string>
#include<iostream>
using namespace std;
class bank
{
 private:
  int acno,bal,deb,cre;
  string name,actyp;
 public:
  void createacc();
  void withdraw();
  void display();
  void balance();
  void deposit();
};
void bank::createacc()
{
 cout<<"Enter acc no \n";
 cin>>acno;
 cout<<"Enter name \n";
 cin>>name;
 cout<<"Enter account type \n";
 cin>>actyp;
 cout<<"Enter balance \n";
 cin>>bal;
}
void bank::withdraw()
{
 cout<<"Enter Withdraw ammount\n";
 cin>>deb;
 if(bal>=deb)
  {
   bal-=deb;
   cout<<"Amount is withdrawn\n";
  }
 else
  cout<<"Error during transation please try again\n";
}
void bank::balance()
{
 cout<<"\nBalance is"<<bal;
}
void bank::display()
{
 cout<<"\nName is "<<name;
 cout<<"\nAccNo is "<<acno;
 cout<<"\nAcc Type is "<<actyp;
 cout<<"\nBalance amount is "<<bal;
}
void bank::deposit()
{
 cout<<"Enter amount to be credited";
 cin>>cre;
 bal+=cre;
 cout<<"Congrats!!  Creditted";
}
int main()
{
 bank b[10];
 int n,i;
 cout<<"Enter no of clients\n";
 cin>>n;
 for(i=0;i<n;i++)
  {
    b[i].createacc();
    b[i].withdraw();
    b[i].deposit();
    b[i].balance();
    b[i].display();
  }
}
