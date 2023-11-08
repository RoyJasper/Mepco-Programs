#include<iostream>
#include<string>
using namespace std;
class vol
{
 public:
 virtual void volume()
 {
  cout<<"\n THUS THE VOLUME FUNCTION IS CALLED";
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
  cout<<"\n THE VOLUME OF CUBE OF SIZE " << f << " IS : "<< a;
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
   cout<<"\n THE VOLUME OF CYLINDER OF SIZE " << r << "AND" << h << " IS : "<< a;
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
   cout<<"\n THE VOLUME OF SPHERE OF SIZE " << rd << " IS : "<< a;
 }
};
int main()
{
 vol *v,v1;
 cube c;
 cylinder y;;
 sphere s;
 v1.volume();
 cout<<"\nENTER THE radius OF THE CUBE";
 cin>>c.f;
 v=&c;
 v->volume();
 cout<<"\nENTER THE radius AND height OF THE CYLINDER";
 cin>>y.r>>y.h;
 v=&y;
 v->volume();
 cout<<"\nENTER THE radius OF THE SPHERE";
 cin>>s.rd;
 v=&s;
 v->volume();
}





