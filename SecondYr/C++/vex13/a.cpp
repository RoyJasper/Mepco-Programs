#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;
int main()
{
float f=4.20,f1=4.30;
int k;
cout<<"\n"<<typeid(k).name();
cout<<"\n"<<typeid(f).name();
if(typeid(k)==typeid(f))
cout<<"\n Both are same";
else
cout<<"\n They are not Same";
f1=float(k);
cout<<"\n"<<typeid(f1).name();
cout<<"\n"<<typeid(f).name();
if(typeid(f1)==typeid(f))
cout<<"\n Both are same";
else
cout<<"\n They are not Same";
}

