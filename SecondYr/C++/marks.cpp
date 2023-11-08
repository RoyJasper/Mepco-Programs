#include<iostream>
#include<string>
using namespace std;
bool checkpass(int m1,int m2,int m3,int pass=50)
class student
{
private:
int rno;
string name;
string dept;
int m1,m2,m3,pass;
public:
void readdetails();
void printdetails();
};
void student::readdetails()
{
cout<<"\nEnter the rollno,name,3 subject marks,dept";
cin>>rno>>name>>m1>>m2>>m3>>dept;
}
int student::printdetails()
{
int total;
int result;
result=checkpass(m1,m2,m3,50);
total=m1+m2+m3;
cout<<"\nStudent name is "<<name;
cout<<"\nRoll no is"<<rno;
cout<<"\nMarks are"<<m1<<m2<<m3;
cout<<"\nTotal is "<<total;
if(result==1)
return 1;
else
return 0;
}
bool checkpass(int m1,int m2,int m3,int pass)
{
if((m1>pass)&&(m2>pass)&&(m3>pass))
return 1;
else
return 0;
}
int main()
{
student s[50];
int n,i;
float c=0.00;
cout<<"\nEnter the students";
cin>>n;
for(i=0;i<n;i++)
{
s[i].readdetails();
c=s[i].printdetails()+c;
}
c=c/n;
c=c*100;
cout<<"\nThe total percentage of class is "<<c;
}
