#include<iostream>
#include<string>
using namespace std;
class student
{
 private:
  int rno,marks[6],tot;
  string name,dept;
  float avg;
 public:
  void readdetails();
  void printdetails();
  void calculate();
};
void student::readdetails()
{
 int i;
 cout<<"Enter roll no \n";
 cin>>rno;
 cout<<"Enter name \n";
 cin>>name;
 cout<<"Enter dept \n";
 cin>>dept;
 cout<<"Enter marks \n";
 for(i=0;i<6;i++)
  cin>>marks[i];
}
void student::calculate()
{
 tot=0;
 int i;
 for(i=0;i<6;i++)
  {
  tot=tot+marks[i];
  }
 avg=tot/6;
}
void student::printdetails()
{
 int i;
 cout<<"\nRoll no is "<<rno;
 cout<<"\nName is"<<name;
 cout<<"\nDept is "<<dept;
 cout<<"\nMarks are";
  for(i=0;i<6;i++)
  {
   cout<<"\t"<<marks[i];
  }
 cout<<"\nTotal is"<<tot;
 cout<<"\nAvg is"<<avg;
}
int  main()
{
 int n,i;
 student s[10];
 cout<<"\nEnter no of students";
 cin>>n;
 for(i=0;i<n;i++)
  {
   s[i].readdetails();
   s[i].calculate();
   s[i].printdetails();
  }
 return 0;
}
 







