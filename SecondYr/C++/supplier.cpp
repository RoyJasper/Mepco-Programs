#include<iostream>
#include<string>
using namespace std;
class product
{
int productnumber;
string productname;
public:
product()
{
productnumber=0;
productname="";
}
product(int pn,string pa)
{
productnumber=pn;
productname=pa;
}
void printdetail()
{
cout<<"\t"<<productname;
}
};
class supplier
{
int supplierid,totalproduct;
string suppliername;
product *supplierproduct;
public:
supplier(supplier &sc)
{
supplierid=sc.supplierid;
suppliername=sc.suppliername;
supplierproduct=new product[sc.totalproduct];
for(int i=0;i<sc.totalproduct;i++)
{
supplierproduct[i]=sc.supplierproduct[i];
}
totalproduct=sc.totalproduct;
}
~supplier()
{
delete [] supplierproduct;
}
supplier(int sid=0,string sna="",product *sp=NULL,int stp=0)
{
supplierid=sid;
suppliername=sna;
supplierproduct=new product[stp];
for(int i=0;i<stp;i++)
{
supplierproduct[i]=sp[i];
}
totalproduct=stp;
}
void printdetails();
};
int main()
{
int n,id,sid,stproduct,suid;
string name,sname,suname;
cout<<"ENTER THE NO OF PRODUCTS";
cin>>n;
product item[n];
for(int i=0;i<n;i++)
{
cout<<"ENTER THE PRODUCT ID AND PRODUCT NAME";
cin>>id>>name;
item[i]=product(id,name);
}
cout<<"ENTER THE SUPPLIER NAME SUPPLIED ID";
cin>>sname>>sid;
cout<<"ENTER THE TOTAL PRODUCTS";
cin>>stproduct;
supplier ram(sid,sname,item,stproduct);
cout<<"ENTER THE SUPPLIER NAME SUPPLIED ID";
cin>>sname>>sid;
cout<<"ENTER THE TOTAL PRODUCTS";
cin>>stproduct;
supplier raj(sid,sname,item,stproduct);
supplier rahul(ram);
ram.printdetails();
raj.printdetails();
rahul.printdetails();
}
void supplier :: printdetails()
{
int j=0;
cout<<"\nTHE NAME IS"<<suppliername;
cout<<"\nTHE ID ID"<<supplierid;
cout<<"\nTHE SUPPLIED PRODUCT ARE";
for(j=0;j<totalproduct;j++)
supplierproduct[j].printdetail();
}


