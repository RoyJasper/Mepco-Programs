#include<iostream>
#include<string>
using namespace std;
class scholarship;
class student
{
 public:
 string name;
 string dept;
 int rno;
 void readdetails();
 friend void search(student[],scholarship[],int);
};
void student::readdetails()
{
 cout<<"enter the name";
 cin>>name;
 cout<<"enter th roll no";
 cin>>rno;
 cout<<"enter the dept";
 cin>>dept;
}
class scholarship
{
 public:
 string schotype;
 int schamt;
 string nam;
 void readdetail();
 friend void search(student[],scholarship[],int);
};
void scholarship::readdetail()
{
 cout<<"enter the name of the student who are receiving scholarship";
 cin>>nam;
 cout<<"enter the scholarship type";
 cin>>schotype;
 cout<<"enter the scholarship amount";
 cin>>schamt;
}
void search(student s[10],scholarship x[20],int n)
{
 int i,j;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
 if(s[i].name==x[j].nam)
   {
    cout<<"\n"<<s[i].name;
    cout<<"\t"<<s[i].rno;
    cout<<"\t"<<s[i].dept;
    cout<<"\t"<<x[j].schotype;
    cout<<"    "<<x[j].schamt;
    cout<<"\n";
   }
  }
 }
}
int main()
{
 int i,n;
 student s[10];
 scholarship x[20];
 cout<<"enter the no of students";
 cin>>n;
 for(i=0;i<n;i++)
 {
  s[i].readdetails();
 }
 for(i=0;i<n;i++)
 {
  x[i].readdetail();
 }
 cout<<"name\t";
 cout<<"rno\t";
 cout<<"dept\t";
 cout<<"schotype";
 cout<<" schamount";
 search(s,x,n);
}



