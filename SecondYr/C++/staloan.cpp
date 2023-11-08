#include<iostream>
#include<string>
using namespace std;
class loan
{
public:
static int totalln;
static int housing;
static int ln;
static void displaytotalloans();
static void displayhousing();
static void displayloan();
private:
int accno;
string name;
string ltype;
int amt;
int yr;
public:
void read();
};
void loan::read()
{
cout<<"\nEnter the account no,name,loan type,loan amount,no of years";
cin>>accno>>name>>ltype>>amt>>yr;
totalln++;
if(ltype=="housing")
housing++;
if(amt>200000)
ln++;
}
//void loan::print()
//{
//loan::displaytotalloans();
//loan::displayhousing();
//loan::displayloan();
//}
int loan::totalln;
int loan::housing;
int loan::ln;
void loan::displaytotalloans()
{
cout<<"\nNo of loans sanctioned is" <<loan::totalln;
}
void loan::displayhousing()
{
cout<<"\nNo of loans sanctioned for housing is "<<loan::housing;
}
void loan::displayloan()
{
cout<<"\nNo of accounts having loan amount greater than 200000 is"<<loan::ln;
}
int main()
{
int i,n;
loan l[50];
cout<<"\nEnter the no of loan accounts";
cin>>n;
for(i=0;i<n;i++)
{
l[i].read();
}
loan::displaytotalloans();
loan::displayhousing();
loan::displayloan();
}


