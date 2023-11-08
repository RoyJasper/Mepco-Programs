#include<iostream>
#include<string>
using namespace std;
class subject
{
	string stitle;
	int scode;
public:
	subject()
	{
	stitle="";
	scode=0;
	}
subject(string tstitle,int tscode)
{
stitle=tstitle;
scode=tscode;
}
	void printdetails()
	{
	cout<<"\n \t\tsubject title      "<<stitle;
	cout<<"\n \t\tsubject code       "<<scode;
	}
};
class examiner
{
	int id;
	string name;
	int tot;
	subject *list;
public:
	examiner()
	{
	name="";
	list=0;
	tot=0;
	}
examiner(int tid,string tna,subject *tlist,int ttot)
{
tot=ttot;
id=tid;
name=tna;
list =new subject [ttot];
for(int i=0;i<ttot;i++)
list[i]=tlist[i];
}
	examiner(examiner &dum)
	{
	tot=dum.tot;
	id=dum.id;
	name=dum.name;
	list=new subject[dum.tot];
	for(int i=0;i<dum.tot;i++)
	list[i]=dum.list[i];
}
~examiner()
{
cout<<"\n destructor is invoked\n";
delete []list;
cout<<"\n deleted";
}
	void displaydetails()
	{
	cout<<"\n examiner name     "<<name;
	cout<<"\n examiner id     "<<id;
	cout<<"\n list of papers evaluated :   \n";
	for(int i=0;i<tot;i++)
	list[i].printdetails();
	}
};
int main()
{
 subject x[10];
string ti,tna;
int n,i,co,tid,tt,m;
cout<<"\n enter the number of subjects    \n";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n enter the subject title    ";
cin>>ti;
cout<<"\n enter the subject code   ";
cin>>co;
x[i]=subject(ti,co);
}
cout<<"\n enter the first examiner name   ";
cin>>tna;
cout<<"\n enter the examiner id    ";
cin>>tid;
cout<<"\n enter the  number of subject to be evaluated   ";
cin>>m;
examiner a(tid,tna,x,m);
cout<<"\n enter the second examiner name    ";
cin>>tna;
cout<<"\n enter the examiner id    ";
cin>>tid;
cout<<"\n enter the  number of subject to be evaluated   ";
cin>>m;
examiner b(tid,tna,x+2,m);
//examiner c(b);
cout<<"\n************************************************\n";
cout<<"\n       examiner and their subject details\n  ";
cout<<"\n************************************************\n";
a.displaydetails();
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
b.displaydetails();
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//c.displaydetails();
//cout<<"\n*************************************************\n";
return 0;
}

