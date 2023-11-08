#include<iostream>
#include<string>
using namespace std;
class student
{
int roll;
string name;
public:
 void getdetails()
 {
cout<<"\n Enter the name of student   ";
cin>>name;
cout<<"\n Enter rollnumber of Student   ";
cin>>roll;
 }
void printdetails()
 { 
cout<<"\n  Name is   "<<name;
cout<<"\n  Rollnumber is  "<<roll;
 }
};
class internalmark : public student
{
int mark[6];
int tot;
float avg;
public:
void readmarks()
 {
cout<<"\n Enter the  internal marks of 6 Subjects   ";
for(int i=0;i<6;i++)
{
 cin>>mark[i];
}
 }
void calculate()
{
tot=0;
for(int i=0;i<6;i++)
{
tot=tot+mark[i];
}
avg=tot/6;
}
void printmarks()
{
cout<<"\n marks are \n";
for(int i=0;i<6;i++)
 { 
cout<<mark[i]<<"\t";
 }
cout<<"\n Total is  "<<tot;
cout<<"\n Average is  "<<avg;
}
};
class universitymark : public student
{
int marks[9];
int tott;
float avgg;
public:
void readunimarks()
{
cout<<"\n Enter the  university marks of 9 subjects   ";
for(int i=0;i<9;i++)
 {
 cin>>marks[i];
 }
}
void calculateunimarks()
{
tott=0;
for(int i=0;i<9;i++)
{
tott=tott+marks[i];
}
avgg=tott/9;
}
void printunimarks()
{
cout<<"\n University marks are......   \n ";
for(int i=0;i<9;i++)
{
 cout<<marks[i]<<"\t";
}
cout<<"\n Total is "<<tott;
cout<<"\n Average is "<<avgg;
}
};
int main()
{
int n,i;
internalmark im[20];
universitymark um[20];
cout<<"\n Enter the number of students    ";
cin>>n;
for(i=0;i<n;i++)
{
im[i].getdetails();
im[i].readmarks();
im[i].calculate();
um[i].readunimarks();
um[i].calculateunimarks();
}
//cout<<"\n ***************************************************\n";
cout<<"\n                 Student mark details   \n ";
//cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
for(i=0;i<n;i++)
{
im[i].printdetails();
im[i].printmarks();
um[i].printunimarks();
cout<<"\n----------------------------------------------\n";
}
return 0;
}


