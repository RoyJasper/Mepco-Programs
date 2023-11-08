#include<fstream>
#include<iostream>
using namespace std;
class student
{
 int rno;
 string name;
 public:
  student(int trno=0,string tname="  ")
   {
    rno=trno;
    name=tname;
   }
  void get()
   {
    cout<<"\nEnter rno and name";
    cin>>rno>>name;
   }
  void print()
   {
    cout<<"\n rno is "<<rno;
    cout<<"\n Name is "<<name;
   }  
};
class internal:public student
{
 int mark[6];
 int tot;
 float avg;
 public:
  interanal(int trno,string tname,int tm[],float av:(trno,tname))
   {
    for(int i=0;i<6;i++)
       mark[i]=tm[i];
    tot=to;
    avg=av;
   }
};
