#include<iostream>
#include<string>
using namespace std;
class premiumcalc
{
private:
    int lno,yr,am;
    float roi,pre;
    string name,lt;
public:
    void getdetails();
    void calculate();
    void display();
};
void premiumcalc::getdetails()
{
    cout<<"\nEnter name";
    cin>>name;
    cout<<"\nEnter loan no";
    cin>>lno;
    cout<<"\nEnter loan type";
    cin>>lt;
    cout<<"\nEnter no of years";
    cin>>yr;
    cout<<"\nEnter rate of intrest ";
    cin>>roi;
    cout<<"\nEnter loan amount ";
    cin>>am;
}
void premiumcalc::calculate()
{
    float si,tot;
    si=am*yr*roi/100;
    tot=si+am;
    pre=tot/(12*yr);
}
void premiumcalc::display()
{
    cout<<"\n name is"<<name;
    cout<<"\n loan no is"<<lno;
    cout<<"\n loan type is"<<lt;
    cout<<"\n no of years is"<<yr;
    cout<<"\n rate of intrest is "<<roi;
    cout<<"\n loan amount is"<<am;
    cout<<"\npremium amount is "<<pre;
}
int main()
{
    premiumcalc pd;
    premiumcalc *pc=new premiumcalc;
    pc->getdetails();
    pc->calculate();
    pc->display();
   // string premiumcalc::*ptr=&premiumcalc::name;
    //pd *ptr="roy";
    //premiumcalc *newpc->&pd;
    //cout<<"name is"<<newpc ->name;
}
