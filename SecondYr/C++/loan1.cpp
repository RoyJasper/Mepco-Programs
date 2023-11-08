#include<iostream>
#include<string>
using namespace std;
class loan
{
 private:
 int accno;
 string name;
 string ltype;
 int amount;
 int year;
 public:
 static int totalloans;
 static int housing;
 static int loans;
 static void displaytotalloans();
 static void displayhousing();
 static void displayloan();
 void read();
 void print();
};
void loan::read()
{
 cout<<"\nenter the account no:";
 cin>>accno;
 cout<<"enter the name";
 cin>>name;
 cout<<"enter the loan type";
 cin>>ltype;
 cout<<"enter the loan amount";
 cin>>amount;
 cout<<"enter the no of years";
 cin>>year;
 totalloans++;
 if(ltype=="housing")
 housing++;
 if(amount>2000000)
 loans++;
}
int loan::totalloans;
int loan::housing;
int loan::loans;
void loan::displaytotalloans()
{
 cout<<"\nno of loans sanctioned is"<<loan::totalloans;
}
void loan::displayhousing()
{
cout<<"\nloans sanctioned for housing is"<<loan::housing;
}
void loan::displayloan()
{
cout<<"no of account having loan greater than 2000000 is"<<loan::loans;
}
int main()
{
 int i,n;
 loan l[10];
 cout<<"\nenter the no of loan accounts";
 cin>>n;
 for(i=0;i<n;i++)
 {
  l[i].read();
 }
 loan::displaytotalloans();
 loan::displayhousing();
 loan::displayloan();
}
