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
cout<<"Enter roll no";
cin>>rno;
cout<<"Enter name";
cin>>name;
cout<<"Enter department";
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
cout<<"Enter the name";
cin>>name;
cout<<"Enter department";
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
cout<<"ENTER THE NAME OF THE STUDENT'S RECIEVING SCHOLARSHIPS";
cin>>nam;
cout<<"ENTER THE SCHOLARSHIP AMOUNT";
cin>>schoamnt;
cout<<"ENTER THE SCHOLARSHIP TYPE";
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
student c;
student a[10];
scholarship b[10];
int i,n,m,j;
cout<<"ENTER THE NUMBER OF STUDENTS";
cin>>n;
for(i=0;i<n;i++)
{
a[i].readdetail();
cout<<"ENTER THE NUMBER OF STUDENTS WHO R RECIEVING THEIR SCHOLARSHIP";
cin>>m;
for(j=0;j<m;j++)
search(a,b,n,m);
}
}


