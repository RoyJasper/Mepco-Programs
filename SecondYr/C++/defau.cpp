#include<iostream>
using namespace std;
bool checkpass(int m1,int m2,int m3,int pass=50);
class student
{
 private:
       int rno,m1,m2,m3;
       string name,dept;
 public:
       void read();
       int print();
};
void student :: read()
{
 cout<<"enter rno";
 cin>>rno;
 cout<<"enter name";
 cin>>name;
 cout<<"enter m1";
 cin>>m1;
 cout<<"enter m2";
 cin>>m2;
 cout<<"enter m3";
 cin>>m3;
 cout<<"enter department";
 cin>>dept;
}
int student :: print()
{
 int tot;
 int result;
 result= checkpass(m1,m2,m3);
 tot=m1+m2+m3;
 cout<<"\n student rno"<<rno;
 cout<<"\n student name"<<name;
 cout<<"\nMark 1 "<<m1<<"\nMark 2 "<<m2<<"\nMark 3 "<<m3;
 cout<<"\ttotal "<<tot;
 if(result==1)
  return 1;
 else
  return 0;
}
bool checkpass(int m1,int m2,int m3,int pass)
{
 if((m1>50)&& (m2>50)&&(m3>50))
  return true;
 else
  return false;
}
int main()
{
 student s[20];
 int n=2,i,k;
 float c=0;
 cout<<"enter no of students";
 cin>>k;
 for(i=0;i<k;i++)
 {
  cout<<"\nEnter details of student no "<<i+1<<"\n";
  s[i].read();
 }
 for(i=0;i<k;i++)
 {
  c=s[i].print()+c;
 }
 c=c/k;
 c=c*100;
 cout<<"\ntotal percentage is "<<c;
 return 0;
}

