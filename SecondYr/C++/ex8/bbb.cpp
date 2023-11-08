#include<iostream>
#include<string>
using namespace std;
class farenheit;
class celcius
{
double cel;
public:
celcius()
{
cel=0;
}
celcius(double ab)
{
  cel=ab;
}
/*celcius(farenheit &fa)
  {
  double cd=fa.getfaren();
  cel=(5/9)*(cd-32);
  }*/
double getcel()
    {
  return cel;
    }
void show()
  {

  cout<<"\n CELCIUS IS ::"<<cel<<" degree\n";
  cout<<"\n***********************************";

  }
};
class farenheit
{
double faren;
public:
farenheit()
{faren=0;}

farenheit(double ef)
  {
  faren=ef;
  }
farenheit(celcius ce)
  {
  double gh=ce.getcel();
  faren=((9*gh)/5)+32;
  }
operator celcius()
{
  double ff=faren;
 // cout<<"\n"<<ff;
  cout<<"\n\n";
  double cc;
  cc=5*(ff-32)/9;
//  cout<<"\n"<<cc<<"check";
  return celcius(cc);
}
double getfaren()
  {
  return faren;
  }
void show()
  {
  cout<<"\n***********************************";
  cout<<"\n\n FARENHEIT IS:: "<<faren<<" faren";
  }
};
int main()
{
double x,y;
cout<<"\n enter the celcius :";
cin>>x;
cout<<"\n enter the farenheit   :";
cin>>y;
celcius c(x);
farenheit f(y);
farenheit f1;
celcius c2;
f1=c;
f1.show();
c2=f;
c2.show();
return 0;
}

