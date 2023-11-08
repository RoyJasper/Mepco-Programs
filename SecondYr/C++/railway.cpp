#include<iostream>
#include<string>
using namespace std;
class time
{

    int h1,m1,s1,h2,m2,s2;
    string a;
    public:
        time(int th1=0,int tm1=0,int ts1=0,int th2=0,int tm2=0,int ts2=0,string ta="  ")
        {
            h1=th1;
            m1=tm1;
            s1=ts1;
            h2=th2;
            m2=tm2;
            s2=ts2;
            a=ta;
        }
};
main()
{
    int h1,m1,s1,h2,m2,s2;
    string a;
    cout<<"\nEnter standard time hr , min , sec , am/pm ";
    cin>>h1;
    cin>>m1;
    cin>>s1;
    cin>>a;
    if(a=="pm")
    {
        h1+=12;
    }
    cout<<"\n Railway time is "<<h1<<":"<<m1<<":"<<s1;
    cout<<"\nEnter railway time hr , min , sec";
    cin>>h2;
    cin>>m2;
    cin>>s2;
    if(h2>=12)
    {
        h2-=12;
        a="pm";
    }
    cout<<"\n Standard time is "<<h2<<":"<<m2<<":"<<s2<<" "<<a;
}
