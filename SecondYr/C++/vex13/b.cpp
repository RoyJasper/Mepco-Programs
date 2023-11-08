#include<iostream>
#include<string>
using namespace std;
class vol
{
public:
virtual void volume()
{
cout<<"\n Volume Function is called \n";
}
};
class cube : public vol
{
public:
int f;
void volume()
{
float a;
a=f*f*f;
cout<<"\n Volume of cube of size " << f << " is : "<< a;
}
};
class cylinder : public vol
{
public:
int r,h;
void volume()
{
float a;
a=3.14*r*r*h;
cout<<"\n Volume of Cylinder of radius " << r << "and" << h << " is : "<< a;
}
};
class sphere : public vol
{
public:
int rd;
void volume()
{
float a;
a=4*0.33*3.14*rd*rd*rd;
cout<<"\n Volume of sphere of size " << rd << " IS : "<< a;
}
};
int main()
{
vol *v,v1;
cube c;
cylinder y;;
sphere s;
v1.volume();
cout<<"\n Enter side of cube ";
cin>>c.f;
v=&c;
v->volume();
cout<<"\n Enter radius and height of cylinder ";
cin>>y.r>>y.h;
v=&y;
v->volume();
cout<<"\n Enter Radius of sphere ";
cin>>s.rd;
v=&s;
v->volume();
}





