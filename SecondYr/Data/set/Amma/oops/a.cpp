

#include<iostream>
#include<string>
using namespace std;
class student
{
 public:
     int rno;
     string dept,name;
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
class inmark :public student
{
public:
    int m[6],tot;
    float avg;
    void readmark()
    {
     cout<<"\ninternal mark";
     cout<<"\n*************";
     getdetails();
     tot=0;
     cout<<"\nenter subject marks";
     for(int i=0;i<6;i++)
     {
      cin>>m[i];
      tot=tot+m[i];
     }
     avg=tot/6;
    }
    void printmark()
    {
     cout<<"\ninternal marks";
     cout<<"\n**************";
     printdetails();
     cout<<"\nmarks";
     for(int i=0;i<6;i++)
        cout<<"\n"<<m[i];
     cout<<"\ntotal  :"<<tot;
     cout<<"\naverage:"<<avg;
    }
};
class unmark:public student
{
 public:
     int m[9],tot;
     float avg;
     void read()
     {
      cout<<"\nuniversity marks";
      cout<<"\n****************";
      getdetails();
      tot=0;
      cout<<"\nenter marks";
      for(int i=0;i<9;i++)
      {
       cin>>m[i];
       tot=tot+m[i];
      }
      avg=tot/9;
     }
     void print()
     {
      int i;
      cout<<"\nuniversity marks";
      cout<<"\n****************";
      printdetails();
      cout<<"\n marks are";
      for(i=0;i<9;i++)
      {
       cout<<"\n"<<m[i];
      }
      cout<<"\n total:"<<tot;
      cout<<"\n average:"<<avg;
     }

};
int main()
{
 int n,i;
 cout<<"\nenter no of students";
 cin>>n;
 inmark in[20];
 unmark un[20];
 for(i=0;i<n;i++)
  in[i].readmark();
 for(i=0;i<n;i++)
  un[i].read();
 for(i=0;i<n;i++)
  in[i].printmark();
 for(i=0;i<n;i++)
  un[i].print();
}

