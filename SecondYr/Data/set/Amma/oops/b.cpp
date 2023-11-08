#include<iostream>
#include<string>
using namespace std;
class student
{
 public:
     int rno;
     string name,dept;
     void getdetails()
     {
      cout<<"\nenter rollno";
      cin>>rno;
      cout<<"\nenter name";
      cin>>name;
      cout<<"\nenter department";
      cin>>dept;
     }
     void printdetails()
     {
      cout<<"\nroll no   :"<<rno;
      cout<<"\n name     :"<<name;
      cout<<"\ndepartment:"<<dept;
     }
};

class mark :public student
{
public:
    int m[9],tot,cr[10],o;
    float avg;
    void readmark()
    {
     getdetails();
     tot=0;
     cout<<"\nenter subject marks";
     o=0;
     for(int i=0;i<9;i++)
     {
      cout<<"\nmark"<<i+1<<":";
      cin>>m[i];
      cout<<"\nenter credit";
      cin>>cr[i];
      o=cr[i]+o;
      tot=tot+m[i];
     }
     avg=tot/9;
    }
    void printmark()
    {
     printdetails();
     cout<<"\nmarks";
     for(int i=0;i<9;i++)
        cout<<"\n"<<m[i];
     cout<<"\ntotal  :"<<tot;
     cout<<"\naverage:"<<avg;
    }
};
class grade:public mark
{
 public:
 float cgpa,gpa;
 void calculate()
 {
  int k,v;
  readmark();
  gpa=0;
  for(int i=0;i<9;i++)
  {
   k=m[i]/10;
   v=k*cr[i];
   gpa=gpa+v;
  }
  cgpa=gpa/o;;
 }
 void print()
 {
  printmark();
  cout<<"\n CGPA :"<<cgpa;
 }
};
int main()
{
 grade s[20];
 int n,i;
 cout<<"\n enter no of students";
 cin>>n;
 for(i=0;i<n;i++)
  s[i].calculate();
 for(i=0;i<n;i++)
  s[i].print();
}

