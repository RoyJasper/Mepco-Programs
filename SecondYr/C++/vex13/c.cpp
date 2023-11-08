#include<iostream>
#include<string>
using namespace std;
class vehicle
{
public:
virtual void mileage() const =0;
};
void vehicle :: mileage() const
{
cout<<"\n Main Class Vehicle is called ";
}
class two :public vehicle
{
public:
void mileage () const
{
vehicle :: mileage();
}
};
class four :public vehicle
{
public:
void mileage () const
{
vehicle :: mileage();
}
};
class bicycle :public two
{
public:
int d,f;
void mileage () const
{
float m;
two :: mileage();
m=d/f;
cout<<"\n Mileage given by Bicycle is.. "<<m;
}
};
class scooter :public two
{
public:
int d,f;
void mileage () const
{
float m;
two :: mileage();
m=d/f;
cout<<"\n Mileage given by Scooter is..  "<<m;
}};
class petrol :public four
{
public:
int d,f;
void mileage () const
{
float m;
four :: mileage();
m=d/f;
cout<<"\n Mileage given by Petrol Vehicle is..  "<<m;
}};
class diesel :public four
{
public:
int d,f;
void mileage () const
{
float m;
four :: mileage();
m=d/f;
cout<<"\n Mileage given by Diesel Vehicle is..  "<<m;
}
};

int main()
{
bicycle bi;
cout<<"\n^^^^^^^^^^^^^^^^^^^^^FOR BICYCLE^^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n Enter the Distance traveled  (km) : ";
cin>>bi.d;
cout<<"\n Enter the Amount of Fuel consumed (lt) : ";
cin>>bi.f;
vehicle *b = & bi;
b->mileage();

scooter oo;
cout<<"\n^^^^^^^^^^^^^^^^^^^^^FOR SCOOTER^^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n Enter the Distance traveled  (km) : ";
cin>>oo.d;
cout<<"\n Enter the Amount of Fuel consumed (lt) : ";
cin>>oo.f;
vehicle *s = & oo;
s->mileage();

petrol pe;
cout<<"\n^^^^^^^^^^^^^^^^^^^^^FOR PETROL VEHICLE^^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n Enter the Distance traveled  (km) : ";
cin>>pe.d;
cout<<"\n Enter the Amount of Fuel consumed (lt) : ";
cin>>pe.f;
vehicle *p = & pe;
p->mileage();

diesel di;
cout<<"\n^^^^^^^^^^^^^^^^^^^^^FOR DIESEL VEHICLE^^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n Enter the Distance traveled  (km) : ";
cin>>di.d;
cout<<"\n Enter the Amount of Fuel consumed (lt) : ";
cin>>di.f;
vehicle *df = & di;
df->mileage();

return 0;
}
