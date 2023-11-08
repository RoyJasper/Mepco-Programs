#include<iostream>
#include<string>
using namespace std;
class product
{
	string pname;
	int pcode;
public:
	product()
	{
	pname="";
	pcode=0;
	}
product(string tname,int tpcode)
{
pname=tname;
pcode=tpcode;
}
	void printdetails()
	{
	cout<<"\n \t\tproduct name      "<<pname;
	cout<<"\n \t\tproduct code       "<<pcode;
	}
};
class supplier
{
	int id;
	string name;
	int tot;
	product *list;
public:
	supplier()
	{
	name="";
	list=0;
	tot=0;
	}
supplier(int tid,string tna,product *tlist,int ttot)
{
tot=ttot;
id=tid;
name=tna;
list =new product [ttot];
for(int i=0;i<ttot;i++)
list[i]=tlist[i];
}
supplier(supplier &dum)
{
	tot=dum.tot;
	id=dum.id;
	name=dum.name;
	list=new product[dum.tot];
	for(int i=0;i<dum.tot;i++)
	list[i]=dum.list[i];
}
~supplier()
{
cout<<"\n destructor is invoked\n";
delete []list;
cout<<"\n deleted";
}
	void displaydetails()
	{
	cout<<"\n supplier name   "<<name;
	cout<<"\n supplier id     "<<id;
	cout<<"\n list of item supplied : \n";
	for(int i=0;i<tot;i++)
	list[i].printdetails();
	}
};
int main()
{
 product x[10];
string ti,tna;
int n,i,co,tid,tt,m;
//cout<<"\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
//cout<<"\n           ROY JASPER'S SUPERRMARKET  \n";
//cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
cout<<"\n enter the number of products in the shop";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n enter the product name    ";
cin>>ti;
cout<<"\n enter the product code   ";
cin>>co;
x[i]=product(ti,co);
}
cout<<"\n enter the first supplier name   ";
cin>>tna;
cout<<"\n enter the first supplier id    ";
cin>>tid;
cout<<"\n enter the  number of item supplied   ";
cin>>m;
supplier a(tid,tna,x,m);
cout<<"\n enter the second supplier name    ";
cin>>tna;
cout<<"\n enter the second supplier id    ";
cin>>tid;
cout<<"\n enter the  number of item supplied  ";
cin>>m;
supplier b(tid,tna,x+2,m);

supplier c(b);
cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n         ROY JASPER'S SUPERMARKET     \n";
cout<<"\n    Suppliers and  supplied item details\n  ";
cout<<"\n************************************************\n";
a.displaydetails();
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
b.displaydetails();
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//c.displaydetails();
cout<<"\n_________________________________________________\n";
return 0;
}

