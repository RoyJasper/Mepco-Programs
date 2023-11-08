#include<iostream>
#include<string>
using namespace std;
class student
{
    int regno;
    string name;
public:
    void readdetails()
    {

        cout<<"\n Enter the register number      ";
        cin>>regno;
        cout<<"\n Enter name     ";
        cin>>name;
    }
    void printdetails()
    {

        cout<<"\n Register number is      "<<regno;
        cout<<"\n Student name is          "<<name;
    }
};
class markdetails:public student
{

    int mark[9];
    int tot;
    float avg;
   int tm[9];

public:
     int credit[9];
      int totcredit;


    void readmarks()
    {
        for(int i=0;i<9;i++)
        {
           cout<<" Mark and credit  of "<<i+1<<"  subject :  ";
           cin>>mark[i];
           tm[i]=mark[i];
          // cout<<" Credit of "<<i+1<<" subject   ";
           cin>>credit[i];
        }

    }
    void calculate()
    {
        
        tot=0;
        for(int i=0;i<9;i++)
        {
            tot=tot+mark[i];
        }
        avg=tot/9;
        totcredit=0;
        for(int i=0;i<9;i++)
        {
        mark[i]=mark[i]/10;
        totcredit=totcredit+credit[i];
        }
        for(int i=0;i<9;i++)
        {
        credit[i]=credit[i]*mark[i];
        }
   }
        void print()
        {

            cout<<"\n Marks are    ";
        for(int i=0;i<9;i++)
        {
            cout<<tm[i]<<" \t";
        }
        cout<<"\n Total is     "<<tot;
        cout<<"\n Average is    "<<avg;
        }
        };
        class grade :public markdetails
        {
            float cgpa;
            float gpa[20];
        public:
            void calculatecgpa()
            {
                cgpa=0;
        for(int i=0;i<9;i++)
        {
            gpa[i]=credit[i];
              cgpa=cgpa+gpa[i];
        }
    cgpa=cgpa/totcredit;
            }
        void printmarks()
            {

                cout<<"\n The GPA of  Subjects are   ";
                for(int i=0;i<9;i++)
        {
            cout<<gpa[i]<<"\t";
        }
        cout<<"\n The cgpa is    "<<cgpa;
            }
        };

        int main()
        {

            int n;
            cout<<"\n Enter  number of students    ";
            cin>>n;
            grade g[20];
        for(int i=0;i<n;i++)
        {
            g[i].readdetails();
            g[i].readmarks();
            g[i].calculate();
            g[i].calculatecgpa();
        }
        cout<<"\n\t\t Student Mark Details \n";
        for(int i=0;i<n;i++)
        {
            cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            g[i].printdetails();
            g[i].print();
            g[i].printmarks();
            cout<<"\n***********************************************************************\n";
        }
        return 0;
        }


