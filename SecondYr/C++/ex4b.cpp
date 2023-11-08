#include<iostream>
#include<string>
using namespace std;
class scholarship;
class student
{
	private:
		int rno;
		string na,dept;
	public:
		void readdetails()
		{
			cout<<"Enter the roll no:";
			cin<<rno;
			cout<<"Enter the Name:";
			cin>>name;
			cout<<"Enter the Department:";
			cin>>dept;
		}
	friend void search(student[],scholarship[],int);
};
class scholarship
{
	private:
		string stype,a;
		int samt;
	public:
		void readdetails();
	friend void search(student[],scholarship[],int);
};
void scholarship::readdetails()
{
	cout<<"Enter the name of the person recieving scholarship:";
	cin>>a;
	cout<<"Enter the scholarship amount:";
	cin>>samt;
	cout<<"Enter the scholarship type:";
	cin>>stype;
}
void search(student a[],scholarship b[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;i<n;i++)
			if(a[i].na==b[j].a)
			{
				cout<<"\nName:"<<a[i].na;
				cout<<"\nRoll:"<<a[i].rno;
				cout<<"\nDepartment:"<<a[i].dept;
				cout<<"\nScholarship Type:"<<b[j].stype;
				cout<<"\nScholarship Amount:"<<b[j].samt;
			}
}
void main()
{
	student a[10];
	scholarship b[20];
	int n;
	cout<<"Enter the number of students:";
	cin>>n;
	for(int i=0;i<n;i++)
		a[i].readdetails();
	for(i=0;i<n;i++)
		b[i].readdetails();
search(a,b,n);
}