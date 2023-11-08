#include<iostream>
using namespace std;
const float pi=3.14;
int volume(int);
float volume(int,int);
float volume(float,float);
float volume(float);
int main()
{
 float cy,co,sp,r1,h1,a;
 int c,cu,r,h;
 cout<<"\nEnter side length for cube";
 cin>>c;
 cu=volume(c);
 cout<<"\nVolume of cube is"<<cu;
 cout<<"\nEnter radius and height of cylinder";
 cin>>r>>h;
 cy=volume(r,h);
 cout<<"\nVolume of cylinder is"<<cy;
 cout<<"\nEnter radius and height of cone";
 cin>>r1>>h1;
 co=volume(r1,h1);
 cout<<"\nVolume of Cone is"<<co;
 cout<<"\nEnter radius of sphere";
 cin>>a;
 sp=volume(a);
 cout<<"Volume of Sphere is"<<sp;
 return 0;
}
int volume(int a)
{
 return (a*a*a);
}
float volume(int r,int h)
{
 return (pi*r*r*h);
}
float volume(float r,float h)
{
 return (pi*r*r*h/3);
}
float volume(float a)
{
 return (4*pi*a*a*a/3);
}

