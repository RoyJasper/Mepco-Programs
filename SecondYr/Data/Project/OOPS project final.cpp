#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<typeinfo>
using namespace std;
class loan
{
  private:
    int cal;
    int age;
    int hect;
    int bal;
    int gold;
    int sal;
    int prop;
    int acno;
    string bname;
    string name;
    int stat;
  public:
    int req;
    void account()
    {
    int i,j,k,l;
    stat=0,bal=0,hect=0,gold=0,prop=0;
    string v;
    char g;
    cout<<"\n\n\n Please enter your application number  ";
    cin>>req;
    cout<<"\n Enter your Name ";
    cin>>name;
    cout<<"\n Enter your Age ";
    cin>>age;
    cout<<"\n Enter your Monthly Salary ";
    cin>>sal;
    cout<<"\n Whether you have any bank account or not Y/N ";
    cin>>g;
    if(g=='y')
    {
    stat++;
    cout<<"\n Enter bank name ";
    cin>>bname;
    cout<<"\n Enter the Account number ";
    cin>>acno;
    cout<<"\n Enter the Amount in your account ";
    cin>>bal;
    }
    else
    bal=0;
    cout<<"\n Whether you have ornaments or not Y/N ";
    cin>>g;
    gold=0;
    if(g=='y')
    {
    stat++;
    cout<<"\n Enter the quantity of gold that you have (in Grams): ";
    cin>>i;
    cout<<"\n Enter the quantity of silver that you have (in Grams): ";
    cin>>j;
    cout<<"\n Enter the quantity of platinum that you have (in Grams): ";
    cin>>k;
    i=i*1500;
    j=j*20;
    k=k*5000;
    gold=i+j+k;
    }
    else
    gold=0;
    cout<<"\n Whether you have a vehicle or not Y/N ";
    cin>>g;
    prop=0;
    if(g=='y')
    {
    stat++;
    i=0,j=0,k=0;
    cout<<"\nEnter the Number of vehicle that you have";
    cin>>l;
    while(l!=0)
    {
    cout<<"\n Enter the vehicle you have ";
    cin>>v;
    if(v=="car")
    i=i+200000;
    else if(v=="bike")
    j=j+30000;
    else
    k+=2000;
    l--;
    }
    prop=i+j+k;
    }
    else
    prop=0;
    cout<<"\n Whether you have land or not Y/N ";
    cin>>g;
    if(g=='y')
    {
    stat++;
    cout<<"\n  How many acres that you have ?  ";
    cin>>hect;
    hect=hect*10000;
    }
    else
    hect=0;
    }
    void calculate()
    {
    cal=0;
    cal=cal+hect;
    cal=cal+bal;
    cal=cal+gold;
    cal=cal+sal;
    cal=cal+prop;
    if(age>=50)
    cal=cal/2;
    else
    cal=cal*0.4;
    }
    void print()
    {
    if(stat!=0||sal>=20000)
    {
    cout<<"\n\n\n";
    //cout<<"\nU ARE SOOO LUCKY";
    cout<<"\n Loan is sanctioned for  "<<name;
    cout<<"\n Amount sanctioned is "<<cal;
    }
    else if(stat==0)
      cout<<"\n Apologise you are not eligible for getting loan .....:-( ";
    }
    void print1()
    {
    if(stat!=0||sal>=20000)
    {
    cout<<"\n"<<name;
    cout<<"\t Amount sanctioned for you is "<<cal;
    }
    else if(stat==0)
    {
    cout<<"\n"<<name;
    cout<<"\t\t Sorry you are not eligible for loan.....:-( ";
    }
    }
    friend int search(loan [],int ,int);
    };
    void intro()
    {
	cout<<"\n\n\t\t WELCOME  TO BANK LOAN SANCTION SYSTEM";
	cout<<"\n\n\n\n PROGRAM CODED BY :  M.VIGNESH ,C.S.ROY JASPER , S.SIVA KUMARAN ";
	cout<<"\n\n\n\n OF MEPCO SCHLINK ENGINEERING COLLEGE ";
	cout<<"\n\n\n\n";
    }
    int search(loan oa[20],int re,int n)
    {
    for(int i=0;i<n;i++)
    {
    if(oa[i].req==re)
    {
    return i;
    }
    }
    }
    int main()
    {
    int re;
    int d;
    int a[30];
    int i=0;
    int f;
    int n=0;
    loan ln[20];
    loan oa[20];
    intro();
    cin.get();
    fstream cfile("bank.dat",ios::in|ios::out|ios::trunc|ios::binary);
    cout<<"\n\n"<<"\t\t\t"<<"WELCOME TO LOAN SANCTION SYSTEM "<<"\n";
    cout<<"\n\nEnter the number of applicants  ";
    cin>>n;
    do
    {
		cout<<"\n\n\n\t\tMAIN MENU ";
		cout<<"\n\n\t01] SUBMMIT APPLICATION FORM FOR LOAN ";
		cout<<"\n\n\t02] CHECKING";
		cout<<"\n\n\t03] DISPLAY ALL APPLICANTS ";
		cout<<"\n\n\t04] EXIT";
		cout<<"\n\n\tEnter Your Option (1-4) ";
		cin>>f;
		switch(f)
		{
		case 1:
		        for(int i=0;i<n;i++)
                {
                ln[i].account();
                cfile.seekp(i*sizeof(loan),ios::beg);
                cfile.write((char *) &ln[i],sizeof(loan));
                cfile.seekg(i*sizeof(loan),ios::beg);
                cfile.read((char *) &oa[i],sizeof(loan));
                oa[i].calculate();
                cout<<"\n\n You have applied for loan successfully !! ";
                }
		    	break;
		case 2:
                cout<<"\nPlease enter application number for loan verification  :  ";
                cin>>re;
                d=search(oa,re,n);
                cfile.seekg(d*sizeof(loan),ios::beg);
                cfile.read((char *)&oa[d],sizeof (loan));
                oa[d].calculate();
                oa[d].print();
                break;
		case 3:
		        cout<<"=========================================================";
		        cout<<"\nNAME\t\tSTATUS\n";
		        cout<<"=========================================================";
                for(int j=0;j<n;j++)
                {
                cfile.seekg(j*sizeof(loan),ios::beg);
                cfile.read((char *)&oa[j],sizeof (loan));
                oa[j].calculate();
                oa[j].print1();
                }
                break;
		 case 4:
			cout<<"\n\n\tThanks for using Our System ";
			return 0;
			break;
		 default :
		     cout<<"\n Please enter correct choice...... ";
		     break;
		}
		//cin.ignore();
		//cin.get();
	}while(f!=4);

    }
