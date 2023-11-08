#include<iostream>
#include<string>
using namespace std;
class student
{
public:
int rno;
string dept;
string name;
void readdetails()
{
cout<<"\nEnter roll no";
cin>>rno;
cout<<"\nEnter name ";
cin>>name;
cout<<"\nEnter department";
cin>>dept;
}
void printdetail()
{
cout<<"NAME"<<"\t";
cout<<"ROLLNO"<<"\t";
cout<<"DEPT"<<"\t";
cout<<"S.AMOUNT"<<"\t";
cout<<"S.TYPE"<<"\n";
}
};
class scholarship
{
string schotype;
string nam;
int schoamnt; 
public:      
void readdetail();
friend void search(student [],scholarship [],int,int);
};
void scholarship::readdetail()
{   
cout<<"Enter name of student receiving scholarship";
cin>>nam;
cout<<" scholarship amount"<<schoamnt;
cout<<"Enter scholarship type";
cin>>schotype; 
}   
void search(student a[],scholarship b[],int n,int m)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(a[i].name==b[j].nam)
{
cout<<b[j].nam<<"\t";
cout<<a[i].rno<<"\t";
cout<<a[i].dept<<"\t";
cout<<b[j].schoamnt<<"\t";
cout<<b[j].schotype<<"\n";
}
}}
}
main()
{
student a[10];
scholarship b[10];
int i,n,m,j;
cout<<"Enter no of ";
for(i=0;i<n;i++)
{
a[i].readdetails();
cout<<"\nEnter the no of students who are receiving scholarship ";
cin>>m;
for(j=0;j<m;j++)
search(a,b,n,m);
}
}

